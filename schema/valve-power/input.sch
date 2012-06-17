EESchema Schematic File Version 2  date Mon 18 Jun 2012 12:08:36 AM MSK
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
LIBS:con-usb
LIBS:con-usb-2
LIBS:con-usb-3
LIBS:mc34152
LIBS:my_comps
LIBS:ncp3063
LIBS:sdc
LIBS:stm
LIBS:usb
LIBS:valve-power-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 5 17
Title ""
Date "17 jun 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VDD #PWR031
U 1 1 4FDB399C
P 5800 2050
AR Path="/4FDC7DE6/4FDB399C" Ref="#PWR031"  Part="1" 
AR Path="/4FDC7DE5/4FDB399C" Ref="#PWR034"  Part="1" 
AR Path="/4FDC7DE4/4FDB399C" Ref="#PWR037"  Part="1" 
AR Path="/4FDC7DE3/4FDB399C" Ref="#PWR040"  Part="1" 
AR Path="/4FDC7DB7/4FDB399C" Ref="#PWR043"  Part="1" 
AR Path="/4FDC7DB6/4FDB399C" Ref="#PWR046"  Part="1" 
AR Path="/4FDC7DB5/4FDB399C" Ref="#PWR049"  Part="1" 
AR Path="/4FDC7DB4/4FDB399C" Ref="#PWR052"  Part="1" 
AR Path="/4FDB299D/4FDB399C" Ref="#PWR073"  Part="1" 
AR Path="/4FDB3921/4FDB399C" Ref="#PWR076"  Part="1" 
AR Path="/4FDB3935/4FDB399C" Ref="#PWR079"  Part="1" 
AR Path="/4FDB3936/4FDB399C" Ref="#PWR082"  Part="1" 
F 0 "#PWR082" H 5800 2150 30  0001 C CNN
F 1 "VDD" H 5800 2160 30  0000 C CNN
	1    5800 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2300 5800 2050
Connection ~ 5800 3250
Wire Wire Line
	5800 3250 6250 3250
Wire Wire Line
	4600 4500 4600 4700
Connection ~ 4600 3600
Wire Wire Line
	3900 3600 4800 3600
Wire Wire Line
	5300 3600 5500 3600
Wire Wire Line
	4600 3600 4600 4000
Wire Wire Line
	5800 3800 5800 4550
Wire Wire Line
	5800 3400 5800 2800
Wire Wire Line
	6750 3250 7150 3250
$Comp
L R R13
U 1 1 4FDB2AE7
P 5800 2550
AR Path="/4FDC7DE6/4FDB2AE7" Ref="R13"  Part="1" 
AR Path="/4FDC7DE5/4FDB2AE7" Ref="R17"  Part="1" 
AR Path="/4FDC7DE4/4FDB2AE7" Ref="R21"  Part="1" 
AR Path="/4FDC7DE3/4FDB2AE7" Ref="R25"  Part="1" 
AR Path="/4FDC7DB7/4FDB2AE7" Ref="R29"  Part="1" 
AR Path="/4FDC7DB6/4FDB2AE7" Ref="R33"  Part="1" 
AR Path="/4FDC7DB5/4FDB2AE7" Ref="R37"  Part="1" 
AR Path="/4FDC7DB4/4FDB2AE7" Ref="R41"  Part="1" 
AR Path="/4FDB299D/4FDB2AE7" Ref="R61"  Part="1" 
AR Path="/4FDB3921/4FDB2AE7" Ref="R65"  Part="1" 
AR Path="/4FDB3935/4FDB2AE7" Ref="R69"  Part="1" 
AR Path="/4FDB3936/4FDB2AE7" Ref="R73"  Part="1" 
F 0 "R73" V 5880 2550 50  0000 C CNN
F 1 "33k" V 5800 2550 50  0000 C CNN
	1    5800 2550
	1    0    0    -1  
$EndComp
Text HLabel 7150 3250 2    60   Input ~ 0
out
$Comp
L R R14
U 1 1 4FDB2AA4
P 6500 3250
AR Path="/4FDC7DE6/4FDB2AA4" Ref="R14"  Part="1" 
AR Path="/4FDC7DE5/4FDB2AA4" Ref="R18"  Part="1" 
AR Path="/4FDC7DE4/4FDB2AA4" Ref="R22"  Part="1" 
AR Path="/4FDC7DE3/4FDB2AA4" Ref="R26"  Part="1" 
AR Path="/4FDC7DB7/4FDB2AA4" Ref="R30"  Part="1" 
AR Path="/4FDC7DB6/4FDB2AA4" Ref="R34"  Part="1" 
AR Path="/4FDC7DB5/4FDB2AA4" Ref="R38"  Part="1" 
AR Path="/4FDC7DB4/4FDB2AA4" Ref="R42"  Part="1" 
AR Path="/4FDB299D/4FDB2AA4" Ref="R62"  Part="1" 
AR Path="/4FDB3921/4FDB2AA4" Ref="R66"  Part="1" 
AR Path="/4FDB3935/4FDB2AA4" Ref="R70"  Part="1" 
AR Path="/4FDB3936/4FDB2AA4" Ref="R74"  Part="1" 
F 0 "R74" V 6580 3250 50  0000 C CNN
F 1 "2k4" V 6500 3250 50  0000 C CNN
	1    6500 3250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR032
U 1 1 4FDB2A6B
P 4600 4700
AR Path="/4FDC7DE6/4FDB2A6B" Ref="#PWR032"  Part="1" 
AR Path="/4FDC7DE5/4FDB2A6B" Ref="#PWR035"  Part="1" 
AR Path="/4FDC7DE4/4FDB2A6B" Ref="#PWR038"  Part="1" 
AR Path="/4FDC7DE3/4FDB2A6B" Ref="#PWR041"  Part="1" 
AR Path="/4FDC7DB7/4FDB2A6B" Ref="#PWR044"  Part="1" 
AR Path="/4FDC7DB6/4FDB2A6B" Ref="#PWR047"  Part="1" 
AR Path="/4FDC7DB5/4FDB2A6B" Ref="#PWR050"  Part="1" 
AR Path="/4FDC7DB4/4FDB2A6B" Ref="#PWR053"  Part="1" 
AR Path="/4FDB299D/4FDB2A6B" Ref="#PWR074"  Part="1" 
AR Path="/4FDB3921/4FDB2A6B" Ref="#PWR077"  Part="1" 
AR Path="/4FDB3935/4FDB2A6B" Ref="#PWR080"  Part="1" 
AR Path="/4FDB3936/4FDB2A6B" Ref="#PWR083"  Part="1" 
F 0 "#PWR083" H 4600 4700 30  0001 C CNN
F 1 "GND" H 4600 4630 30  0001 C CNN
	1    4600 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR033
U 1 1 4FDB2A62
P 5800 4550
AR Path="/4FDC7DE6/4FDB2A62" Ref="#PWR033"  Part="1" 
AR Path="/4FDC7DE5/4FDB2A62" Ref="#PWR036"  Part="1" 
AR Path="/4FDC7DE4/4FDB2A62" Ref="#PWR039"  Part="1" 
AR Path="/4FDC7DE3/4FDB2A62" Ref="#PWR042"  Part="1" 
AR Path="/4FDC7DB7/4FDB2A62" Ref="#PWR045"  Part="1" 
AR Path="/4FDC7DB6/4FDB2A62" Ref="#PWR048"  Part="1" 
AR Path="/4FDC7DB5/4FDB2A62" Ref="#PWR051"  Part="1" 
AR Path="/4FDC7DB4/4FDB2A62" Ref="#PWR054"  Part="1" 
AR Path="/4FDB299D/4FDB2A62" Ref="#PWR075"  Part="1" 
AR Path="/4FDB3921/4FDB2A62" Ref="#PWR078"  Part="1" 
AR Path="/4FDB3935/4FDB2A62" Ref="#PWR081"  Part="1" 
AR Path="/4FDB3936/4FDB2A62" Ref="#PWR084"  Part="1" 
F 0 "#PWR084" H 5800 4550 30  0001 C CNN
F 1 "GND" H 5800 4480 30  0001 C CNN
	1    5800 4550
	1    0    0    -1  
$EndComp
Text HLabel 3900 3600 0    60   Input ~ 0
in-24v
$Comp
L R R12
U 1 1 4FDB29FE
P 5050 3600
AR Path="/4FDC7DE6/4FDB29FE" Ref="R12"  Part="1" 
AR Path="/4FDC7DE5/4FDB29FE" Ref="R16"  Part="1" 
AR Path="/4FDC7DE4/4FDB29FE" Ref="R20"  Part="1" 
AR Path="/4FDC7DE3/4FDB29FE" Ref="R24"  Part="1" 
AR Path="/4FDC7DB7/4FDB29FE" Ref="R28"  Part="1" 
AR Path="/4FDC7DB6/4FDB29FE" Ref="R32"  Part="1" 
AR Path="/4FDC7DB5/4FDB29FE" Ref="R36"  Part="1" 
AR Path="/4FDC7DB4/4FDB29FE" Ref="R40"  Part="1" 
AR Path="/4FDB299D/4FDB29FE" Ref="R60"  Part="1" 
AR Path="/4FDB3921/4FDB29FE" Ref="R64"  Part="1" 
AR Path="/4FDB3935/4FDB29FE" Ref="R68"  Part="1" 
AR Path="/4FDB3936/4FDB29FE" Ref="R72"  Part="1" 
F 0 "R72" V 5130 3600 50  0000 C CNN
F 1 "2k4" V 5050 3600 50  0000 C CNN
	1    5050 3600
	0    -1   -1   0   
$EndComp
$Comp
L R R11
U 1 1 4FDB29E5
P 4600 4250
AR Path="/4FDC7DE6/4FDB29E5" Ref="R11"  Part="1" 
AR Path="/4FDC7DE5/4FDB29E5" Ref="R15"  Part="1" 
AR Path="/4FDC7DE4/4FDB29E5" Ref="R19"  Part="1" 
AR Path="/4FDC7DE3/4FDB29E5" Ref="R23"  Part="1" 
AR Path="/4FDC7DB7/4FDB29E5" Ref="R27"  Part="1" 
AR Path="/4FDC7DB6/4FDB29E5" Ref="R31"  Part="1" 
AR Path="/4FDC7DB5/4FDB29E5" Ref="R35"  Part="1" 
AR Path="/4FDC7DB4/4FDB29E5" Ref="R39"  Part="1" 
AR Path="/4FDB299D/4FDB29E5" Ref="R59"  Part="1" 
AR Path="/4FDB3921/4FDB29E5" Ref="R63"  Part="1" 
AR Path="/4FDB3935/4FDB29E5" Ref="R67"  Part="1" 
AR Path="/4FDB3936/4FDB29E5" Ref="R71"  Part="1" 
F 0 "R71" V 4680 4250 50  0000 C CNN
F 1 "33k" V 4600 4250 50  0000 C CNN
	1    4600 4250
	1    0    0    -1  
$EndComp
$Comp
L NPN Q1
U 1 1 4FDB29D2
P 5700 3600
AR Path="/4FDC7DE6/4FDB29D2" Ref="Q1"  Part="1" 
AR Path="/4FDC7DE5/4FDB29D2" Ref="Q2"  Part="1" 
AR Path="/4FDC7DE4/4FDB29D2" Ref="Q3"  Part="1" 
AR Path="/4FDC7DE3/4FDB29D2" Ref="Q4"  Part="1" 
AR Path="/4FDC7DB7/4FDB29D2" Ref="Q5"  Part="1" 
AR Path="/4FDC7DB6/4FDB29D2" Ref="Q6"  Part="1" 
AR Path="/4FDC7DB5/4FDB29D2" Ref="Q7"  Part="1" 
AR Path="/4FDC7DB4/4FDB29D2" Ref="Q8"  Part="1" 
AR Path="/4FDB299D/4FDB29D2" Ref="Q17"  Part="1" 
AR Path="/4FDB3921/4FDB29D2" Ref="Q18"  Part="1" 
AR Path="/4FDB3935/4FDB29D2" Ref="Q19"  Part="1" 
AR Path="/4FDB3936/4FDB29D2" Ref="Q20"  Part="1" 
F 0 "Q20" H 5700 3450 50  0000 R CNN
F 1 "bc847" H 5700 3750 50  0000 R CNN
	1    5700 3600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
