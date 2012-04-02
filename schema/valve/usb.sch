EESchema Schematic File Version 2  date Tue 03 Apr 2012 01:04:14 AM MSK
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
Sheet 4 45
Title ""
Date "2 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 5500 3150
Wire Wire Line
	5500 3150 5200 3150
Wire Wire Line
	8800 4000 8800 4300
Wire Wire Line
	8500 3200 9100 3200
Wire Wire Line
	8200 3000 8200 2800
Wire Wire Line
	8200 2800 7100 2800
Wire Wire Line
	6300 2000 6300 1400
Wire Wire Line
	6300 2800 6300 2500
Wire Wire Line
	6950 4200 7400 4200
Wire Wire Line
	5200 3650 5200 3750
Wire Wire Line
	5500 2850 5500 4000
Connection ~ 5700 4200
Wire Wire Line
	5700 4200 5700 3800
Wire Wire Line
	5400 4200 6450 4200
Wire Wire Line
	5500 4000 5400 4000
Wire Wire Line
	5400 4100 5850 4100
Wire Wire Line
	5400 4300 5500 4300
Wire Wire Line
	5500 4300 5500 4600
Wire Wire Line
	5200 3150 5200 3250
Wire Wire Line
	6350 4100 7400 4100
Wire Wire Line
	5700 3300 5700 3000
Wire Wire Line
	5700 2600 5700 1700
Wire Wire Line
	6600 2800 6000 2800
Connection ~ 6300 2800
Wire Wire Line
	8200 3400 8200 3800
Wire Wire Line
	8800 3500 8800 3200
Connection ~ 8800 3200
Wire Wire Line
	9600 3200 9900 3200
Text HLabel 9900 3200 2    60   Input ~ 0
en
$Comp
L GND #PWR62
U 1 1 4F79F38D
P 8800 4300
F 0 "#PWR62" H 8800 4300 30  0001 C CNN
F 1 "GND" H 8800 4230 30  0001 C CNN
	1    8800 4300
	1    0    0    -1  
$EndComp
$Comp
L R R85
U 1 1 4F79F383
P 8800 3750
F 0 "R85" V 8880 3750 50  0000 C CNN
F 1 "10k" V 8800 3750 50  0000 C CNN
	1    8800 3750
	1    0    0    -1  
$EndComp
$Comp
L R R83
U 1 1 4F79F376
P 9350 3200
F 0 "R83" V 9430 3200 50  0000 C CNN
F 1 "1k" V 9350 3200 50  0000 C CNN
	1    9350 3200
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR61
U 1 1 4F79F36D
P 8200 3800
F 0 "#PWR61" H 8200 3800 30  0001 C CNN
F 1 "GND" H 8200 3730 30  0001 C CNN
	1    8200 3800
	1    0    0    -1  
$EndComp
$Comp
L NPN Q29
U 1 1 4F79F34C
P 8300 3200
F 0 "Q29" H 8300 3050 50  0000 R CNN
F 1 "bc847" H 8300 3350 50  0000 R CNN
	1    8300 3200
	-1   0    0    -1  
$EndComp
$Comp
L R R82
U 1 1 4F79F31F
P 6850 2800
F 0 "R82" V 6930 2800 50  0000 C CNN
F 1 "1k" V 6850 2800 50  0000 C CNN
	1    6850 2800
	0    -1   -1   0   
$EndComp
Text Label 6300 1750 1    60   ~ 0
usb-vcc
Text Label 5700 2050 1    60   ~ 0
usb-vcc
$Comp
L R R81
U 1 1 4F79F29C
P 6300 2250
F 0 "R81" V 6380 2250 50  0000 C CNN
F 1 "10k" V 6300 2250 50  0000 C CNN
	1    6300 2250
	1    0    0    -1  
$EndComp
$Comp
L PNP Q28
U 1 1 4F79F27D
P 5800 2800
F 0 "Q28" H 5800 2650 60  0000 R CNN
F 1 "bc857" H 5800 2950 60  0000 R CNN
	1    5800 2800
	-1   0    0    1   
$EndComp
Text HLabel 7400 4200 2    60   Input ~ 0
d+
Text HLabel 7400 4100 2    60   Input ~ 0
d-
$Comp
L GND #PWR60
U 1 1 4F79EA74
P 5200 3750
F 0 "#PWR60" H 5200 3750 30  0001 C CNN
F 1 "GND" H 5200 3680 30  0001 C CNN
	1    5200 3750
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 4F79EA67
P 5200 3450
F 0 "C1" H 5250 3550 50  0000 L CNN
F 1 "4u7" H 5250 3350 50  0000 L CNN
	1    5200 3450
	1    0    0    -1  
$EndComp
Text Label 5500 3100 1    60   ~ 0
usb-vcc
$Comp
L GND #PWR63
U 1 1 4F79EA26
P 5500 4600
F 0 "#PWR63" H 5500 4600 30  0001 C CNN
F 1 "GND" H 5500 4530 30  0001 C CNN
	1    5500 4600
	1    0    0    -1  
$EndComp
$Comp
L R R84
U 1 1 4F79E9FF
P 5700 3550
F 0 "R84" V 5780 3550 50  0000 C CNN
F 1 "1k5" V 5700 3550 50  0000 C CNN
	1    5700 3550
	1    0    0    -1  
$EndComp
$Comp
L R R87
U 1 1 4F79E9AD
P 6700 4200
F 0 "R87" V 6780 4200 50  0000 C CNN
F 1 "22" V 6700 4200 50  0000 C CNN
	1    6700 4200
	0    -1   -1   0   
$EndComp
$Comp
L R R86
U 1 1 4F79E9A1
P 6100 4100
F 0 "R86" V 6180 4100 50  0000 C CNN
F 1 "22" V 6100 4100 50  0000 C CNN
	1    6100 4100
	0    -1   -1   0   
$EndComp
$Comp
L USB_2_VALID J1
U 1 1 4F79E985
P 5200 4150
F 0 "J1" H 5500 4400 60  0000 C CNN
F 1 "USB_2_VALID" H 5500 3850 60  0001 C CNN
F 4 "VCC" H 4875 4300 50  0001 C CNN "VCC"
F 5 "D-" H 4900 4200 50  0001 C CNN "Data-"
F 6 "D+" H 4900 4100 50  0001 C CNN "Data+"
F 7 "GND" H 4875 4000 50  0001 C CNN "Ground"
	1    5200 4150
	-1   0    0    -1  
$EndComp
$EndSCHEMATC