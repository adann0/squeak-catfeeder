/*
$ gcc -o servo servo.c -lpigpio -lrt -lpthread
$ sudo ./servo <pin> <seconds>
*/

#include <stdio.h>
#include <pigpio.h>
#include <stdlib.h>

void usage(char * msg) { fprintf(stderr, "%s\n", msg) ; exit(1) ; }

int rotate(int pin, int sleep) {
   
   if (gpioInitialise() < 0) {
      usage("pigpio initialisation failed") ;
      return 1 ;
   }
   
   gpioSetMode(pin, 1) ;
   gpioPWM(pin, 192) ;
   time_sleep(sleep) ;
   gpioTerminate() ;
   
   return 0 ;
}

int main(int argc, char *argv[]) {

   if (argc < 3) {
       usage("USAGE: ./servo <pin> <seconds>") ;
   }

   char *ptr;
   
   int pin = strtol(argv[1], &ptr, 10);
   int seconds = strtol(argv[2], &ptr, 10);
   
   rotate(pin, seconds);
   
   return 0;
}
