EESchema Schematic File Version 2  date Tue 03 Apr 2012 12:20:51 AM MSK
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
$Descr A3 16535 11700
encoding utf-8
Sheet 45 45
Title ""
Date "2 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CRYSTAL X?
U 1 1 4F7A0A14
P 4900 4650
F 0 "X?" H 4900 4800 60  0000 C CNN
F 1 "CRYSTAL" H 4900 4500 60  0000 C CNN
	1    4900 4650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 4F7A09EC
P 4350 4350
F 0 "#PWR?" H 4350 4350 30  0001 C CNN
F 1 "GND" H 4350 4280 30  0001 C CNN
	1    4350 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 4100 4350 4350
Connection ~ 4350 3500
Wire Wire Line
	4350 3700 4350 3300
Wire Wire Line
	7650 1500 7650 1000
Connection ~ 8250 10800
Wire Wire Line
	8250 10400 8250 10800
Wire Wire Line
	8850 10400 8850 10800
Wire Wire Line
	8850 10800 6450 10800
Wire Wire Line
	6450 10800 6450 10400
Connection ~ 7650 1200
Wire Wire Line
	8850 1500 8850 1200
Wire Wire Line
	8850 1200 6450 1200
Wire Wire Line
	6450 1200 6450 1500
Wire Wire Line
	8250 1500 8250 1200
Connection ~ 8250 1200
Wire Wire Line
	7150 1500 7150 1200
Connection ~ 7150 1200
Connection ~ 7650 10800
Wire Wire Line
	7650 11000 7650 10400
Wire Wire Line
	4350 3500 5950 3500
Wire Wire Line
	4350 2800 4350 2600
$Comp
L VCC #PWR?
U 1 1 4F7A09E2
P 4350 2600
F 0 "#PWR?" H 4350 2700 30  0001 C CNN
F 1 "VCC" H 4350 2700 30  0000 C CNN
	1    4350 2600
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F7A09C4
P 4350 3900
F 0 "C?" H 4400 4000 50  0000 L CNN
F 1 "C" H 4400 3800 50  0000 L CNN
	1    4350 3900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4F7A09A9
P 4350 3050
F 0 "R?" V 4430 3050 50  0000 C CNN
F 1 "R" V 4350 3050 50  0000 C CNN
	1    4350 3050
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 4F7A098C
P 7650 1000
F 0 "#PWR?" H 7650 1100 30  0001 C CNN
F 1 "VCC" H 7650 1100 30  0000 C CNN
	1    7650 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4F7A0978
P 7650 11000
F 0 "#PWR?" H 7650 11000 30  0001 C CNN
F 1 "GND" H 7650 10930 30  0001 C CNN
	1    7650 11000
	1    0    0    -1  
$EndComp
$Comp
L STM32F102C8T6 stm32?
U 1 1 4F7A091B
P 7650 5400
F 0 "stm32?" H 7650 5200 60  0000 C CNN
F 1 "STM32F102C8T6" H 7650 5600 60  0000 C CNN
	1    7650 5400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
