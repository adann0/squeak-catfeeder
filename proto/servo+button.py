#!/usr/bin/env python3

import time
import pigpio

pi = pigpio.pi() # connect to the interface
pi.set_mode(25, pigpio.INPUT)

try : # try/except ctrl+c
    while True:
        if (pi.read(25) != 1) :
            print("PUSH")
            pi.set_servo_pulsewidth(15, 700)
            time.sleep(0.5)
            pi.set_servo_pulsewidth(15,0)
        else :
            print("...")
except :
    print("Quit.")
    pi.stop(
