EESchema Schematic File Version 2  date Sat 16 Jun 2012 11:54:35 AM MSK
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
LIBS:ncp3063
LIBS:sdc
LIBS:stm
LIBS:usb
LIBS:mc34152
LIBS:valve-hm-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 6 7
Title ""
Date "16 jun 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 10800 1800 2    60   Input ~ 0
out2
Text HLabel 8300 1800 2    60   Input ~ 0
out1
NoConn ~ 5100 3300
NoConn ~ 5100 3150
$Comp
L GND #PWR059
U 1 1 4FDB2F05
P 5800 4900
AR Path="/4FDB33F6/4FDB2F05" Ref="#PWR059"  Part="1" 
AR Path="/4FDB2BC5/4FDB2F05" Ref="#PWR062"  Part="1" 
F 0 "#PWR062" H 5800 4900 30  0001 C CNN
F 1 "GND" H 5800 4830 30  0001 C CNN
	1    5800 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4400 5800 4900
Connection ~ 7400 1800
Wire Wire Line
	7400 1800 8300 1800
Wire Wire Line
	7400 1900 7400 1700
Wire Wire Line
	6400 2100 6200 2100
Wire Wire Line
	6550 4000 7100 4000
Wire Wire Line
	5100 4000 4500 4000
Wire Wire Line
	5100 3550 4500 3550
Wire Wire Line
	6550 3550 7100 3550
Wire Wire Line
	7100 2100 6900 2100
Wire Wire Line
	7400 2300 7400 2550
Wire Wire Line
	7400 1300 7400 950 
Wire Wire Line
	5800 2750 5800 2250
Wire Wire Line
	9900 1300 9900 950 
Wire Wire Line
	9900 2300 9900 2550
Wire Wire Line
	9600 2100 9400 2100
Wire Wire Line
	8900 2100 8700 2100
Wire Wire Line
	9900 1900 9900 1700
Wire Wire Line
	9900 1800 10800 1800
Connection ~ 9900 1800
Text Label 6900 4000 0    60   ~ 0
outB
Text Label 6900 3550 0    60   ~ 0
outA
$Comp
L R R37
U 1 1 4FDB2ED0
P 9150 2100
AR Path="/4FDB33F6/4FDB2ED0" Ref="R37"  Part="1" 
AR Path="/4FDB2BC5/4FDB2ED0" Ref="R39"  Part="1" 
F 0 "R39" V 9230 2100 50  0000 C CNN
F 1 "10" V 9150 2100 50  0000 C CNN
	1    9150 2100
	0    -1   -1   0   
$EndComp
$Comp
L MOSFET_N Q5
U 1 1 4FDB2ECF
P 9800 2100
AR Path="/4FDB33F6/4FDB2ECF" Ref="Q5"  Part="1" 
AR Path="/4FDB2BC5/4FDB2ECF" Ref="Q7"  Part="1" 
F 0 "Q7" H 9810 2270 60  0000 R CNN
F 1 "MOSFET_N" H 9810 1950 60  0000 R CNN
	1    9800 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR060
U 1 1 4FDB2ECE
P 9900 2550
AR Path="/4FDB33F6/4FDB2ECE" Ref="#PWR060"  Part="1" 
AR Path="/4FDB2BC5/4FDB2ECE" Ref="#PWR063"  Part="1" 
F 0 "#PWR063" H 9900 2550 30  0001 C CNN
F 1 "GND" H 9900 2480 30  0001 C CNN
	1    9900 2550
	1    0    0    -1  
$EndComp
$Comp
L DIODE D4
U 1 1 4FDB2ECD
P 9900 1500
AR Path="/4FDB33F6/4FDB2ECD" Ref="D4"  Part="1" 
AR Path="/4FDB2BC5/4FDB2ECD" Ref="D6"  Part="1" 
F 0 "D6" H 9900 1600 40  0000 C CNN
F 1 "1N4148" H 9900 1400 40  0000 C CNN
	1    9900 1500
	0    -1   -1   0   
$EndComp
Text GLabel 9900 950  1    60   Input ~ 0
24V
Text Label 8700 2100 0    60   ~ 0
outB
Text GLabel 5800 2250 1    60   Input ~ 0
10V
Text HLabel 4500 4000 0    60   Input ~ 0
in2
Text HLabel 4500 3550 0    60   Input ~ 0
in1
Text Label 6200 2100 0    60   ~ 0
outA
Text GLabel 7400 950  1    60   Input ~ 0
24V
$Comp
L DIODE D3
U 1 1 4FDB2DC3
P 7400 1500
AR Path="/4FDB33F6/4FDB2DC3" Ref="D3"  Part="1" 
AR Path="/4FDB2BC5/4FDB2DC3" Ref="D5"  Part="1" 
F 0 "D5" H 7400 1600 40  0000 C CNN
F 1 "1N4148" H 7400 1400 40  0000 C CNN
	1    7400 1500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR061
U 1 1 4FDB2D3E
P 7400 2550
AR Path="/4FDB33F6/4FDB2D3E" Ref="#PWR061"  Part="1" 
AR Path="/4FDB2BC5/4FDB2D3E" Ref="#PWR064"  Part="1" 
F 0 "#PWR064" H 7400 2550 30  0001 C CNN
F 1 "GND" H 7400 2480 30  0001 C CNN
	1    7400 2550
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q4
U 1 1 4FDB2C4B
P 7300 2100
AR Path="/4FDB33F6/4FDB2C4B" Ref="Q4"  Part="1" 
AR Path="/4FDB2BC5/4FDB2C4B" Ref="Q6"  Part="1" 
F 0 "Q6" H 7310 2270 60  0000 R CNN
F 1 "MOSFET_N" H 7310 1950 60  0000 R CNN
	1    7300 2100
	1    0    0    -1  
$EndComp
$Comp
L R R36
U 1 1 4FDB2C18
P 6650 2100
AR Path="/4FDB33F6/4FDB2C18" Ref="R36"  Part="1" 
AR Path="/4FDB2BC5/4FDB2C18" Ref="R38"  Part="1" 
F 0 "R38" V 6730 2100 50  0000 C CNN
F 1 "10" V 6650 2100 50  0000 C CNN
	1    6650 2100
	0    -1   -1   0   
$EndComp
$Comp
L MC34152 U4
U 1 1 4FDB2BFB
P 5800 3750
AR Path="/4FDB33F6/4FDB2BFB" Ref="U4"  Part="1" 
AR Path="/4FDB2BC5/4FDB2BFB" Ref="U5"  Part="1" 
F 0 "U5" H 5800 4100 60  0000 C CNN
F 1 "MC34152" H 5800 3750 60  0000 C CNN
	1    5800 3750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
