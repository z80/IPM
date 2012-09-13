EESchema Schematic File Version 2  date Wed 05 Sep 2012 02:15:31 PM MSK
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
LIBS:usb
LIBS:my_comps
LIBS:con-usb
LIBS:cable-usb-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "5 sep 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 5850 4050 0    60   ~ 0
d+
Text Label 5850 3850 0    60   ~ 0
d-
Wire Wire Line
	6250 4050 5800 4050
Connection ~ 6000 4650
Wire Wire Line
	6000 4850 6000 4450
Wire Wire Line
	5200 4300 5200 4100
Wire Wire Line
	5200 4100 4950 4100
Wire Wire Line
	4950 4000 5450 4000
Wire Wire Line
	4950 3900 5450 3900
Wire Wire Line
	4950 3800 5200 3800
Wire Wire Line
	5200 3800 5200 3600
Wire Wire Line
	6250 3650 6000 3650
Wire Wire Line
	6000 3650 6000 3450
Wire Wire Line
	6000 4450 6250 4450
Wire Wire Line
	6000 4650 6250 4650
Wire Wire Line
	6250 3850 5800 3850
$Comp
L GND #PWR4
U 1 1 503B6B7B
P 6000 4850
F 0 "#PWR4" H 6000 4850 30  0001 C CNN
F 1 "GND" H 6000 4780 30  0001 C CNN
	1    6000 4850
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR3
U 1 1 503B6B56
P 6000 3450
F 0 "#PWR3" H 6000 3550 30  0001 C CNN
F 1 "VCC" H 6000 3550 30  0000 C CNN
	1    6000 3450
	1    0    0    -1  
$EndComp
Text Label 5300 4000 0    60   ~ 0
d+
Text Label 5300 3900 0    60   ~ 0
d-
$Comp
L VCC #PWR1
U 1 1 503B6B3F
P 5200 3600
F 0 "#PWR1" H 5200 3700 30  0001 C CNN
F 1 "VCC" H 5200 3700 30  0000 C CNN
	1    5200 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 503B6B39
P 5200 4300
F 0 "#PWR2" H 5200 4300 30  0001 C CNN
F 1 "GND" H 5200 4230 30  0001 C CNN
	1    5200 4300
	1    0    0    -1  
$EndComp
$Comp
L USB_2_VALID J1
U 1 1 503B6AF6
P 4750 3950
F 0 "J1" H 5050 4200 60  0000 C CNN
F 1 "USB_2_VALID" H 5050 3650 60  0001 C CNN
F 4 "VCC" H 4425 4100 50  0001 C CNN "VCC"
F 5 "D-" H 4450 4000 50  0001 C CNN "Data-"
F 6 "D+" H 4450 3900 50  0001 C CNN "Data+"
F 7 "GND" H 4425 3800 50  0001 C CNN "Ground"
	1    4750 3950
	-1   0    0    -1  
$EndComp
$Comp
L MINI-USB-B U1
U 1 1 503B6A0B
P 7150 4150
F 0 "U1" H 7150 3750 60  0000 C CNN
F 1 "MINI-USB-B" H 7150 4550 60  0000 C CNN
	1    7150 4150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
