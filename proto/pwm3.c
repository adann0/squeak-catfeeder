/*
$ gcc -shared -o libpwm.so -fPIC pwm.c -lpigpio -lrt -lpthread
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
