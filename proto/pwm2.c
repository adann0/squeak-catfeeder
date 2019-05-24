/*
$ gcc -o pwm pwm.c -lpigpio -lrt -lpthread
$ sudo ./pwm
*/

#include <pigpio.h>

int pwm(int pin, int sleep) {

   if (gpioInitialise() < 0) {
      return 1 ;
   }

   gpioSetMode(pin, 1) ;

   gpioPWM(pin, 192) ;

   time_sleep(sleep) ;

   gpioTerminate() ;

   return 0 ;
}

int main(int argc, char *argv[]) {
   pwm(17, 2);
   return 0;
}
