/*
$ gcc -o pwm pwm.c -lpigpio -lrt -lpthread
$ sudo ./pwm <pin> <seconds>
*/

#include <stdio.h>
#include <pigpio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   if (gpioInitialise() < 0)
      return 1 ;


   gpioSetMode(15, 1) ;
   gpioSetMode(25, 0) ;

   for(;;) {
     if (!(gpioRead(25))) {
	      puts("PUSH");
        gpioPWM(15, 40) ;
        time_sleep(0.6) ;
        gpioPWM(15, 0) ; }
     else
	      puts("...");
   }

   gpioTerminate() ;

   return 0;
}
