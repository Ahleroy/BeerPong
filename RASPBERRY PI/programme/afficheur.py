#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Une LED branchee a la pin 25 clignote

import RPi.GPIO as GPIO  # bibliotheque pour utiliser les GPIO
import time              # bibliotheque pour gestion du temps

GPIO.setwarnings(False)

global Data
global Latch
global Clock

global ClockC
global Reset

global timer

Data=5
Latch=3
Clock=7

ClockC=11
Reset=13

timer=0.0000001

GPIO.setmode(GPIO.BOARD)   # mode de numerotation des pins
GPIO.setup(Data,GPIO.OUT)  # la pin 3 reglee en sortie (output)
GPIO.setup(Latch,GPIO.OUT)
GPIO.setup(Clock,GPIO.OUT)
GPIO.setup(ClockC,GPIO.OUT)
GPIO.setup(Reset,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)

def reset():

        GPIO.output(Data,GPIO.LOW)
        GPIO.output(Latch,GPIO.HIGH)
        GPIO.output(ClockC,GPIO.LOW)
        GPIO.output(Clock,GPIO.LOW)

        while (GPIO.input(Reset) ==0):
                GPIO.output(ClockC,GPIO.HIGH)
                time.sleep(timer)
                GPIO.output(ClockC,GPIO.LOW)
                time.sleep(timer)

        GPIO.output(Data,GPIO.LOW)
        GPIO.output(Clock,GPIO.LOW)
        GPIO.output(Latch,GPIO.LOW)

        return;

def affiche(n, matrix):
        for k in range(n):
            for j in range(12):

                    GPIO.output(ClockC,GPIO.LOW)
                    GPIO.output(Latch,GPIO.HIGH)
                    GPIO.output(Data,GPIO.LOW)
                    GPIO.output(Clock,GPIO.LOW)

                    for i in range(32):
                            if matrix[j-11][31-((32+i) %32)]==1:
                                    GPIO.output(Data,GPIO.HIGH)
                            else:
                                    GPIO.output(Data,GPIO.LOW)

                            GPIO.output(Clock,GPIO.HIGH)
                            GPIO.output(Clock,GPIO.LOW)

                    GPIO.output(Latch,GPIO.LOW)
                    time.sleep(timer)
                    GPIO.output(ClockC,GPIO.HIGH)
        return;


def kill():

        GPIO.cleanup()

        return;
