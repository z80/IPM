EESchema Schematic File Version 2  date Mon 18 Jun 2012 01:29:25 AM MSK
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
Date "17 jun 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	11400 4800 11400 4900
Wire Wire Line
	11400 4900 12050 4900
Wire Wire Line
	12050 4800 11800 4800
Wire Wire Line
	11550 4500 11550 4600
Wire Wire Line
	11550 4600 12050 4600
Wire Wire Line
	12050 4700 11850 4700
Wire Wire Line
	12050 5000 11850 5000
Wire Wire Line
	11850 5000 11850 5200
Connection ~ 11850 5100
Wire Wire Line
	11850 4700 11850 4500
Connection ~ 11850 4600
Wire Wire Line
	12050 5100 11200 5100
Wire Wire Line
	11200 5100 11200 5000
$Comp
L VDD #PWR?
U 1 1 4FDE4B8E
P 11400 4800
F 0 "#PWR?" H 11400 4900 30  0001 C CNN
F 1 "VDD" H 11400 4910 30  0000 C CNN
	1    11400 4800
	1    0    0    -1  
$EndComp
Text GLabel 11800 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P?
U 1 1 4FDE4B8D
P 12400 4850
F 0 "P?" V 12350 4850 60  0000 C CNN
F 1 "CONN_6" V 12450 4850 60  0000 C CNN
	1    12400 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 4FDE4B8C
P 11850 5200
F 0 "#PWR?" H 11850 5200 30  0001 C CNN
F 1 "GND" H 11850 5130 30  0001 C CNN
	1    11850 5200
	-1   0    0    -1  
$EndComp
Text GLabel 11850 4500 1    60   Input ~ 0
24v
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4B8B
P 11550 4500
F 0 "#FLG?" H 11550 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 11550 4680 30  0000 C CNN
	1    11550 4500
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4B8A
P 11200 5000
F 0 "#FLG?" H 11200 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 11200 5180 30  0000 C CNN
	1    11200 5000
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4B89
P 13100 5000
F 0 "#FLG?" H 13100 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 13100 5180 30  0000 C CNN
	1    13100 5000
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4B88
P 13450 4500
F 0 "#FLG?" H 13450 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 13450 4680 30  0000 C CNN
	1    13450 4500
	-1   0    0    -1  
$EndComp
Text GLabel 13750 4500 1    60   Input ~ 0
24v
$Comp
L GND #PWR?
U 1 1 4FDE4B87
P 13750 5200
F 0 "#PWR?" H 13750 5200 30  0001 C CNN
F 1 "GND" H 13750 5130 30  0001 C CNN
	1    13750 5200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P?
U 1 1 4FDE4B86
P 14300 4850
F 0 "P?" V 14250 4850 60  0000 C CNN
F 1 "CONN_6" V 14350 4850 60  0000 C CNN
	1    14300 4850
	1    0    0    1   
$EndComp
Text GLabel 13700 4800 0    60   Input ~ 0
10v
$Comp
L VDD #PWR?
U 1 1 4FDE4B85
P 13300 4800
F 0 "#PWR?" H 13300 4900 30  0001 C CNN
F 1 "VDD" H 13300 4910 30  0000 C CNN
	1    13300 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	13100 5100 13100 5000
Wire Wire Line
	13950 5100 13100 5100
Connection ~ 13750 4600
Wire Wire Line
	13750 4700 13750 4500
Connection ~ 13750 5100
Wire Wire Line
	13750 5000 13750 5200
Wire Wire Line
	13950 5000 13750 5000
Wire Wire Line
	13950 4700 13750 4700
Wire Wire Line
	13450 4600 13950 4600
Wire Wire Line
	13450 4500 13450 4600
Wire Wire Line
	13950 4800 13700 4800
Wire Wire Line
	13300 4900 13950 4900
Wire Wire Line
	13300 4800 13300 4900
Wire Wire Line
	12000 3950 11650 3950
Wire Wire Line
	12000 3750 11650 3750
Wire Wire Line
	12000 3550 11650 3550
Wire Wire Line
	12000 3350 11650 3350
Wire Wire Line
	12000 3150 11650 3150
Wire Wire Line
	12000 2950 11650 2950
Wire Wire Line
	12000 2750 11650 2750
Wire Wire Line
	12000 2550 11650 2550
Wire Wire Line
	12000 2350 11650 2350
Wire Wire Line
	12000 2150 11650 2150
Wire Wire Line
	12000 2250 11650 2250
Wire Wire Line
	12000 2450 11650 2450
Wire Wire Line
	12000 2650 11650 2650
Wire Wire Line
	12000 2850 11650 2850
Wire Wire Line
	12000 3050 11650 3050
Wire Wire Line
	12000 3250 11650 3250
Wire Wire Line
	12000 3450 11650 3450
Wire Wire Line
	12000 3650 11650 3650
Wire Wire Line
	12000 3850 11650 3850
Wire Wire Line
	12000 4050 11650 4050
$Comp
L CONN_20 P?
U 1 1 4FDE4B84
P 12350 3100
F 0 "P?" V 12300 3100 60  0000 C CNN
F 1 "CONN_20" V 12400 3100 60  0000 C CNN
	1    12350 3100
	1    0    0    -1  
$EndComp
Text Label 11700 4050 0    60   ~ 0
iob20
Text Label 11700 3950 0    60   ~ 0
iob19
Text Label 11700 3850 0    60   ~ 0
iob18
Text Label 11700 3750 0    60   ~ 0
iob17
Text Label 11700 3650 0    60   ~ 0
iob16
Text Label 11700 3550 0    60   ~ 0
iob15
Text Label 11700 3450 0    60   ~ 0
iob14
Text Label 11700 3350 0    60   ~ 0
iob13
Text Label 11700 3250 0    60   ~ 0
iob12
Text Label 11700 3150 0    60   ~ 0
iob11
Text Label 11700 3050 0    60   ~ 0
iob10
Text Label 11700 2950 0    60   ~ 0
iob9
Text Label 11700 2850 0    60   ~ 0
iob8
Text Label 11700 2750 0    60   ~ 0
iob7
Text Label 11700 2650 0    60   ~ 0
iob6
Text Label 11700 2550 0    60   ~ 0
iob5
Text Label 11700 2450 0    60   ~ 0
iob4
Text Label 11700 2350 0    60   ~ 0
iob3
Text Label 11700 2250 0    60   ~ 0
iob2
Text Label 11700 2150 0    60   ~ 0
iob1
Text Label 13600 2150 0    60   ~ 0
iob1
Text Label 13600 2250 0    60   ~ 0
iob2
Text Label 13600 2350 0    60   ~ 0
iob3
Text Label 13600 2450 0    60   ~ 0
iob4
Text Label 13600 2550 0    60   ~ 0
iob5
Text Label 13600 2650 0    60   ~ 0
iob6
Text Label 13600 2750 0    60   ~ 0
iob7
Text Label 13600 2850 0    60   ~ 0
iob8
Text Label 13600 2950 0    60   ~ 0
iob9
Text Label 13600 3050 0    60   ~ 0
iob10
Text Label 13600 3150 0    60   ~ 0
iob11
Text Label 13600 3250 0    60   ~ 0
iob12
Text Label 13600 3350 0    60   ~ 0
iob13
Text Label 13600 3450 0    60   ~ 0
iob14
Text Label 13600 3550 0    60   ~ 0
iob15
Text Label 13600 3650 0    60   ~ 0
iob16
Text Label 13600 3750 0    60   ~ 0
iob17
Text Label 13600 3850 0    60   ~ 0
iob18
Text Label 13600 3950 0    60   ~ 0
iob19
Text Label 13600 4050 0    60   ~ 0
iob20
$Comp
L CONN_20 P?
U 1 1 4FDE4B83
P 14250 3100
F 0 "P?" V 14200 3100 60  0000 C CNN
F 1 "CONN_20" V 14300 3100 60  0000 C CNN
	1    14250 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	13900 4050 13550 4050
Wire Wire Line
	13900 3850 13550 3850
Wire Wire Line
	13900 3650 13550 3650
Wire Wire Line
	13900 3450 13550 3450
Wire Wire Line
	13900 3250 13550 3250
Wire Wire Line
	13900 3050 13550 3050
Wire Wire Line
	13900 2850 13550 2850
Wire Wire Line
	13900 2650 13550 2650
Wire Wire Line
	13900 2450 13550 2450
Wire Wire Line
	13900 2250 13550 2250
Wire Wire Line
	13900 2150 13550 2150
Wire Wire Line
	13900 2350 13550 2350
Wire Wire Line
	13900 2550 13550 2550
Wire Wire Line
	13900 2750 13550 2750
Wire Wire Line
	13900 2950 13550 2950
Wire Wire Line
	13900 3150 13550 3150
Wire Wire Line
	13900 3350 13550 3350
Wire Wire Line
	13900 3550 13550 3550
Wire Wire Line
	13900 3750 13550 3750
Wire Wire Line
	13900 3950 13550 3950
Wire Wire Line
	1250 4800 1250 4900
Wire Wire Line
	1250 4900 1900 4900
Wire Wire Line
	1900 4800 1650 4800
Wire Wire Line
	1400 4500 1400 4600
Wire Wire Line
	1400 4600 1900 4600
Wire Wire Line
	1900 4700 1700 4700
Wire Wire Line
	1900 5000 1700 5000
Wire Wire Line
	1700 5000 1700 5200
Connection ~ 1700 5100
Wire Wire Line
	1700 4700 1700 4500
Connection ~ 1700 4600
Wire Wire Line
	1900 5100 1050 5100
Wire Wire Line
	1050 5100 1050 5000
$Comp
L VDD #PWR?
U 1 1 4FDE4ABB
P 1250 4800
F 0 "#PWR?" H 1250 4900 30  0001 C CNN
F 1 "VDD" H 1250 4910 30  0000 C CNN
	1    1250 4800
	1    0    0    -1  
$EndComp
Text GLabel 1650 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P?
U 1 1 4FDE4ABA
P 2250 4850
F 0 "P?" V 2200 4850 60  0000 C CNN
F 1 "CONN_6" V 2300 4850 60  0000 C CNN
	1    2250 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 4FDE4AB9
P 1700 5200
F 0 "#PWR?" H 1700 5200 30  0001 C CNN
F 1 "GND" H 1700 5130 30  0001 C CNN
	1    1700 5200
	-1   0    0    -1  
$EndComp
Text GLabel 1700 4500 1    60   Input ~ 0
24v
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4AB8
P 1400 4500
F 0 "#FLG?" H 1400 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 1400 4680 30  0000 C CNN
	1    1400 4500
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4AB7
P 1050 5000
F 0 "#FLG?" H 1050 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 1050 5180 30  0000 C CNN
	1    1050 5000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9900 3950 9550 3950
Wire Wire Line
	9900 3750 9550 3750
Wire Wire Line
	9900 3550 9550 3550
Wire Wire Line
	9900 3350 9550 3350
Wire Wire Line
	9900 3150 9550 3150
Wire Wire Line
	9900 2950 9550 2950
Wire Wire Line
	9900 2750 9550 2750
Wire Wire Line
	9900 2550 9550 2550
Wire Wire Line
	9900 2350 9550 2350
Wire Wire Line
	9900 2150 9550 2150
Wire Wire Line
	9900 2250 9550 2250
Wire Wire Line
	9900 2450 9550 2450
Wire Wire Line
	9900 2650 9550 2650
Wire Wire Line
	9900 2850 9550 2850
Wire Wire Line
	9900 3050 9550 3050
Wire Wire Line
	9900 3250 9550 3250
Wire Wire Line
	9900 3450 9550 3450
Wire Wire Line
	9900 3650 9550 3650
Wire Wire Line
	9900 3850 9550 3850
Wire Wire Line
	9900 4050 9550 4050
$Comp
L CONN_20 P?
U 1 1 4FDE4AA3
P 10250 3100
F 0 "P?" V 10200 3100 60  0000 C CNN
F 1 "CONN_20" V 10300 3100 60  0000 C CNN
	1    10250 3100
	1    0    0    -1  
$EndComp
Text Label 9600 4050 0    60   ~ 0
ioa20
Text Label 9600 3950 0    60   ~ 0
ioa19
Text Label 9600 3850 0    60   ~ 0
ioa18
Text Label 9600 3750 0    60   ~ 0
ioa17
Text Label 9600 3650 0    60   ~ 0
ioa16
Text Label 9600 3550 0    60   ~ 0
ioa15
Text Label 9600 3450 0    60   ~ 0
ioa14
Text Label 9600 3350 0    60   ~ 0
ioa13
Text Label 9600 3250 0    60   ~ 0
ioa12
Text Label 9600 3150 0    60   ~ 0
ioa11
Text Label 9600 3050 0    60   ~ 0
ioa10
Text Label 9600 2950 0    60   ~ 0
ioa9
Text Label 9600 2850 0    60   ~ 0
ioa8
Text Label 9600 2750 0    60   ~ 0
ioa7
Text Label 9600 2650 0    60   ~ 0
ioa6
Text Label 9600 2550 0    60   ~ 0
ioa5
Text Label 9600 2450 0    60   ~ 0
ioa4
Text Label 9600 2350 0    60   ~ 0
ioa3
Text Label 9600 2250 0    60   ~ 0
ioa2
Text Label 9600 2150 0    60   ~ 0
ioa1
Text Label 7700 2150 0    60   ~ 0
ioa1
Text Label 7700 2250 0    60   ~ 0
ioa2
Text Label 7700 2350 0    60   ~ 0
ioa3
Text Label 7700 2450 0    60   ~ 0
ioa4
Text Label 7700 2550 0    60   ~ 0
ioa5
Text Label 7700 2650 0    60   ~ 0
ioa6
Text Label 7700 2750 0    60   ~ 0
ioa7
Text Label 7700 2850 0    60   ~ 0
ioa8
Text Label 7700 2950 0    60   ~ 0
ioa9
Text Label 7700 3050 0    60   ~ 0
ioa10
Text Label 7700 3150 0    60   ~ 0
ioa11
Text Label 7700 3250 0    60   ~ 0
ioa12
Text Label 7700 3350 0    60   ~ 0
ioa13
Text Label 7700 3450 0    60   ~ 0
ioa14
Text Label 7700 3550 0    60   ~ 0
ioa15
Text Label 7700 3650 0    60   ~ 0
ioa16
Text Label 7700 3750 0    60   ~ 0
ioa17
Text Label 7700 3850 0    60   ~ 0
ioa18
Text Label 7700 3950 0    60   ~ 0
ioa19
Text Label 7700 4050 0    60   ~ 0
ioa20
$Comp
L CONN_20 P?
U 1 1 4FDE4A99
P 8350 3100
F 0 "P?" V 8300 3100 60  0000 C CNN
F 1 "CONN_20" V 8400 3100 60  0000 C CNN
	1    8350 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 4050 7650 4050
Wire Wire Line
	8000 3850 7650 3850
Wire Wire Line
	8000 3650 7650 3650
Wire Wire Line
	8000 3450 7650 3450
Wire Wire Line
	8000 3250 7650 3250
Wire Wire Line
	8000 3050 7650 3050
Wire Wire Line
	8000 2850 7650 2850
Wire Wire Line
	8000 2650 7650 2650
Wire Wire Line
	8000 2450 7650 2450
Wire Wire Line
	8000 2250 7650 2250
Wire Wire Line
	8000 2150 7650 2150
Wire Wire Line
	8000 2350 7650 2350
Wire Wire Line
	8000 2550 7650 2550
Wire Wire Line
	8000 2750 7650 2750
Wire Wire Line
	8000 2950 7650 2950
Wire Wire Line
	8000 3150 7650 3150
Wire Wire Line
	8000 3350 7650 3350
Wire Wire Line
	8000 3550 7650 3550
Wire Wire Line
	8000 3750 7650 3750
Wire Wire Line
	8000 3950 7650 3950
Wire Wire Line
	5900 3950 5550 3950
Wire Wire Line
	5900 3750 5550 3750
Wire Wire Line
	5900 3550 5550 3550
Wire Wire Line
	5900 3350 5550 3350
Wire Wire Line
	5900 3150 5550 3150
Wire Wire Line
	5900 2950 5550 2950
Wire Wire Line
	5900 2750 5550 2750
Wire Wire Line
	5900 2550 5550 2550
Wire Wire Line
	5900 2350 5550 2350
Wire Wire Line
	5900 2150 5550 2150
Wire Wire Line
	5900 2250 5550 2250
Wire Wire Line
	5900 2450 5550 2450
Wire Wire Line
	5900 2650 5550 2650
Wire Wire Line
	5900 2850 5550 2850
Wire Wire Line
	5900 3050 5550 3050
Wire Wire Line
	5900 3250 5550 3250
Wire Wire Line
	5900 3450 5550 3450
Wire Wire Line
	5900 3650 5550 3650
Wire Wire Line
	5900 3850 5550 3850
Wire Wire Line
	5900 4050 5550 4050
$Comp
L CONN_20 P?
U 1 1 4FDE4A8C
P 6250 3100
F 0 "P?" V 6200 3100 60  0000 C CNN
F 1 "CONN_20" V 6300 3100 60  0000 C CNN
	1    6250 3100
	1    0    0    -1  
$EndComp
Text Label 5600 4050 0    60   ~ 0
io20
Text Label 5600 3950 0    60   ~ 0
io19
Text Label 5600 3850 0    60   ~ 0
io18
Text Label 5600 3750 0    60   ~ 0
io17
Text Label 5600 3650 0    60   ~ 0
io16
Text Label 5600 3550 0    60   ~ 0
io15
Text Label 5600 3450 0    60   ~ 0
io14
Text Label 5600 3350 0    60   ~ 0
io13
Text Label 5600 3250 0    60   ~ 0
io12
Text Label 5600 3150 0    60   ~ 0
io11
Text Label 5600 3050 0    60   ~ 0
io10
Text Label 5600 2950 0    60   ~ 0
io9
Text Label 5600 2850 0    60   ~ 0
io8
Text Label 5600 2750 0    60   ~ 0
io7
Text Label 5600 2650 0    60   ~ 0
io6
Text Label 5600 2550 0    60   ~ 0
io5
Text Label 5600 2450 0    60   ~ 0
io4
Text Label 5600 2350 0    60   ~ 0
io3
Text Label 5600 2250 0    60   ~ 0
io2
Text Label 5600 2150 0    60   ~ 0
io1
Wire Wire Line
	9300 4800 9300 4900
Wire Wire Line
	9300 4900 9950 4900
Wire Wire Line
	9950 4800 9700 4800
Wire Wire Line
	9450 4500 9450 4600
Wire Wire Line
	9450 4600 9950 4600
Wire Wire Line
	9950 4700 9750 4700
Wire Wire Line
	9950 5000 9750 5000
Wire Wire Line
	9750 5000 9750 5200
Connection ~ 9750 5100
Wire Wire Line
	9750 4700 9750 4500
Connection ~ 9750 4600
Wire Wire Line
	9950 5100 9100 5100
Wire Wire Line
	9100 5100 9100 5000
$Comp
L VDD #PWR?
U 1 1 4FDE4A74
P 9300 4800
F 0 "#PWR?" H 9300 4900 30  0001 C CNN
F 1 "VDD" H 9300 4910 30  0000 C CNN
	1    9300 4800
	1    0    0    -1  
$EndComp
Text GLabel 9700 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P?
U 1 1 4FDE4A73
P 10300 4850
F 0 "P?" V 10250 4850 60  0000 C CNN
F 1 "CONN_6" V 10350 4850 60  0000 C CNN
	1    10300 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 4FDE4A72
P 9750 5200
F 0 "#PWR?" H 9750 5200 30  0001 C CNN
F 1 "GND" H 9750 5130 30  0001 C CNN
	1    9750 5200
	-1   0    0    -1  
$EndComp
Text GLabel 9750 4500 1    60   Input ~ 0
24v
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A71
P 9450 4500
F 0 "#FLG?" H 9450 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 9450 4680 30  0000 C CNN
	1    9450 4500
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A70
P 9100 5000
F 0 "#FLG?" H 9100 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 9100 5180 30  0000 C CNN
	1    9100 5000
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A6B
P 7200 5000
F 0 "#FLG?" H 7200 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 7200 5180 30  0000 C CNN
	1    7200 5000
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A6A
P 7550 4500
F 0 "#FLG?" H 7550 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 7550 4680 30  0000 C CNN
	1    7550 4500
	-1   0    0    -1  
$EndComp
Text GLabel 7850 4500 1    60   Input ~ 0
24v
$Comp
L GND #PWR?
U 1 1 4FDE4A69
P 7850 5200
F 0 "#PWR?" H 7850 5200 30  0001 C CNN
F 1 "GND" H 7850 5130 30  0001 C CNN
	1    7850 5200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_6 P?
U 1 1 4FDE4A68
P 8400 4850
F 0 "P?" V 8350 4850 60  0000 C CNN
F 1 "CONN_6" V 8450 4850 60  0000 C CNN
	1    8400 4850
	1    0    0    1   
$EndComp
Text GLabel 7800 4800 0    60   Input ~ 0
10v
$Comp
L VDD #PWR?
U 1 1 4FDE4A67
P 7400 4800
F 0 "#PWR?" H 7400 4900 30  0001 C CNN
F 1 "VDD" H 7400 4910 30  0000 C CNN
	1    7400 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 5100 7200 5000
Wire Wire Line
	8050 5100 7200 5100
Connection ~ 7850 4600
Wire Wire Line
	7850 4700 7850 4500
Connection ~ 7850 5100
Wire Wire Line
	7850 5000 7850 5200
Wire Wire Line
	8050 5000 7850 5000
Wire Wire Line
	8050 4700 7850 4700
Wire Wire Line
	7550 4600 8050 4600
Wire Wire Line
	7550 4500 7550 4600
Wire Wire Line
	8050 4800 7800 4800
Wire Wire Line
	7400 4900 8050 4900
Wire Wire Line
	7400 4800 7400 4900
Wire Wire Line
	5250 4800 5250 4900
Wire Wire Line
	5250 4900 5900 4900
Wire Wire Line
	5900 4800 5650 4800
Wire Wire Line
	5400 4500 5400 4600
Wire Wire Line
	5400 4600 5900 4600
Wire Wire Line
	5900 4700 5700 4700
Wire Wire Line
	5900 5000 5700 5000
Wire Wire Line
	5700 5000 5700 5200
Connection ~ 5700 5100
Wire Wire Line
	5700 4700 5700 4500
Connection ~ 5700 4600
Wire Wire Line
	5900 5100 5050 5100
Wire Wire Line
	5050 5100 5050 5000
$Comp
L VDD #PWR?
U 1 1 4FDE4A61
P 5250 4800
F 0 "#PWR?" H 5250 4900 30  0001 C CNN
F 1 "VDD" H 5250 4910 30  0000 C CNN
	1    5250 4800
	1    0    0    -1  
$EndComp
Text GLabel 5650 4800 0    60   Input ~ 0
10v
$Comp
L CONN_6 P?
U 1 1 4FDE4A60
P 6250 4850
F 0 "P?" V 6200 4850 60  0000 C CNN
F 1 "CONN_6" V 6300 4850 60  0000 C CNN
	1    6250 4850
	1    0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 4FDE4A5F
P 5700 5200
F 0 "#PWR?" H 5700 5200 30  0001 C CNN
F 1 "GND" H 5700 5130 30  0001 C CNN
	1    5700 5200
	-1   0    0    -1  
$EndComp
Text GLabel 5700 4500 1    60   Input ~ 0
24v
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A5E
P 5400 4500
F 0 "#FLG?" H 5400 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 5400 4680 30  0000 C CNN
	1    5400 4500
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A5D
P 5050 5000
F 0 "#FLG?" H 5050 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 5050 5180 30  0000 C CNN
	1    5050 5000
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A03
P 2850 5000
F 0 "#FLG?" H 2850 5095 30  0001 C CNN
F 1 "PWR_FLAG" H 2850 5180 30  0000 C CNN
	1    2850 5000
	-1   0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE4A02
P 3200 4500
F 0 "#FLG?" H 3200 4595 30  0001 C CNN
F 1 "PWR_FLAG" H 3200 4680 30  0000 C CNN
	1    3200 4500
	-1   0    0    -1  
$EndComp
Text GLabel 3500 4500 1    60   Input ~ 0
24v
$Comp
L GND #PWR?
U 1 1 4FDE4A01
P 3500 5200
F 0 "#PWR?" H 3500 5200 30  0001 C CNN
F 1 "GND" H 3500 5130 30  0001 C CNN
	1    3500 5200
	-1   0    0    -1  
$EndComp
Text Label 3400 2150 0    60   ~ 0
io1
Text Label 3400 2250 0    60   ~ 0
io2
Text Label 3400 2350 0    60   ~ 0
io3
Text Label 3400 2450 0    60   ~ 0
io4
Text Label 3400 2550 0    60   ~ 0
io5
Text Label 3400 2650 0    60   ~ 0
io6
Text Label 3400 2750 0    60   ~ 0
io7
Text Label 3400 2850 0    60   ~ 0
io8
Text Label 3400 2950 0    60   ~ 0
io9
Text Label 3400 3050 0    60   ~ 0
io10
Text Label 3400 3150 0    60   ~ 0
io11
Text Label 3400 3250 0    60   ~ 0
io12
Text Label 3400 3350 0    60   ~ 0
io13
Text Label 3400 3450 0    60   ~ 0
io14
Text Label 3400 3550 0    60   ~ 0
io15
Text Label 3400 3650 0    60   ~ 0
io16
Text Label 3400 3750 0    60   ~ 0
io17
Text Label 3400 3850 0    60   ~ 0
io18
Text Label 3400 3950 0    60   ~ 0
io19
Text Label 3400 4050 0    60   ~ 0
io20
$Comp
L CONN_6 P?
U 1 1 4FDE4A00
P 4050 4850
F 0 "P?" V 4000 4850 60  0000 C CNN
F 1 "CONN_6" V 4100 4850 60  0000 C CNN
	1    4050 4850
	1    0    0    1   
$EndComp
Text GLabel 3450 4800 0    60   Input ~ 0
10v
$Comp
L VDD #PWR?
U 1 1 4FDE49FF
P 3050 4800
F 0 "#PWR?" H 3050 4900 30  0001 C CNN
F 1 "VDD" H 3050 4910 30  0000 C CNN
	1    3050 4800
	1    0    0    -1  
$EndComp
$Comp
L CONN_20 P?
U 1 1 4FDE49FE
P 4050 3100
F 0 "P?" V 4000 3100 60  0000 C CNN
F 1 "CONN_20" V 4100 3100 60  0000 C CNN
	1    4050 3100
	1    0    0    -1  
$EndComp
Text GLabel 1800 6650 1    60   Input ~ 0
10v
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE49FD
P 1600 6650
F 0 "#FLG?" H 1600 6745 30  0001 C CNN
F 1 "PWR_FLAG" H 1600 6830 30  0000 C CNN
	1    1600 6650
	-1   0    0    -1  
$EndComp
$Comp
L VDD #PWR?
U 1 1 4FDE49FC
P 2400 6600
F 0 "#PWR?" H 2400 6700 30  0001 C CNN
F 1 "VDD" H 2400 6710 30  0000 C CNN
	1    2400 6600
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG?
U 1 1 4FDE49FB
P 2200 6600
F 0 "#FLG?" H 2200 6695 30  0001 C CNN
F 1 "PWR_FLAG" H 2200 6780 30  0000 C CNN
	1    2200 6600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1800 6800 1800 6650
Wire Wire Line
	1600 6800 1800 6800
Wire Wire Line
	1600 6650 1600 6800
Wire Wire Line
	2850 5100 2850 5000
Wire Wire Line
	3700 5100 2850 5100
Wire Wire Line
	3700 4050 3350 4050
Wire Wire Line
	3700 3850 3350 3850
Wire Wire Line
	3700 3650 3350 3650
Wire Wire Line
	3700 3450 3350 3450
Wire Wire Line
	3700 3250 3350 3250
Wire Wire Line
	3700 3050 3350 3050
Wire Wire Line
	3700 2850 3350 2850
Wire Wire Line
	3700 2650 3350 2650
Wire Wire Line
	3700 2450 3350 2450
Wire Wire Line
	3700 2250 3350 2250
Connection ~ 3500 4600
Wire Wire Line
	3500 4700 3500 4500
Connection ~ 3500 5100
Wire Wire Line
	3500 5000 3500 5200
Wire Wire Line
	3700 5000 3500 5000
Wire Wire Line
	3700 4700 3500 4700
Wire Wire Line
	3200 4600 3700 4600
Wire Wire Line
	3200 4500 3200 4600
Wire Wire Line
	3700 2150 3350 2150
Wire Wire Line
	3700 2350 3350 2350
Wire Wire Line
	3700 2550 3350 2550
Wire Wire Line
	3700 2750 3350 2750
Wire Wire Line
	3700 2950 3350 2950
Wire Wire Line
	3700 3150 3350 3150
Wire Wire Line
	3700 3350 3350 3350
Wire Wire Line
	3700 3550 3350 3550
Wire Wire Line
	3700 3750 3350 3750
Wire Wire Line
	3700 3950 3350 3950
Wire Wire Line
	3700 4800 3450 4800
Wire Wire Line
	3050 4900 3700 4900
Wire Wire Line
	3050 4800 3050 4900
Wire Wire Line
	2200 6800 2200 6600
Wire Wire Line
	2400 6800 2200 6800
Wire Wire Line
	2400 6600 2400 6800
$EndSCHEMATC
