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
Text HLabel 8600 4000 2    60   Input ~ 0
out
Connection ~ 7900 4000
Wire Wire Line
	8600 4000 7900 4000
Wire Wire Line
	7900 3700 7900 4300
Wire Wire Line
	7900 3300 7900 2400
Connection ~ 7300 3500
Wire Wire Line
	7300 3500 7300 3200
Wire Wire Line
	6400 3500 6100 3500
Wire Wire Line
	4700 4100 4700 3900
Wire Wire Line
	4700 3900 4900 3900
Wire Wire Line
	4900 3500 3900 3500
Wire Wire Line
	4700 4600 4700 4850
Wire Wire Line
	6100 3900 6400 3900
Wire Wire Line
	6900 3500 7600 3500
Wire Wire Line
	7300 2700 7300 2400
Wire Wire Line
	6400 3900 6400 4600
Wire Wire Line
	7900 4800 7900 5100
$Comp
L GND #PWR12
U 1 1 4F79F12A
P 7900 5100
AR Path="/4F79FC54/4F79F12A" Ref="#PWR12"  Part="1" 
AR Path="/4F79FC56/4F79F12A" Ref="#PWR4"  Part="1" 
AR Path="/4F79FC55/4F79F12A" Ref="#PWR8"  Part="1" 
AR Path="/4F79FC53/4F79F12A" Ref="#PWR16"  Part="1" 
AR Path="/4F79FC48/4F79F12A" Ref="#PWR20"  Part="1" 
AR Path="/4F79FC47/4F79F12A" Ref="#PWR24"  Part="1" 
AR Path="/4F79FC32/4F79F12A" Ref="#PWR28"  Part="1" 
AR Path="/4F79EEDB/4F79F12A" Ref="#PWR67"  Part="1" 
F 0 "#PWR12" H 7900 5100 30  0001 C CNN
F 1 "GND" H 7900 5030 30  0001 C CNN
	1    7900 5100
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 4F79F111
P 7900 4550
AR Path="/4F79FC54/4F79F111" Ref="R12"  Part="1" 
AR Path="/4F79FC56/4F79F111" Ref="R4"  Part="1" 
AR Path="/4F79FC55/4F79F111" Ref="R8"  Part="1" 
AR Path="/4F79FC53/4F79F111" Ref="R16"  Part="1" 
AR Path="/4F79FC48/4F79F111" Ref="R20"  Part="1" 
AR Path="/4F79FC47/4F79F111" Ref="R24"  Part="1" 
AR Path="/4F79FC32/4F79F111" Ref="R28"  Part="1" 
AR Path="/4F79EEDB/4F79F111" Ref="R91"  Part="1" 
F 0 "R12" V 7980 4550 50  0000 C CNN
F 1 "10k" V 7900 4550 50  0000 C CNN
	1    7900 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 4F79F0F0
P 6400 4600
AR Path="/4F79FC54/4F79F0F0" Ref="#PWR11"  Part="1" 
AR Path="/4F79FC56/4F79F0F0" Ref="#PWR3"  Part="1" 
AR Path="/4F79FC55/4F79F0F0" Ref="#PWR7"  Part="1" 
AR Path="/4F79FC53/4F79F0F0" Ref="#PWR15"  Part="1" 
AR Path="/4F79FC48/4F79F0F0" Ref="#PWR19"  Part="1" 
AR Path="/4F79FC47/4F79F0F0" Ref="#PWR23"  Part="1" 
AR Path="/4F79FC32/4F79F0F0" Ref="#PWR27"  Part="1" 
AR Path="/4F79EEDB/4F79F0F0" Ref="#PWR66"  Part="1" 
F 0 "#PWR11" H 6400 4600 30  0001 C CNN
F 1 "GND" H 6400 4530 30  0001 C CNN
	1    6400 4600
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR10
U 1 1 4F79F0DB
P 7900 2400
AR Path="/4F79FC54/4F79F0DB" Ref="#PWR10"  Part="1" 
AR Path="/4F79FC56/4F79F0DB" Ref="#PWR2"  Part="1" 
AR Path="/4F79FC55/4F79F0DB" Ref="#PWR6"  Part="1" 
AR Path="/4F79FC53/4F79F0DB" Ref="#PWR14"  Part="1" 
AR Path="/4F79FC48/4F79F0DB" Ref="#PWR18"  Part="1" 
AR Path="/4F79FC47/4F79F0DB" Ref="#PWR22"  Part="1" 
AR Path="/4F79FC32/4F79F0DB" Ref="#PWR26"  Part="1" 
AR Path="/4F79EEDB/4F79F0DB" Ref="#PWR65"  Part="1" 
F 0 "#PWR10" H 7900 2500 30  0001 C CNN
F 1 "VCC" H 7900 2500 30  0000 C CNN
	1    7900 2400
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR9
U 1 1 4F79F0CE
P 7300 2400
AR Path="/4F79FC54/4F79F0CE" Ref="#PWR9"  Part="1" 
AR Path="/4F79FC56/4F79F0CE" Ref="#PWR1"  Part="1" 
AR Path="/4F79FC55/4F79F0CE" Ref="#PWR5"  Part="1" 
AR Path="/4F79FC53/4F79F0CE" Ref="#PWR13"  Part="1" 
AR Path="/4F79FC48/4F79F0CE" Ref="#PWR17"  Part="1" 
AR Path="/4F79FC47/4F79F0CE" Ref="#PWR21"  Part="1" 
AR Path="/4F79FC32/4F79F0CE" Ref="#PWR25"  Part="1" 
AR Path="/4F79EEDB/4F79F0CE" Ref="#PWR64"  Part="1" 
F 0 "#PWR9" H 7300 2500 30  0001 C CNN
F 1 "VCC" H 7300 2500 30  0000 C CNN
	1    7300 2400
	1    0    0    -1  
$EndComp
$Comp
L PNP Q3
U 1 1 4F79F09F
P 7800 3500
AR Path="/4F79FC54/4F79F09F" Ref="Q3"  Part="1" 
AR Path="/4F79FC56/4F79F09F" Ref="Q1"  Part="1" 
AR Path="/4F79FC55/4F79F09F" Ref="Q2"  Part="1" 
AR Path="/4F79FC53/4F79F09F" Ref="Q4"  Part="1" 
AR Path="/4F79FC48/4F79F09F" Ref="Q5"  Part="1" 
AR Path="/4F79FC47/4F79F09F" Ref="Q6"  Part="1" 
AR Path="/4F79FC32/4F79F09F" Ref="Q7"  Part="1" 
AR Path="/4F79EEDB/4F79F09F" Ref="Q30"  Part="1" 
F 0 "Q3" H 7800 3350 60  0000 R CNN
F 1 "bc857" H 7800 3650 60  0000 R CNN
	1    7800 3500
	1    0    0    1   
$EndComp
$Comp
L R R9
U 1 1 4F79EFBA
P 7300 2950
AR Path="/4F79FC54/4F79EFBA" Ref="R9"  Part="1" 
AR Path="/4F79FC56/4F79EFBA" Ref="R1"  Part="1" 
AR Path="/4F79FC55/4F79EFBA" Ref="R5"  Part="1" 
AR Path="/4F79FC53/4F79EFBA" Ref="R13"  Part="1" 
AR Path="/4F79FC48/4F79EFBA" Ref="R17"  Part="1" 
AR Path="/4F79FC47/4F79EFBA" Ref="R21"  Part="1" 
AR Path="/4F79FC32/4F79EFBA" Ref="R25"  Part="1" 
AR Path="/4F79EEDB/4F79EFBA" Ref="R88"  Part="1" 
F 0 "R9" V 7380 2950 50  0000 C CNN
F 1 "10k" V 7300 2950 50  0000 C CNN
	1    7300 2950
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 4F79EFB2
P 6650 3500
AR Path="/4F79FC54/4F79EFB2" Ref="R10"  Part="1" 
AR Path="/4F79FC56/4F79EFB2" Ref="R2"  Part="1" 
AR Path="/4F79FC55/4F79EFB2" Ref="R6"  Part="1" 
AR Path="/4F79FC53/4F79EFB2" Ref="R14"  Part="1" 
AR Path="/4F79FC48/4F79EFB2" Ref="R18"  Part="1" 
AR Path="/4F79FC47/4F79EFB2" Ref="R22"  Part="1" 
AR Path="/4F79FC32/4F79EFB2" Ref="R26"  Part="1" 
AR Path="/4F79EEDB/4F79EFB2" Ref="R89"  Part="1" 
F 0 "R10" V 6730 3500 50  0000 C CNN
F 1 "1k" V 6650 3500 50  0000 C CNN
	1    6650 3500
	0    -1   -1   0   
$EndComp
Text GLabel 4700 4850 3    60   Input ~ 0
gnd-24v
$Comp
L R R11
U 1 1 4F79EF52
P 4700 4350
AR Path="/4F79FC54/4F79EF52" Ref="R11"  Part="1" 
AR Path="/4F79FC56/4F79EF52" Ref="R3"  Part="1" 
AR Path="/4F79FC55/4F79EF52" Ref="R7"  Part="1" 
AR Path="/4F79FC53/4F79EF52" Ref="R15"  Part="1" 
AR Path="/4F79FC48/4F79EF52" Ref="R19"  Part="1" 
AR Path="/4F79FC47/4F79EF52" Ref="R23"  Part="1" 
AR Path="/4F79FC32/4F79EF52" Ref="R27"  Part="1" 
AR Path="/4F79EEDB/4F79EF52" Ref="R90"  Part="1" 
F 0 "R11" V 4780 4350 50  0000 C CNN
F 1 "1k5" V 4700 4350 50  0000 C CNN
	1    4700 4350
	1    0    0    -1  
$EndComp
Text HLabel 3900 3500 0    60   Input ~ 0
in
$Comp
L PHDARL U3
U 1 1 4F79EF18
P 5500 3700
AR Path="/4F79FC54/4F79EF18" Ref="U3"  Part="1" 
AR Path="/4F79FC56/4F79EF18" Ref="U1"  Part="1" 
AR Path="/4F79FC55/4F79EF18" Ref="U2"  Part="1" 
AR Path="/4F79FC53/4F79EF18" Ref="U4"  Part="1" 
AR Path="/4F79FC48/4F79EF18" Ref="U5"  Part="1" 
AR Path="/4F79FC47/4F79EF18" Ref="U6"  Part="1" 
AR Path="/4F79FC32/4F79EF18" Ref="U7"  Part="1" 
AR Path="/4F79EEDB/4F79EF18" Ref="U18"  Part="1" 
F 0 "U3" H 5510 4020 70  0000 C CNN
F 1 "PHDARL" H 5510 3380 70  0000 C CNN
	1    5500 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
