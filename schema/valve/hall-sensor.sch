EESchema Schematic File Version 2  date Tue 03 Apr 2012 08:56:06 PM MSK
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:my_comps
LIBS:valve-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 2 45
Title ""
Date "3 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR59
U 1 1 4F79F4AC
P 5100 4650
F 0 "#PWR59" H 5100 4650 30  0001 C CNN
F 1 "GND" H 5100 4580 30  0001 C CNN
	1    5100 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4400 5100 4650
Wire Wire Line
	4900 3700 5350 3700
Wire Wire Line
	3900 3700 4400 3700
Wire Wire Line
	5100 3900 5100 3700
Connection ~ 5100 3700
$Comp
L R R80
U 1 1 4F79F48F
P 5100 4150
F 0 "R80" V 5180 4150 50  0000 C CNN
F 1 "10k" V 5100 4150 50  0000 C CNN
	1    5100 4150
	1    0    0    -1  
$EndComp
Text HLabel 5350 3700 2    60   Input ~ 0
out
Text HLabel 3900 3700 0    60   Input ~ 0
in
$Comp
L R R79
U 1 1 4F79F464
P 4650 3700
F 0 "R79" V 4730 3700 50  0000 C CNN
F 1 "100" V 4650 3700 50  0000 C CNN
	1    4650 3700
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
