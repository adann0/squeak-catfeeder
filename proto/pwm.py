#!/usr/bin/env python3

import sys
import time
import pigpio

def usage(msg) : sys.exit(msg)

def rotate(pin, sleep) :
  gpioSetMode(pin, 1)
  gpioPWN(pin, 192)
  time.sleep(sleep)
  gpioTerminate()

if __name__ == "__main__" :
   if (sys.argv < 3) : usage("USAGE: ./pwm <pin> <seconds>")
   rotate(int(sys.argv[1]), int(sys.argv[2]))
