EESchema Schematic File Version 2  date 09/08/2012 15:31:21
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
LIBS:valve-mb-cache
EELAYER 25  0
EELAYER END
$Descr A3 16535 11700
encoding utf-8
Sheet 1 1
Title ""
Date "9 aug 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_20 P21
U 1 1 50239E65
P 13450 3100
F 0 "P21" V 13400 3100 60  0000 C CNN
F 1 "CONN_20" V 13500 3100 60  0000 C CNN
	1    13450 3100
	1    0    0    -1  
$EndComp
Text Label 12800 4050 0    60   ~ 0
ioc20
Text Label 12800 3950 0    60   ~ 0
ioc19
Text Label 12800 3850 0    60   ~ 0
ioc18
Text Label 12800 3750 0    60   ~ 0
ioc17
Text Label 12800 3650 0    60   ~ 0
ioc16
Text Label 12800 3550 0    60   ~ 0
ioc15
Text Label 12800 3450 0    60   ~ 0
ioc14
Text Label 12800 3350 0    60   ~ 0
ioc13
Text Label 12800 3250 0    60   ~ 0
ioc12
Text Label 12800 3150 0    60   ~ 0
ioc11
Text Label 12800 3050 0    60   ~ 0
ioc10
Text Label 12800 2950 0    60   ~ 0
ioc9
Text Label 12800 2850 0    60   ~ 0
ioc8
Text Label 12800 2750 0    60   ~ 0
ioc7
Text Label 12800 2650 0    60   ~ 0
ioc6
Text Label 12800 2550 0    60   ~ 0
ioc5
Text Label 12800 2450 0    60   ~ 0
ioc4
Text Label 12800 2350 0    60   ~ 0
ioc3
Text Label 12800 2250 0    60   ~ 0
ioc2
Text Label 12800 2150 0    60   ~ 0
ioc1
Text Label 11450 2150 0    60   ~ 0
ioc1
Text Label 11450 2250 0    60   ~ 0
ioc2
Text Label 11450 2350 0    60   ~ 0
ioc3
Text Label 11450 2450 0    60   ~ 0
ioc4
Text Label 11450 2550 0    60   ~ 0
ioc5
Text Label 11450 2650 0    60   ~ 0
ioc6
Text Label 11450 2750 0    60   ~ 0
ioc7
Text Label 11450 2850 0    60   ~ 0
ioc8
Text Label 11450 2950 0    60   ~ 0
ioc9
Text Label 11450 3050 0    60   ~ 0
ioc10
Text Label 11450 3150 0    60   ~ 0
ioc11
Text Label 11450 3250 0    60   ~ 0
ioc12
Text Label 11450 3350 0    60   ~ 0
ioc13
Text Label 11450 3450 0    60   ~ 0
ioc14
Text Label 11450 3550 0    60   ~ 0
ioc15
Text Label 11450 3650 0    60   ~ 0
ioc16
Text Label 11450 3750 0    60   ~ 0
ioc17
Text Label 11450 3850 0    60   ~ 0
ioc18
Text Label 11450 3950 0    60   ~ 0
ioc19
Text Label 11450 4050 0    60   ~ 0
ioc20
$Comp
L CONN_20 P19
U 1 1 50239E64
P 12100 3100
F 0 "P19" V 12050 3100 60  0000 C CNN
F 1 "CONN_20" V 12150 3100 60  0000 C CNN
	1    12100 3100
	1    0    0    -1  
$EndComp
Text Notes 11650 1950 0    60   ~ 0
Third MCU power boards couple
$Comp
L VDD #PWR01
U 1 1 50239E63
P 11100 4800
F 0 "#PWR01" H 11100 4900 30  0001 C CNN
F 1 "VDD" H 11100 4910 30  0000 C CNN
	1    11100 4800
	1    0    0    -1  
$EndComp
Text GLabel 11500 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P20
U 1 1 50239E62
P 12100 4850
F 0 "P20" V 12050 4850 60  0000 C CNN
F 1 "CONN_6" V 12150 4850 60  0000 C CNN
	1    12100 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR02
U 1 1 50239E61
P 11550 5200
F 0 "#PWR02" H 11550 5200 30  0001 C CNN
F 1 "GND" H 11550 5130 30  0001 C CNN
	1    11550 5200
	-1   0    0    -1  
$EndComp
Text GLabel 11550 4500 1    60   Input ~ 0
24v
Text GLabel 12900 4500 1    60   Input ~ 0
24v
$Comp
L GND #PWR03
U 1 1 50239E60
P 12900 5200
F 0 "#PWR03" H 12900 5200 30  0001 C CNN
F 1 "GND" H 12900 5130 30  0001 C CNN
	1    12900 5200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P22
U 1 1 50239E5F
P 13450 4850
F 0 "P22" V 13400 4850 60  0000 C CNN
F 1 "CONN_6" V 13500 4850 60  0000 C CNN
	1    13450 4850
	1    0    0    1   
$EndComp
Text GLabel 12850 4800 0    60   Input ~ 0
10v
$Comp
L VDD #PWR04
U 1 1 50239E5E
P 12450 4800
F 0 "#PWR04" H 12450 4900 30  0001 C CNN
F 1 "VDD" H 12450 4910 30  0000 C CNN
	1    12450 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	13100 3950 12750 3950
Wire Wire Line
	13100 3750 12750 3750
Wire Wire Line
	13100 3550 12750 3550
Wire Wire Line
	13100 3350 12750 3350
Wire Wire Line
	13100 3150 12750 3150
Wire Wire Line
	13100 2950 12750 2950
Wire Wire Line
	13100 2750 12750 2750
Wire Wire Line
	13100 2550 12750 2550
Wire Wire Line
	13100 2350 12750 2350
Wire Wire Line
	13100 2150 12750 2150
Wire Wire Line
	13100 2250 12750 2250
Wire Wire Line
	13100 2450 12750 2450
Wire Wire Line
	13100 2650 12750 2650
Wire Wire Line
	13100 2850 12750 2850
Wire Wire Line
	13100 3050 12750 3050
Wire Wire Line
	13100 3250 12750 3250
Wire Wire Line
	13100 3450 12750 3450
Wire Wire Line
	13100 3650 12750 3650
Wire Wire Line
	13100 3850 12750 3850
Wire Wire Line
	13100 4050 12750 4050
Wire Wire Line
	11750 4050 11400 4050
Wire Wire Line
	11750 3850 11400 3850
Wire Wire Line
	11750 3650 11400 3650
Wire Wire Line
	11750 3450 11400 3450
Wire Wire Line
	11750 3250 11400 3250
Wire Wire Line
	11750 3050 11400 3050
Wire Wire Line
	11750 2850 11400 2850
Wire Wire Line
	11750 2650 11400 2650
Wire Wire Line
	11750 2450 11400 2450
Wire Wire Line
	11750 2250 11400 2250
Wire Wire Line
	11750 2150 11400 2150
Wire Wire Line
	11750 2350 11400 2350
Wire Wire Line
	11750 2550 11400 2550
Wire Wire Line
	11750 2750 11400 2750
Wire Wire Line
	11750 2950 11400 2950
Wire Wire Line
	11750 3150 11400 3150
Wire Wire Line
	11750 3350 11400 3350
Wire Wire Line
	11750 3550 11400 3550
Wire Wire Line
	11750 3750 11400 3750
Wire Wire Line
	11750 3950 11400 3950
Connection ~ 11550 5100
Wire Wire Line
	11750 5100 11550 5100
Wire Wire Line
	11100 4800 11100 4900
Wire Wire Line
	11100 4900 11750 4900
Wire Wire Line
	11750 4800 11500 4800
Wire Wire Line
	11750 4700 11550 4700
Wire Wire Line
	11750 5000 11550 5000
Wire Wire Line
	11550 5000 11550 5200
Wire Wire Line
	11550 4700 11550 4500
Wire Wire Line
	11750 4600 11550 4600
Connection ~ 11550 4600
Connection ~ 12900 4600
Wire Wire Line
	13100 4600 12900 4600
Wire Wire Line
	12900 4500 12900 4700
Wire Wire Line
	12900 5200 12900 5000
Wire Wire Line
	12900 5000 13100 5000
Wire Wire Line
	12900 4700 13100 4700
Wire Wire Line
	13100 4800 12850 4800
Wire Wire Line
	13100 4900 12450 4900
Wire Wire Line
	12450 4900 12450 4800
Wire Wire Line
	13100 5100 12900 5100
Connection ~ 12900 5100
$Comp
L TST P17
U 1 1 4FE1CC6B
P 4750 6500
F 0 "P17" H 4750 6800 40  0000 C CNN
F 1 "TST" H 4750 6750 30  0000 C CNN
	1    4750 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 6500 4750 6700
$Comp
L GND #PWR05
U 1 1 4FE1CC6A
P 4750 6700
F 0 "#PWR05" H 4750 6700 30  0001 C CNN
F 1 "GND" H 4750 6630 30  0001 C CNN
	1    4750 6700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 4FE1CC69
P 5050 6700
F 0 "#PWR06" H 5050 6700 30  0001 C CNN
F 1 "GND" H 5050 6630 30  0001 C CNN
	1    5050 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 6500 5050 6700
$Comp
L TST P18
U 1 1 4FE1CC68
P 5050 6500
F 0 "P18" H 5050 6800 40  0000 C CNN
F 1 "TST" H 5050 6750 30  0000 C CNN
	1    5050 6500
	1    0    0    -1  
$EndComp
$Comp
L TST P16
U 1 1 4FE1CC63
P 4450 6500
F 0 "P16" H 4450 6800 40  0000 C CNN
F 1 "TST" H 4450 6750 30  0000 C CNN
	1    4450 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 6500 4450 6700
$Comp
L GND #PWR07
U 1 1 4FE1CC62
P 4450 6700
F 0 "#PWR07" H 4450 6700 30  0001 C CNN
F 1 "GND" H 4450 6630 30  0001 C CNN
	1    4450 6700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 4FE1CC5C
P 4150 6700
F 0 "#PWR08" H 4150 6700 30  0001 C CNN
F 1 "GND" H 4150 6630 30  0001 C CNN
	1    4150 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 6500 4150 6700
Connection ~ 1800 7750
Wire Wire Line
	2000 7750 1800 7750
Connection ~ 9950 5100
Wire Wire Line
	10150 5100 9950 5100
Wire Wire Line
	9500 4800 9500 4900
Wire Wire Line
	9500 4900 10150 4900
Wire Wire Line
	10150 4800 9900 4800
Wire Wire Line
	10150 4700 9950 4700
Wire Wire Line
	10150 5000 9950 5000
Wire Wire Line
	9950 5000 9950 5200
Wire Wire Line
	9950 4700 9950 4500
Wire Wire Line
	10150 4600 9950 4600
Connection ~ 9950 4600
Connection ~ 8600 4600
Wire Wire Line
	8800 4600 8600 4600
Wire Wire Line
	8600 4500 8600 4700
Wire Wire Line
	8600 5200 8600 5000
Wire Wire Line
	8600 5000 8800 5000
Wire Wire Line
	8600 4700 8800 4700
Wire Wire Line
	8800 4800 8550 4800
Wire Wire Line
	8800 4900 8150 4900
Wire Wire Line
	8150 4900 8150 4800
Wire Wire Line
	8800 5100 8600 5100
Connection ~ 8600 5100
Connection ~ 7050 5100
Wire Wire Line
	7250 5100 7050 5100
Wire Wire Line
	6600 4800 6600 4900
Wire Wire Line
	6600 4900 7250 4900
Wire Wire Line
	7250 4800 7000 4800
Wire Wire Line
	7250 4700 7050 4700
Wire Wire Line
	7250 5000 7050 5000
Wire Wire Line
	7050 5000 7050 5200
Wire Wire Line
	7050 4700 7050 4500
Wire Wire Line
	7250 4600 7050 4600
Connection ~ 7050 4600
Connection ~ 5800 4600
Wire Wire Line
	6000 4600 5800 4600
Wire Wire Line
	5800 4500 5800 4700
Wire Wire Line
	5800 5200 5800 5000
Wire Wire Line
	5800 5000 6000 5000
Wire Wire Line
	5800 4700 6000 4700
Wire Wire Line
	6000 4800 5750 4800
Wire Wire Line
	6000 4900 5350 4900
Wire Wire Line
	5350 4900 5350 4800
Wire Wire Line
	6000 5100 5800 5100
Connection ~ 5800 5100
Connection ~ 4350 5000
Wire Wire Line
	4550 5000 4350 5000
Wire Wire Line
	3900 4700 3900 4800
Wire Wire Line
	3900 4800 4550 4800
Wire Wire Line
	4550 4700 4300 4700
Wire Wire Line
	4550 4600 4350 4600
Wire Wire Line
	4550 4900 4350 4900
Wire Wire Line
	4350 4900 4350 5100
Wire Wire Line
	4350 4600 4350 4400
Wire Wire Line
	4550 4500 4350 4500
Connection ~ 4350 4500
Connection ~ 2950 4500
Wire Wire Line
	3150 4500 2950 4500
Wire Wire Line
	2950 4400 2950 4600
Wire Wire Line
	2950 5100 2950 4900
Wire Wire Line
	2950 4900 3150 4900
Wire Wire Line
	2950 4600 3150 4600
Wire Wire Line
	3150 4700 2900 4700
Wire Wire Line
	3150 4800 2500 4800
Wire Wire Line
	2500 4800 2500 4700
Wire Wire Line
	3150 5000 2950 5000
Connection ~ 2950 5000
Connection ~ 1450 5100
Wire Wire Line
	1650 5100 1450 5100
Connection ~ 1800 7850
Wire Wire Line
	1800 7650 1800 7950
Wire Wire Line
	1800 7950 2000 7950
Wire Wire Line
	1800 8150 2000 8150
Wire Wire Line
	1800 7850 2000 7850
Wire Wire Line
	8800 3950 8450 3950
Wire Wire Line
	8800 3750 8450 3750
Wire Wire Line
	8800 3550 8450 3550
Wire Wire Line
	8800 3350 8450 3350
Wire Wire Line
	8800 3150 8450 3150
Wire Wire Line
	8800 2950 8450 2950
Wire Wire Line
	8800 2750 8450 2750
Wire Wire Line
	8800 2550 8450 2550
Wire Wire Line
	8800 2350 8450 2350
Wire Wire Line
	8800 2150 8450 2150
Wire Wire Line
	8800 2250 8450 2250
Wire Wire Line
	8800 2450 8450 2450
Wire Wire Line
	8800 2650 8450 2650
Wire Wire Line
	8800 2850 8450 2850
Wire Wire Line
	8800 3050 8450 3050
Wire Wire Line
	8800 3250 8450 3250
Wire Wire Line
	8800 3450 8450 3450
Wire Wire Line
	8800 3650 8450 3650
Wire Wire Line
	8800 3850 8450 3850
Wire Wire Line
	8800 4050 8450 4050
Wire Wire Line
	10150 4050 9800 4050
Wire Wire Line
	10150 3850 9800 3850
Wire Wire Line
	10150 3650 9800 3650
Wire Wire Line
	10150 3450 9800 3450
Wire Wire Line
	10150 3250 9800 3250
Wire Wire Line
	10150 3050 9800 3050
Wire Wire Line
	10150 2850 9800 2850
Wire Wire Line
	10150 2650 9800 2650
Wire Wire Line
	10150 2450 9800 2450
Wire Wire Line
	10150 2250 9800 2250
Wire Wire Line
	10150 2150 9800 2150
Wire Wire Line
	10150 2350 9800 2350
Wire Wire Line
	10150 2550 9800 2550
Wire Wire Line
	10150 2750 9800 2750
Wire Wire Line
	10150 2950 9800 2950
Wire Wire Line
	10150 3150 9800 3150
Wire Wire Line
	10150 3350 9800 3350
Wire Wire Line
	10150 3550 9800 3550
Wire Wire Line
	10150 3750 9800 3750
Wire Wire Line
	10150 3950 9800 3950
Wire Wire Line
	1000 4800 1000 4900
Wire Wire Line
	1000 4900 1650 4900
Wire Wire Line
	1650 4800 1400 4800
Wire Wire Line
	1650 4700 1450 4700
Wire Wire Line
	1650 5000 1450 5000
Wire Wire Line
	1450 5000 1450 5200
Wire Wire Line
	1450 4700 1450 4500
Wire Wire Line
	7200 3950 6850 3950
Wire Wire Line
	7200 3750 6850 3750
Wire Wire Line
	7200 3550 6850 3550
Wire Wire Line
	7200 3350 6850 3350
Wire Wire Line
	7200 3150 6850 3150
Wire Wire Line
	7200 2950 6850 2950
Wire Wire Line
	7200 2750 6850 2750
Wire Wire Line
	7200 2550 6850 2550
Wire Wire Line
	7200 2350 6850 2350
Wire Wire Line
	7200 2150 6850 2150
Wire Wire Line
	7200 2250 6850 2250
Wire Wire Line
	7200 2450 6850 2450
Wire Wire Line
	7200 2650 6850 2650
Wire Wire Line
	7200 2850 6850 2850
Wire Wire Line
	7200 3050 6850 3050
Wire Wire Line
	7200 3250 6850 3250
Wire Wire Line
	7200 3450 6850 3450
Wire Wire Line
	7200 3650 6850 3650
Wire Wire Line
	7200 3850 6850 3850
Wire Wire Line
	7200 4050 6850 4050
Wire Wire Line
	5950 4050 5600 4050
Wire Wire Line
	5950 3850 5600 3850
Wire Wire Line
	5950 3650 5600 3650
Wire Wire Line
	5950 3450 5600 3450
Wire Wire Line
	5950 3250 5600 3250
Wire Wire Line
	5950 3050 5600 3050
Wire Wire Line
	5950 2850 5600 2850
Wire Wire Line
	5950 2650 5600 2650
Wire Wire Line
	5950 2450 5600 2450
Wire Wire Line
	5950 2250 5600 2250
Wire Wire Line
	5950 2150 5600 2150
Wire Wire Line
	5950 2350 5600 2350
Wire Wire Line
	5950 2550 5600 2550
Wire Wire Line
	5950 2750 5600 2750
Wire Wire Line
	5950 2950 5600 2950
Wire Wire Line
	5950 3150 5600 3150
Wire Wire Line
	5950 3350 5600 3350
Wire Wire Line
	5950 3550 5600 3550
Wire Wire Line
	5950 3750 5600 3750
Wire Wire Line
	5950 3950 5600 3950
Wire Wire Line
	4550 3950 4200 3950
Wire Wire Line
	4550 3750 4200 3750
Wire Wire Line
	4550 3550 4200 3550
Wire Wire Line
	4550 3350 4200 3350
Wire Wire Line
	4550 3150 4200 3150
Wire Wire Line
	4550 2950 4200 2950
Wire Wire Line
	4550 2750 4200 2750
Wire Wire Line
	4550 2550 4200 2550
Wire Wire Line
	4550 2350 4200 2350
Wire Wire Line
	4550 2150 4200 2150
Wire Wire Line
	4550 2250 4200 2250
Wire Wire Line
	4550 2450 4200 2450
Wire Wire Line
	4550 2650 4200 2650
Wire Wire Line
	4550 2850 4200 2850
Wire Wire Line
	4550 3050 4200 3050
Wire Wire Line
	4550 3250 4200 3250
Wire Wire Line
	4550 3450 4200 3450
Wire Wire Line
	4550 3650 4200 3650
Wire Wire Line
	4550 3850 4200 3850
Wire Wire Line
	4550 4050 4200 4050
Wire Wire Line
	1550 6200 1550 6350
Wire Wire Line
	1550 6350 1350 6350
Wire Wire Line
	1350 6350 1350 6200
Wire Wire Line
	3150 4050 2800 4050
Wire Wire Line
	3150 3850 2800 3850
Wire Wire Line
	3150 3650 2800 3650
Wire Wire Line
	3150 3450 2800 3450
Wire Wire Line
	3150 3250 2800 3250
Wire Wire Line
	3150 3050 2800 3050
Wire Wire Line
	3150 2850 2800 2850
Wire Wire Line
	3150 2650 2800 2650
Wire Wire Line
	3150 2450 2800 2450
Wire Wire Line
	3150 2250 2800 2250
Wire Wire Line
	3150 2150 2800 2150
Wire Wire Line
	3150 2350 2800 2350
Wire Wire Line
	3150 2550 2800 2550
Wire Wire Line
	3150 2750 2800 2750
Wire Wire Line
	3150 2950 2800 2950
Wire Wire Line
	3150 3150 2800 3150
Wire Wire Line
	3150 3350 2800 3350
Wire Wire Line
	3150 3550 2800 3550
Wire Wire Line
	3150 3750 2800 3750
Wire Wire Line
	3150 3950 2800 3950
Wire Wire Line
	1950 6150 1950 6350
Wire Wire Line
	1950 6350 2150 6350
Wire Wire Line
	2150 6350 2150 6150
Wire Wire Line
	2000 8050 1800 8050
Wire Wire Line
	1800 8050 1800 8350
Connection ~ 1800 8150
Wire Wire Line
	1650 4600 1450 4600
Connection ~ 1450 4600
Wire Wire Line
	2000 8250 1800 8250
Connection ~ 1800 8250
Wire Wire Line
	2450 6150 2450 6350
$Comp
L TST P15
U 1 1 4FE1CC4E
P 4150 6500
F 0 "P15" H 4150 6800 40  0000 C CNN
F 1 "TST" H 4150 6750 30  0000 C CNN
	1    4150 6500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 4FE1CB11
P 2450 6350
F 0 "#PWR09" H 2450 6350 30  0001 C CNN
F 1 "GND" H 2450 6280 30  0001 C CNN
	1    2450 6350
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG010
U 1 1 4FE1CB06
P 2450 6150
F 0 "#FLG010" H 2450 6245 30  0001 C CNN
F 1 "PWR_FLAG" H 2450 6330 30  0000 C CNN
	1    2450 6150
	-1   0    0    -1  
$EndComp
$Comp
L VDD #PWR011
U 1 1 4FE1CAC7
P 9500 4800
F 0 "#PWR011" H 9500 4900 30  0001 C CNN
F 1 "VDD" H 9500 4910 30  0000 C CNN
	1    9500 4800
	1    0    0    -1  
$EndComp
Text GLabel 9900 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P14
U 1 1 4FE1CAC6
P 10500 4850
F 0 "P14" V 10450 4850 60  0000 C CNN
F 1 "CONN_6" V 10550 4850 60  0000 C CNN
	1    10500 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR012
U 1 1 4FE1CAC5
P 9950 5200
F 0 "#PWR012" H 9950 5200 30  0001 C CNN
F 1 "GND" H 9950 5130 30  0001 C CNN
	1    9950 5200
	-1   0    0    -1  
$EndComp
Text GLabel 9950 4500 1    60   Input ~ 0
24v
Text GLabel 8600 4500 1    60   Input ~ 0
24v
$Comp
L GND #PWR013
U 1 1 4FE1CAC1
P 8600 5200
F 0 "#PWR013" H 8600 5200 30  0001 C CNN
F 1 "GND" H 8600 5130 30  0001 C CNN
	1    8600 5200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P12
U 1 1 4FE1CAC0
P 9150 4850
F 0 "P12" V 9100 4850 60  0000 C CNN
F 1 "CONN_6" V 9200 4850 60  0000 C CNN
	1    9150 4850
	1    0    0    1   
$EndComp
Text GLabel 8550 4800 0    60   Input ~ 0
10v
$Comp
L VDD #PWR014
U 1 1 4FE1CABF
P 8150 4800
F 0 "#PWR014" H 8150 4900 30  0001 C CNN
F 1 "VDD" H 8150 4910 30  0000 C CNN
	1    8150 4800
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR015
U 1 1 4FE1CABD
P 6600 4800
F 0 "#PWR015" H 6600 4900 30  0001 C CNN
F 1 "VDD" H 6600 4910 30  0000 C CNN
	1    6600 4800
	1    0    0    -1  
$EndComp
Text GLabel 7000 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P10
U 1 1 4FE1CABC
P 7600 4850
F 0 "P10" V 7550 4850 60  0000 C CNN
F 1 "CONN_6" V 7650 4850 60  0000 C CNN
	1    7600 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR016
U 1 1 4FE1CABB
P 7050 5200
F 0 "#PWR016" H 7050 5200 30  0001 C CNN
F 1 "GND" H 7050 5130 30  0001 C CNN
	1    7050 5200
	-1   0    0    -1  
$EndComp
Text GLabel 7050 4500 1    60   Input ~ 0
24v
Text GLabel 5800 4500 1    60   Input ~ 0
24v
$Comp
L GND #PWR017
U 1 1 4FE1CAB1
P 5800 5200
F 0 "#PWR017" H 5800 5200 30  0001 C CNN
F 1 "GND" H 5800 5130 30  0001 C CNN
	1    5800 5200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P8
U 1 1 4FE1CAB0
P 6350 4850
F 0 "P8" V 6300 4850 60  0000 C CNN
F 1 "CONN_6" V 6400 4850 60  0000 C CNN
	1    6350 4850
	1    0    0    1   
$EndComp
Text GLabel 5750 4800 0    60   Input ~ 0
10v
$Comp
L VDD #PWR018
U 1 1 4FE1CAAF
P 5350 4800
F 0 "#PWR018" H 5350 4900 30  0001 C CNN
F 1 "VDD" H 5350 4910 30  0000 C CNN
	1    5350 4800
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR019
U 1 1 4FE1CAA7
P 3900 4700
F 0 "#PWR019" H 3900 4800 30  0001 C CNN
F 1 "VDD" H 3900 4810 30  0000 C CNN
	1    3900 4700
	1    0    0    -1  
$EndComp
Text GLabel 4300 4700 0    60   Input ~ 0
10v
$Comp
L CONN_6 P6
U 1 1 4FE1CAA6
P 4900 4750
F 0 "P6" V 4850 4750 60  0000 C CNN
F 1 "CONN_6" V 4950 4750 60  0000 C CNN
	1    4900 4750
	1    0    0    1   
$EndComp
$Comp
L GND #PWR020
U 1 1 4FE1CAA5
P 4350 5100
F 0 "#PWR020" H 4350 5100 30  0001 C CNN
F 1 "GND" H 4350 5030 30  0001 C CNN
	1    4350 5100
	-1   0    0    -1  
$EndComp
Text GLabel 4350 4400 1    60   Input ~ 0
24v
Text GLabel 2950 4400 1    60   Input ~ 0
24v
$Comp
L GND #PWR021
U 1 1 4FE1CAA1
P 2950 5100
F 0 "#PWR021" H 2950 5100 30  0001 C CNN
F 1 "GND" H 2950 5030 30  0001 C CNN
	1    2950 5100
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P4
U 1 1 4FE1CAA0
P 3500 4750
F 0 "P4" V 3450 4750 60  0000 C CNN
F 1 "CONN_6" V 3550 4750 60  0000 C CNN
	1    3500 4750
	1    0    0    1   
$EndComp
Text GLabel 2900 4700 0    60   Input ~ 0
10v
$Comp
L VDD #PWR022
U 1 1 4FE1CA9F
P 2500 4700
F 0 "#PWR022" H 2500 4800 30  0001 C CNN
F 1 "VDD" H 2500 4810 30  0000 C CNN
	1    2500 4700
	1    0    0    -1  
$EndComp
Text Notes 8700 1950 0    60   ~ 0
Third MCU power boards couple
Text Notes 5850 1900 0    60   ~ 0
Second MCU power boards couple
Text Notes 3200 1900 0    60   ~ 0
First MCU power boards couple
Text Notes 1450 7300 0    60   ~ 0
External power
Text Notes 1100 4050 0    60   ~ 0
For power supply
Text GLabel 1800 7650 1    60   Input ~ 0
24v
$Comp
L GND #PWR023
U 1 1 4FE1C9C8
P 1800 8350
F 0 "#PWR023" H 1800 8350 30  0001 C CNN
F 1 "GND" H 1800 8280 30  0001 C CNN
	1    1800 8350
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P2
U 1 1 4FE1C9C7
P 2350 8000
F 0 "P2" V 2300 8000 60  0000 C CNN
F 1 "CONN_6" V 2400 8000 60  0000 C CNN
	1    2350 8000
	1    0    0    1   
$EndComp
$Comp
L CONN_20 P11
U 1 1 4FDE4B84
P 9150 3100
F 0 "P11" V 9100 3100 60  0000 C CNN
F 1 "CONN_20" V 9200 3100 60  0000 C CNN
	1    9150 3100
	1    0    0    -1  
$EndComp
Text Label 8500 4050 0    60   ~ 0
iob20
Text Label 8500 3950 0    60   ~ 0
iob19
Text Label 8500 3850 0    60   ~ 0
iob18
Text Label 8500 3750 0    60   ~ 0
iob17
Text Label 8500 3650 0    60   ~ 0
iob16
Text Label 8500 3550 0    60   ~ 0
iob15
Text Label 8500 3450 0    60   ~ 0
iob14
Text Label 8500 3350 0    60   ~ 0
iob13
Text Label 8500 3250 0    60   ~ 0
iob12
Text Label 8500 3150 0    60   ~ 0
iob11
Text Label 8500 3050 0    60   ~ 0
iob10
Text Label 8500 2950 0    60   ~ 0
iob9
Text Label 8500 2850 0    60   ~ 0
iob8
Text Label 8500 2750 0    60   ~ 0
iob7
Text Label 8500 2650 0    60   ~ 0
iob6
Text Label 8500 2550 0    60   ~ 0
iob5
Text Label 8500 2450 0    60   ~ 0
iob4
Text Label 8500 2350 0    60   ~ 0
iob3
Text Label 8500 2250 0    60   ~ 0
iob2
Text Label 8500 2150 0    60   ~ 0
iob1
Text Label 9850 2150 0    60   ~ 0
iob1
Text Label 9850 2250 0    60   ~ 0
iob2
Text Label 9850 2350 0    60   ~ 0
iob3
Text Label 9850 2450 0    60   ~ 0
iob4
Text Label 9850 2550 0    60   ~ 0
iob5
Text Label 9850 2650 0    60   ~ 0
iob6
Text Label 9850 2750 0    60   ~ 0
iob7
Text Label 9850 2850 0    60   ~ 0
iob8
Text Label 9850 2950 0    60   ~ 0
iob9
Text Label 9850 3050 0    60   ~ 0
iob10
Text Label 9850 3150 0    60   ~ 0
iob11
Text Label 9850 3250 0    60   ~ 0
iob12
Text Label 9850 3350 0    60   ~ 0
iob13
Text Label 9850 3450 0    60   ~ 0
iob14
Text Label 9850 3550 0    60   ~ 0
iob15
Text Label 9850 3650 0    60   ~ 0
iob16
Text Label 9850 3750 0    60   ~ 0
iob17
Text Label 9850 3850 0    60   ~ 0
iob18
Text Label 9850 3950 0    60   ~ 0
iob19
Text Label 9850 4050 0    60   ~ 0
iob20
$Comp
L CONN_20 P13
U 1 1 4FDE4B83
P 10500 3100
F 0 "P13" V 10450 3100 60  0000 C CNN
F 1 "CONN_20" V 10550 3100 60  0000 C CNN
	1    10500 3100
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR024
U 1 1 4FDE4ABB
P 1000 4800
F 0 "#PWR024" H 1000 4900 30  0001 C CNN
F 1 "VDD" H 1000 4910 30  0000 C CNN
	1    1000 4800
	1    0    0    -1  
$EndComp
Text GLabel 1400 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P1
U 1 1 4FDE4ABA
P 2000 4850
F 0 "P1" V 1950 4850 60  0000 C CNN
F 1 "CONN_6" V 2050 4850 60  0000 C CNN
	1    2000 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR025
U 1 1 4FDE4AB9
P 1450 5200
F 0 "#PWR025" H 1450 5200 30  0001 C CNN
F 1 "GND" H 1450 5130 30  0001 C CNN
	1    1450 5200
	-1   0    0    -1  
$EndComp
Text GLabel 1450 4500 1    60   Input ~ 0
24v
$Comp
L CONN_20 P9
U 1 1 4FDE4AA3
P 7550 3100
F 0 "P9" V 7500 3100 60  0000 C CNN
F 1 "CONN_20" V 7600 3100 60  0000 C CNN
	1    7550 3100
	1    0    0    -1  
$EndComp
Text Label 6900 4050 0    60   ~ 0
ioa20
Text Label 6900 3950 0    60   ~ 0
ioa19
Text Label 6900 3850 0    60   ~ 0
ioa18
Text Label 6900 3750 0    60   ~ 0
ioa17
Text Label 6900 3650 0    60   ~ 0
ioa16
Text Label 6900 3550 0    60   ~ 0
ioa15
Text Label 6900 3450 0    60   ~ 0
ioa14
Text Label 6900 3350 0    60   ~ 0
ioa13
Text Label 6900 3250 0    60   ~ 0
ioa12
Text Label 6900 3150 0    60   ~ 0
ioa11
Text Label 6900 3050 0    60   ~ 0
ioa10
Text Label 6900 2950 0    60   ~ 0
ioa9
Text Label 6900 2850 0    60   ~ 0
ioa8
Text Label 6900 2750 0    60   ~ 0
ioa7
Text Label 6900 2650 0    60   ~ 0
ioa6
Text Label 6900 2550 0    60   ~ 0
ioa5
Text Label 6900 2450 0    60   ~ 0
ioa4
Text Label 6900 2350 0    60   ~ 0
ioa3
Text Label 6900 2250 0    60   ~ 0
ioa2
Text Label 6900 2150 0    60   ~ 0
ioa1
Text Label 5650 2150 0    60   ~ 0
ioa1
Text Label 5650 2250 0    60   ~ 0
ioa2
Text Label 5650 2350 0    60   ~ 0
ioa3
Text Label 5650 2450 0    60   ~ 0
ioa4
Text Label 5650 2550 0    60   ~ 0
ioa5
Text Label 5650 2650 0    60   ~ 0
ioa6
Text Label 5650 2750 0    60   ~ 0
ioa7
Text Label 5650 2850 0    60   ~ 0
ioa8
Text Label 5650 2950 0    60   ~ 0
ioa9
Text Label 5650 3050 0    60   ~ 0
ioa10
Text Label 5650 3150 0    60   ~ 0
ioa11
Text Label 5650 3250 0    60   ~ 0
ioa12
Text Label 5650 3350 0    60   ~ 0
ioa13
Text Label 5650 3450 0    60   ~ 0
ioa14
Text Label 5650 3550 0    60   ~ 0
ioa15
Text Label 5650 3650 0    60   ~ 0
ioa16
Text Label 5650 3750 0    60   ~ 0
ioa17
Text Label 5650 3850 0    60   ~ 0
ioa18
Text Label 5650 3950 0    60   ~ 0
ioa19
Text Label 5650 4050 0    60   ~ 0
ioa20
$Comp
L CONN_20 P7
U 1 1 4FDE4A99
P 6300 3100
F 0 "P7" V 6250 3100 60  0000 C CNN
F 1 "CONN_20" V 6350 3100 60  0000 C CNN
	1    6300 3100
	1    0    0    -1  
$EndComp
$Comp
L CONN_20 P5
U 1 1 4FDE4A8C
P 4900 3100
F 0 "P5" V 4850 3100 60  0000 C CNN
F 1 "CONN_20" V 4950 3100 60  0000 C CNN
	1    4900 3100
	1    0    0    -1  
$EndComp
Text Label 4250 4050 0    60   ~ 0
io20
Text Label 4250 3950 0    60   ~ 0
io19
Text Label 4250 3850 0    60   ~ 0
io18
Text Label 4250 3750 0    60   ~ 0
io17
Text Label 4250 3650 0    60   ~ 0
io16
Text Label 4250 3550 0    60   ~ 0
io15
Text Label 4250 3450 0    60   ~ 0
io14
Text Label 4250 3350 0    60   ~ 0
io13
Text Label 4250 3250 0    60   ~ 0
io12
Text Label 4250 3150 0    60   ~ 0
io11
Text Label 4250 3050 0    60   ~ 0
io10
Text Label 4250 2950 0    60   ~ 0
io9
Text Label 4250 2850 0    60   ~ 0
io8
Text Label 4250 2750 0    60   ~ 0
io7
Text Label 4250 2650 0    60   ~ 0
io6
Text Label 4250 2550 0    60   ~ 0
io5
Text Label 4250 2450 0    60   ~ 0
io4
Text Label 4250 2350 0    60   ~ 0
io3
Text Label 4250 2250 0    60   ~ 0
io2
Text Label 4250 2150 0    60   ~ 0
io1
Text Label 2850 2150 0    60   ~ 0
io1
Text Label 2850 2250 0    60   ~ 0
io2
Text Label 2850 2350 0    60   ~ 0
io3
Text Label 2850 2450 0    60   ~ 0
io4
Text Label 2850 2550 0    60   ~ 0
io5
Text Label 2850 2650 0    60   ~ 0
io6
Text Label 2850 2750 0    60   ~ 0
io7
Text Label 2850 2850 0    60   ~ 0
io8
Text Label 2850 2950 0    60   ~ 0
io9
Text Label 2850 3050 0    60   ~ 0
io10
Text Label 2850 3150 0    60   ~ 0
io11
Text Label 2850 3250 0    60   ~ 0
io12
Text Label 2850 3350 0    60   ~ 0
io13
Text Label 2850 3450 0    60   ~ 0
io14
Text Label 2850 3550 0    60   ~ 0
io15
Text Label 2850 3650 0    60   ~ 0
io16
Text Label 2850 3750 0    60   ~ 0
io17
Text Label 2850 3850 0    60   ~ 0
io18
Text Label 2850 3950 0    60   ~ 0
io19
Text Label 2850 4050 0    60   ~ 0
io20
$Comp
L CONN_20 P3
U 1 1 4FDE49FE
P 3500 3100
F 0 "P3" V 3450 3100 60  0000 C CNN
F 1 "CONN_20" V 3550 3100 60  0000 C CNN
	1    3500 3100
	1    0    0    -1  
$EndComp
Text GLabel 1550 6200 1    60   Input ~ 0
10v
$Comp
L PWR_FLAG #FLG026
U 1 1 4FDE49FD
P 1350 6200
F 0 "#FLG026" H 1350 6295 30  0001 C CNN
F 1 "PWR_FLAG" H 1350 6380 30  0000 C CNN
	1    1350 6200
	-1   0    0    -1  
$EndComp
$Comp
L VDD #PWR027
U 1 1 4FDE49FC
P 2150 6150
F 0 "#PWR027" H 2150 6250 30  0001 C CNN
F 1 "VDD" H 2150 6260 30  0000 C CNN
	1    2150 6150
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG028
U 1 1 4FDE49FB
P 1950 6150
F 0 "#FLG028" H 1950 6245 30  0001 C CNN
F 1 "PWR_FLAG" H 1950 6330 30  0000 C CNN
	1    1950 6150
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
