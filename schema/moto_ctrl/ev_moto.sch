EESchema Schematic File Version 2  date Sat 10 Nov 2012 12:30:00 PM MSK
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
LIBS:74hc164
LIBS:74hc165
LIBS:camozzi
LIBS:con-usb
LIBS:con-usb-2
LIBS:con-usb-3
LIBS:d-sub-37
LIBS:lsm303dlh
LIBS:mc34152
LIBS:my_comps
LIBS:ncp3063
LIBS:sdc
LIBS:stm
LIBS:usb
LIBS:lsm303dlhc
LIBS:stm3485ebdr
LIBS:moto_ctrl-cache
EELAYER 25  0
EELAYER END
$Descr A2 23400 16535
encoding utf-8
Sheet 2 2
Title ""
Date "10 nov 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM3485EBDR rs?
U 1 1 509E1075
P 20250 4900
F 0 "rs?" H 20250 4750 60  0000 C CNN
F 1 "STM3485EBDR" H 20250 5050 60  0000 C CNN
	1    20250 4900
	1    0    0    -1  
$EndComp
$Comp
L STM3485EBDR rs485?
U 1 1 509E106E
P 20250 3100
F 0 "rs485?" H 20250 2950 60  0000 C CNN
F 1 "STM3485EBDR" H 20250 3250 60  0000 C CNN
	1    20250 3100
	1    0    0    -1  
$EndComp
NoConn ~ 19900 1600
NoConn ~ 19900 1400
NoConn ~ 20700 1700
NoConn ~ 20700 1500
Text Label 20750 1800 0    60   ~ 0
data+
Wire Wire Line
	20700 1800 21000 1800
Wire Wire Line
	19900 1800 19550 1800
Wire Wire Line
	19350 1600 19350 1500
Wire Wire Line
	19350 1500 19900 1500
Wire Wire Line
	19900 1300 19550 1300
Wire Wire Line
	14800 1250 14800 1150
Wire Wire Line
	14300 1150 14300 1350
Wire Wire Line
	14300 1350 13900 1350
Wire Wire Line
	2100 14700 1300 14700
Wire Wire Line
	2100 14300 1300 14300
Wire Wire Line
	2100 13900 1300 13900
Wire Wire Line
	1300 13500 1700 13500
Wire Wire Line
	1300 12700 1700 12700
Wire Wire Line
	8250 10200 8800 10200
Wire Wire Line
	8250 10400 8800 10400
Wire Wire Line
	8250 9600 9100 9600
Wire Wire Line
	8250 9400 9100 9400
Wire Wire Line
	8250 3500 9100 3500
Wire Wire Line
	8250 3200 9100 3200
Wire Wire Line
	8250 9000 9100 9000
Wire Wire Line
	8250 9200 9100 9200
Wire Wire Line
	8250 8050 9100 8050
Wire Wire Line
	8250 7850 9100 7850
Wire Wire Line
	8250 5100 9100 5100
Wire Wire Line
	8250 4500 9100 4500
Wire Wire Line
	8250 4700 9100 4700
Wire Wire Line
	8250 4900 9100 4900
Wire Wire Line
	8250 4300 9100 4300
Wire Wire Line
	8250 3900 9100 3900
Wire Wire Line
	2950 8700 2950 8850
Wire Wire Line
	3150 8700 3150 8500
Wire Wire Line
	9500 2350 7550 2350
Wire Wire Line
	9500 2350 9500 2200
Connection ~ 8350 2350
Wire Wire Line
	8350 2500 8350 2200
Wire Wire Line
	7550 2350 7550 2200
Connection ~ 7550 1650
Wire Wire Line
	7950 1650 7950 1800
Connection ~ 5650 1650
Connection ~ 2850 5900
Wire Wire Line
	3000 5900 2650 5900
Wire Wire Line
	8250 8400 8900 8400
Wire Wire Line
	8250 10000 9350 10000
Wire Wire Line
	8250 8600 8900 8600
Wire Wire Line
	8250 5300 9150 5300
Connection ~ 5650 2100
Wire Wire Line
	5650 2100 5650 1500
Connection ~ 2150 5900
Wire Wire Line
	2150 6050 2150 5200
Connection ~ 2850 5200
Wire Wire Line
	2850 5250 2850 5200
Wire Wire Line
	2950 8100 2950 8200
Wire Wire Line
	2600 4550 2600 4400
Wire Wire Line
	2600 4400 2850 4400
Wire Wire Line
	3450 4400 3450 4200
Wire Wire Line
	8250 6500 8950 6500
Wire Wire Line
	8250 5700 8950 5700
Wire Wire Line
	4150 2400 4150 2100
Connection ~ 5950 2100
Wire Wire Line
	5950 2400 5950 2100
Connection ~ 5350 11500
Wire Wire Line
	4150 11500 6550 11500
Wire Wire Line
	4150 11500 4150 11300
Connection ~ 5950 11500
Wire Wire Line
	5350 11500 5350 11300
Wire Wire Line
	6550 11500 6550 11300
Wire Wire Line
	5950 11700 5950 11300
Wire Wire Line
	4850 2400 4850 2100
Wire Wire Line
	4850 2100 6550 2100
Wire Wire Line
	6550 2100 6550 2400
Wire Wire Line
	5350 2400 5350 2100
Connection ~ 5350 2100
Wire Wire Line
	8250 5900 8950 5900
Wire Wire Line
	8250 6700 8950 6700
Wire Wire Line
	3250 4400 3650 4400
Connection ~ 3450 4400
Wire Wire Line
	3450 3700 3450 3450
Wire Wire Line
	2650 5200 3650 5200
Wire Wire Line
	2850 5900 2850 5850
Wire Wire Line
	2150 5200 2250 5200
Wire Wire Line
	2150 5900 2250 5900
Wire Wire Line
	8250 5500 9150 5500
Wire Wire Line
	8250 8800 8900 8800
Wire Wire Line
	8250 9800 9350 9800
Wire Wire Line
	3150 8500 3650 8500
Wire Wire Line
	3500 5900 3650 5900
Wire Wire Line
	7550 1650 7550 1800
Wire Wire Line
	8350 1650 8350 1800
Connection ~ 7950 1650
Wire Wire Line
	7950 2350 7950 2200
Connection ~ 7950 2350
Wire Wire Line
	9500 1800 9500 1650
Wire Wire Line
	9500 1650 5650 1650
Connection ~ 8350 1650
Wire Wire Line
	3150 9200 3150 9350
Wire Wire Line
	2450 8100 3650 8100
Connection ~ 2950 8100
Wire Wire Line
	8250 3700 9100 3700
Wire Wire Line
	8250 4100 9100 4100
Wire Wire Line
	3650 6800 3000 6800
Wire Wire Line
	3650 7500 3000 7500
Wire Wire Line
	1300 13100 1700 13100
Wire Wire Line
	1300 15100 2100 15100
Wire Wire Line
	13900 1550 14300 1550
Wire Wire Line
	14300 1550 14300 1750
Wire Wire Line
	14800 1650 14800 1750
Wire Wire Line
	20700 1300 21000 1300
Wire Wire Line
	19900 1700 19550 1700
Wire Wire Line
	20700 1400 21000 1400
Wire Wire Line
	20700 1600 21200 1600
Wire Wire Line
	21200 1600 21200 1700
$Comp
L GND #PWR?
U 1 1 509E0B63
P 21200 1700
F 0 "#PWR?" H 21200 1700 30  0001 C CNN
F 1 "GND" H 21200 1630 30  0001 C CNN
	1    21200 1700
	1    0    0    -1  
$EndComp
Text Label 20750 1400 0    60   ~ 0
clock+
$Comp
L +5V #PWR?
U 1 1 509E0B3C
P 19550 1800
F 0 "#PWR?" H 19550 1890 20  0001 C CNN
F 1 "+5V" H 19550 1890 30  0000 C CNN
	1    19550 1800
	0    -1   -1   0   
$EndComp
Text Label 19600 1700 0    60   ~ 0
clock-
$Comp
L GND #PWR?
U 1 1 509E0B23
P 19350 1600
F 0 "#PWR?" H 19350 1600 30  0001 C CNN
F 1 "GND" H 19350 1530 30  0001 C CNN
	1    19350 1600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 509E0B0F
P 21000 1300
F 0 "#PWR?" H 21000 1390 20  0001 C CNN
F 1 "+5V" H 21000 1390 30  0000 C CNN
	1    21000 1300
	0    1    1    0   
$EndComp
Text Label 19600 1300 0    60   ~ 0
data-
Text Notes 19700 1100 0    60   ~ 0
Encoder connection socket
$Comp
L CONN_6X2 P?
U 1 1 509DDF04
P 20300 1550
F 0 "P?" H 20300 1900 60  0000 C CNN
F 1 "CONN_6X2" V 20300 1550 60  0000 C CNN
	1    20300 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 509DDED8
P 14800 1750
F 0 "#PWR?" H 14800 1750 30  0001 C CNN
F 1 "GND" H 14800 1680 30  0001 C CNN
	1    14800 1750
	1    0    0    -1  
$EndComp
$Comp
L +24V #PWR?
U 1 1 509DDED0
P 14800 1150
F 0 "#PWR?" H 14800 1100 20  0001 C CNN
F 1 "+24V" H 14800 1250 30  0000 C CNN
	1    14800 1150
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 509DDEBC
P 14800 1450
F 0 "C?" H 14850 1550 50  0000 L CNN
F 1 "CP1" H 14850 1350 50  0000 L CNN
	1    14800 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 509DDE9A
P 14300 1750
F 0 "#PWR?" H 14300 1750 30  0001 C CNN
F 1 "GND" H 14300 1680 30  0001 C CNN
	1    14300 1750
	1    0    0    -1  
$EndComp
$Comp
L +24V #PWR?
U 1 1 509DDE8E
P 14300 1150
F 0 "#PWR?" H 14300 1100 20  0001 C CNN
F 1 "+24V" H 14300 1250 30  0000 C CNN
	1    14300 1150
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 509DDE7A
P 13550 1450
F 0 "P?" V 13500 1450 40  0000 C CNN
F 1 "CONN_2" V 13600 1450 40  0000 C CNN
	1    13550 1450
	-1   0    0    -1  
$EndComp
Text Label 1700 15100 0    60   ~ 0
fw-upgrade
Text HLabel 1300 15100 0    60   Input ~ 0
fw-upgrade
Text Label 1700 14700 0    60   ~ 0
synch-ext
Text HLabel 1300 14700 0    60   Input ~ 0
synch-ext
Text HLabel 1300 14300 0    60   Input ~ 0
sda-ext
Text Label 1700 14300 0    60   ~ 0
sda-ext
Text Label 1700 13900 0    60   ~ 0
scl-ext
Text HLabel 1300 13900 0    60   Input ~ 0
scl-ext
$Comp
L GND #PWR?
U 1 1 509DDD56
P 1700 13500
F 0 "#PWR?" H 1700 13500 30  0001 C CNN
F 1 "GND" H 1700 13430 30  0001 C CNN
	1    1700 13500
	0    -1   -1   0   
$EndComp
Text HLabel 1300 13500 0    60   Input ~ 0
gnd
$Comp
L +24V #PWR?
U 1 1 509DDC7D
P 1700 13100
F 0 "#PWR?" H 1700 13050 20  0001 C CNN
F 1 "+24V" H 1700 13200 30  0000 C CNN
	1    1700 13100
	0    1    1    0   
$EndComp
Text HLabel 1300 13100 0    60   Input ~ 0
+24v
$Comp
L VDD #PWR?
U 1 1 509DDC59
P 1700 12700
F 0 "#PWR?" H 1700 12800 30  0001 C CNN
F 1 "VDD" H 1700 12810 30  0000 C CNN
	1    1700 12700
	0    1    1    0   
$EndComp
Text HLabel 1300 12700 0    60   Input ~ 0
vdd
NoConn ~ 8250 7300
NoConn ~ 8250 7100
NoConn ~ 8250 6900
Text Label 9050 5500 0    60   ~ 0
rx
Text Label 9050 5300 0    60   ~ 0
tx
Text Label 2550 8100 0    60   ~ 0
fw-upgrade
$Comp
L GND #PWR?
U 1 1 509DDC2F
P 2950 8850
F 0 "#PWR?" H 2950 8850 30  0001 C CNN
F 1 "GND" H 2950 8780 30  0001 C CNN
	1    2950 8850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 509DDC2E
P 2950 8450
F 0 "R?" V 3030 8450 50  0000 C CNN
F 1 "10k" V 2950 8450 50  0000 C CNN
	1    2950 8450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 509DDC2D
P 3150 9350
F 0 "#PWR?" H 3150 9350 30  0001 C CNN
F 1 "GND" H 3150 9280 30  0001 C CNN
	1    3150 9350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 509DDC2C
P 3150 8950
F 0 "R?" V 3230 8950 50  0000 C CNN
F 1 "10k" V 3150 8950 50  0000 C CNN
	1    3150 8950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 509DDC2B
P 8350 2500
F 0 "#PWR?" H 8350 2500 30  0001 C CNN
F 1 "GND" H 8350 2430 30  0001 C CNN
	1    8350 2500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 509DDC2A
P 8350 2000
F 0 "C?" H 8400 2100 50  0000 L CNN
F 1 "100n" H 8400 1900 50  0000 L CNN
	1    8350 2000
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 509DDC29
P 7950 2000
F 0 "C?" H 8000 2100 50  0000 L CNN
F 1 "100n" H 8000 1900 50  0000 L CNN
	1    7950 2000
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 509DDC28
P 7550 2000
F 0 "C?" H 7600 2100 50  0000 L CNN
F 1 "100n" H 7600 1900 50  0000 L CNN
	1    7550 2000
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 509DDC27
P 3250 5900
F 0 "R?" V 3330 5900 50  0000 C CNN
F 1 "50" V 3250 5900 50  0000 C CNN
	1    3250 5900
	0    -1   -1   0   
$EndComp
Text Label 8650 8400 0    60   ~ 0
synch
Text Label 9000 9800 0    60   ~ 0
led2
Text Label 9000 10000 0    60   ~ 0
led1
Text Label 8750 8800 0    60   ~ 0
sda
Text Label 8750 8600 0    60   ~ 0
scl
$Comp
L VDD #PWR?
U 1 1 509DDC26
P 3450 3450
F 0 "#PWR?" H 3450 3550 30  0001 C CNN
F 1 "VDD" H 3450 3560 30  0000 C CNN
	1    3450 3450
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR?
U 1 1 509DDC25
P 4150 2100
F 0 "#PWR?" H 4150 2200 30  0001 C CNN
F 1 "VDD" H 4150 2210 30  0000 C CNN
	1    4150 2100
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR?
U 1 1 509DDC24
P 5650 1500
F 0 "#PWR?" H 5650 1600 30  0001 C CNN
F 1 "VDD" H 5650 1610 30  0000 C CNN
	1    5650 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 509DDC23
P 2150 6050
F 0 "#PWR?" H 2150 6050 30  0001 C CNN
F 1 "GND" H 2150 5980 30  0001 C CNN
	1    2150 6050
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X?
U 1 1 509DDC22
P 2850 5550
F 0 "X?" H 2850 5700 60  0000 C CNN
F 1 "8MHz" H 2850 5400 60  0000 C CNN
	1    2850 5550
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 509DDC21
P 2450 5900
F 0 "C?" H 2500 6000 50  0000 L CNN
F 1 "18p" H 2500 5800 50  0000 L CNN
	1    2450 5900
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 509DDC20
P 2450 5200
F 0 "C?" H 2500 5300 50  0000 L CNN
F 1 "18p" H 2500 5100 50  0000 L CNN
	1    2450 5200
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 509DDC1F
P 2600 4550
F 0 "#PWR?" H 2600 4550 30  0001 C CNN
F 1 "GND" H 2600 4480 30  0001 C CNN
	1    2600 4550
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 509DDC1E
P 3050 4400
F 0 "C?" H 3100 4500 50  0000 L CNN
F 1 "100n" H 3100 4300 50  0000 L CNN
	1    3050 4400
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 509DDC1D
P 3450 3950
F 0 "R?" V 3530 3950 50  0000 C CNN
F 1 "10k" V 3450 3950 50  0000 C CNN
	1    3450 3950
	1    0    0    -1  
$EndComp
Text Label 8600 6700 0    60   ~ 0
swd-clk
Text Label 8600 6500 0    60   ~ 0
swd-io
Text Label 8650 5900 0    60   ~ 0
usb-d+
Text Label 8650 5700 0    60   ~ 0
usb-d-
$Comp
L GND #PWR?
U 1 1 509DDC1C
P 5950 11700
F 0 "#PWR?" H 5950 11700 30  0001 C CNN
F 1 "GND" H 5950 11630 30  0001 C CNN
	1    5950 11700
	1    0    0    -1  
$EndComp
$Comp
L STM32F102C8T6 stm?
U 1 1 509DDC1B
P 5350 6300
F 0 "stm?" H 5350 6100 60  0000 C CNN
F 1 "STM32F102C8T6" H 5350 6500 60  0000 C CNN
	1    5350 6300
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 509DDC1A
P 9500 2000
F 0 "C?" H 9550 2100 50  0000 L CNN
F 1 "10u" H 9550 1900 50  0000 L CNN
	1    9500 2000
	1    0    0    -1  
$EndComp
Text Label 8800 3700 0    60   ~ 0
i-1-1
Text Label 8800 3900 0    60   ~ 0
i-1-2
Text Label 8800 4100 0    60   ~ 0
io-1-1
Text Label 8800 4300 0    60   ~ 0
io-1-2
Text Label 8800 4900 0    60   ~ 0
i-2-2
Text Label 8800 4700 0    60   ~ 0
i-2-1
Text Label 8800 4500 0    60   ~ 0
io-2-1
Text Label 8800 5100 0    60   ~ 0
io-2-2
Text Label 8800 7850 0    60   ~ 0
i-3-1
Text Label 8800 8050 0    60   ~ 0
i-3-2
Text Label 8800 9200 0    60   ~ 0
i-4-2
Text Label 8800 9000 0    60   ~ 0
i-4-1
Text Label 8800 3200 0    60   ~ 0
io-3-1
Text Label 8800 3500 0    60   ~ 0
io-3-2
Text Label 8800 9400 0    60   ~ 0
io-4-1
Text Label 8800 9600 0    60   ~ 0
io-4-2
Text Label 3050 6800 0    60   ~ 0
sensor-1
Text Label 3050 7500 0    60   ~ 0
sensor-2
Text Label 8400 10400 0    60   ~ 0
sensor-3
Text Label 8400 10200 0    60   ~ 0
sensor-4
$EndSCHEMATC
