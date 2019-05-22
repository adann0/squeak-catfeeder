/*
$ gcc -o pwm pwm.c -lpigpio -lrt -lpthread
$ sudo ./pwm <pin> <seconds>
*/

#include <stdio.h>
#include <pigpio.h>

void usage(char * msg) { fprintf(stderr, "%s\n", msg) ; exit(1) ; }

int rotate(int pin, int sleep) {
   gpioSetMode(pin, PI_OUTPUT) ;
   gpioPWM(pin, 192) ;
   time_sleep(sleep) ;
   gpioTerminate() ;
}

int main(int argc, char *argv[]) {

   if (argc < 3) {
       usage("USAGE: ./pwm <pin> <seconds>") ;
   }

   if (gpioInitialise() < 0) {
      usage("pigpio initialisation failed") ;
   }
   
   rotate(argv[1], argv[2]);
   
   return 0;
}
