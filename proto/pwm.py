#!/usr/bin/env python3

def usage(msg) : sys.exit(msg)

def rotate(pin, sleep) :
  gpioSetMode(pin, 1)
  gpioPWN(pin, 192)
  time.sleep(sleep)
  gpioTerminate()

if __name__ == "__main__" :
   if (sys.argv < 3) : usage("USAGE: ./pwm <pin> <seconds>")
   rotate(int(pin), int(seconds))
