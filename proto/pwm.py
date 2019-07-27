#!/usr/bin/env python3

import sys
import time
import pigpio

def usage(msg) : sys.exit(msg)

def rotate(pin, sleep) :
    pi = pigpio.pi() # Connect to local Pi.
    pi.set_mode(pin, pigpio.OUTPUT)
    pi.set_servo_pulsewidth(pin, 1500)
    time.sleep(sleep)
    pi.set_servo_pulsewidth(pin, 0)
    pi.stop()

if __name__ == "__main__" :
    if len(sys.argv) < 3 : usage("USAGE: ./pwm <pin> <seconds>")
    rotate(int(sys.argv[1]), int(sys.argv[2]))
