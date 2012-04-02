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
Sheet 40 45
Title ""
Date "2 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 7800 2700 1    60   Input ~ 0
vcc-24v
Text GLabel 7800 4850 3    60   Input ~ 0
gnd-24v
Wire Wire Line
	7800 4400 7800 4850
Wire Wire Line
	7800 3400 7800 4000
Wire Wire Line
	7900 3700 7450 3700
Wire Wire Line
	7450 3700 7450 4000
Wire Wire Line
	5950 3350 5950 3800
Wire Wire Line
	5950 3800 5800 3800
Wire Wire Line
	6550 4200 7150 4200
Wire Wire Line
	7450 4400 7450 4850
Wire Wire Line
	4600 4200 4450 4200
Wire Wire Line
	4450 4200 4450 4400
Connection ~ 4000 5250
Wire Wire Line
	4000 5400 4000 5250
Wire Wire Line
	4000 5900 4000 6150
Wire Wire Line
	4450 5050 4450 4900
Wire Wire Line
	4450 5450 4450 5750
Wire Wire Line
	3800 5250 4150 5250
Wire Wire Line
	3300 5250 3000 5250
Wire Wire Line
	4600 3800 4450 3800
Wire Wire Line
	4450 3800 4450 3350
Wire Wire Line
	5800 4200 6050 4200
Wire Wire Line
	6900 4500 6900 4200
Connection ~ 6900 4200
Wire Wire Line
	6900 5000 6900 5350
Connection ~ 7800 3700
Wire Wire Line
	7800 3000 7800 2700
$Comp
L DIODE D1
U 1 1 4F79EE31
P 7800 3200
AR Path="/4F79F576/4F79EE31" Ref="D1"  Part="1" 
AR Path="/4F79F575/4F79EE31" Ref="D3"  Part="1" 
AR Path="/4F79F56D/4F79EE31" Ref="D5"  Part="1" 
AR Path="/4F79F56C/4F79EE31" Ref="D7"  Part="1" 
AR Path="/4F79F56B/4F79EE31" Ref="D9"  Part="1" 
AR Path="/4F79F56A/4F79EE31" Ref="D11"  Part="1" 
AR Path="/4F79F55E/4F79EE31" Ref="D13"  Part="1" 
AR Path="/4F79F55D/4F79EE31" Ref="D15"  Part="1" 
AR Path="/4F79F54D/4F79EE31" Ref="D17"  Part="1" 
AR Path="/4F79E923/4F79EE31" Ref="D19"  Part="1" 
F 0 "D17" H 7800 3300 40  0000 C CNN
F 1 "DIODE" H 7800 3100 40  0000 C CNN
	1    7800 3200
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D2
U 1 1 4F79EE29
P 7800 4200
AR Path="/4F79F576/4F79EE29" Ref="D2"  Part="1" 
AR Path="/4F79F575/4F79EE29" Ref="D4"  Part="1" 
AR Path="/4F79F56D/4F79EE29" Ref="D6"  Part="1" 
AR Path="/4F79F56C/4F79EE29" Ref="D8"  Part="1" 
AR Path="/4F79F56B/4F79EE29" Ref="D10"  Part="1" 
AR Path="/4F79F56A/4F79EE29" Ref="D12"  Part="1" 
AR Path="/4F79F55E/4F79EE29" Ref="D14"  Part="1" 
AR Path="/4F79F55D/4F79EE29" Ref="D16"  Part="1" 
AR Path="/4F79F54D/4F79EE29" Ref="D18"  Part="1" 
AR Path="/4F79E923/4F79EE29" Ref="D20"  Part="1" 
F 0 "D18" H 7800 4300 40  0000 C CNN
F 1 "DIODE" H 7800 4100 40  0000 C CNN
	1    7800 4200
	0    -1   -1   0   
$EndComp
Text HLabel 3000 5250 0    60   Input ~ 0
in
Text HLabel 7900 3700 2    60   Input ~ 0
out
$Comp
L VCC #PWR29
U 1 1 4F79ED4B
P 4450 3350
AR Path="/4F79F576/4F79ED4B" Ref="#PWR29"  Part="1" 
AR Path="/4F79F575/4F79ED4B" Ref="#PWR32"  Part="1" 
AR Path="/4F79F56D/4F79ED4B" Ref="#PWR35"  Part="1" 
AR Path="/4F79F56C/4F79ED4B" Ref="#PWR38"  Part="1" 
AR Path="/4F79F56B/4F79ED4B" Ref="#PWR41"  Part="1" 
AR Path="/4F79F56A/4F79ED4B" Ref="#PWR44"  Part="1" 
AR Path="/4F79F55E/4F79ED4B" Ref="#PWR47"  Part="1" 
AR Path="/4F79F55D/4F79ED4B" Ref="#PWR50"  Part="1" 
AR Path="/4F79F54D/4F79ED4B" Ref="#PWR53"  Part="1" 
AR Path="/4F79E923/4F79ED4B" Ref="#PWR56"  Part="1" 
F 0 "#PWR53" H 4450 3450 30  0001 C CNN
F 1 "VCC" H 4450 3450 30  0000 C CNN
	1    4450 3350
	1    0    0    -1  
$EndComp
Text GLabel 6900 5350 3    60   Input ~ 0
gnd-24v
Text GLabel 5950 3350 1    60   Input ~ 0
vcc-24v
$Comp
L R R29
U 1 1 4F79EC92
P 6300 4200
AR Path="/4F79F576/4F79EC92" Ref="R29"  Part="1" 
AR Path="/4F79F575/4F79EC92" Ref="R34"  Part="1" 
AR Path="/4F79F56D/4F79EC92" Ref="R39"  Part="1" 
AR Path="/4F79F56C/4F79EC92" Ref="R44"  Part="1" 
AR Path="/4F79F56B/4F79EC92" Ref="R49"  Part="1" 
AR Path="/4F79F56A/4F79EC92" Ref="R54"  Part="1" 
AR Path="/4F79F55E/4F79EC92" Ref="R59"  Part="1" 
AR Path="/4F79F55D/4F79EC92" Ref="R64"  Part="1" 
AR Path="/4F79F54D/4F79EC92" Ref="R69"  Part="1" 
AR Path="/4F79E923/4F79EC92" Ref="R74"  Part="1" 
F 0 "R69" V 6380 4200 50  0000 C CNN
F 1 "1k" V 6300 4200 50  0000 C CNN
	1    6300 4200
	0    -1   -1   0   
$EndComp
$Comp
L R R31
U 1 1 4F79EC7E
P 6900 4750
AR Path="/4F79F576/4F79EC7E" Ref="R31"  Part="1" 
AR Path="/4F79F575/4F79EC7E" Ref="R36"  Part="1" 
AR Path="/4F79F56D/4F79EC7E" Ref="R41"  Part="1" 
AR Path="/4F79F56C/4F79EC7E" Ref="R46"  Part="1" 
AR Path="/4F79F56B/4F79EC7E" Ref="R51"  Part="1" 
AR Path="/4F79F56A/4F79EC7E" Ref="R56"  Part="1" 
AR Path="/4F79F55E/4F79EC7E" Ref="R61"  Part="1" 
AR Path="/4F79F55D/4F79EC7E" Ref="R66"  Part="1" 
AR Path="/4F79F54D/4F79EC7E" Ref="R71"  Part="1" 
AR Path="/4F79E923/4F79EC7E" Ref="R76"  Part="1" 
F 0 "R71" V 6980 4750 50  0000 C CNN
F 1 "1k" V 6900 4750 50  0000 C CNN
	1    6900 4750
	1    0    0    -1  
$EndComp
Text GLabel 7450 4850 3    60   Input ~ 0
gnd-24v
$Comp
L MOSFET_N Q8
U 1 1 4F79EC1C
P 7350 4200
AR Path="/4F79F576/4F79EC1C" Ref="Q8"  Part="1" 
AR Path="/4F79F575/4F79EC1C" Ref="Q10"  Part="1" 
AR Path="/4F79F56D/4F79EC1C" Ref="Q12"  Part="1" 
AR Path="/4F79F56C/4F79EC1C" Ref="Q14"  Part="1" 
AR Path="/4F79F56B/4F79EC1C" Ref="Q16"  Part="1" 
AR Path="/4F79F56A/4F79EC1C" Ref="Q18"  Part="1" 
AR Path="/4F79F55E/4F79EC1C" Ref="Q20"  Part="1" 
AR Path="/4F79F55D/4F79EC1C" Ref="Q22"  Part="1" 
AR Path="/4F79F54D/4F79EC1C" Ref="Q24"  Part="1" 
AR Path="/4F79E923/4F79EC1C" Ref="Q26"  Part="1" 
F 0 "Q24" H 7360 4370 60  0000 R CNN
F 1 "MOSFET_N" H 7360 4050 60  0000 R CNN
	1    7350 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR31
U 1 1 4F79EBE4
P 4000 6150
AR Path="/4F79F576/4F79EBE4" Ref="#PWR31"  Part="1" 
AR Path="/4F79F575/4F79EBE4" Ref="#PWR34"  Part="1" 
AR Path="/4F79F56D/4F79EBE4" Ref="#PWR37"  Part="1" 
AR Path="/4F79F56C/4F79EBE4" Ref="#PWR40"  Part="1" 
AR Path="/4F79F56B/4F79EBE4" Ref="#PWR43"  Part="1" 
AR Path="/4F79F56A/4F79EBE4" Ref="#PWR46"  Part="1" 
AR Path="/4F79F55E/4F79EBE4" Ref="#PWR49"  Part="1" 
AR Path="/4F79F55D/4F79EBE4" Ref="#PWR52"  Part="1" 
AR Path="/4F79F54D/4F79EBE4" Ref="#PWR55"  Part="1" 
AR Path="/4F79E923/4F79EBE4" Ref="#PWR58"  Part="1" 
F 0 "#PWR55" H 4000 6150 30  0001 C CNN
F 1 "GND" H 4000 6080 30  0001 C CNN
	1    4000 6150
	1    0    0    -1  
$EndComp
$Comp
L R R33
U 1 1 4F79EBD8
P 4000 5650
AR Path="/4F79F576/4F79EBD8" Ref="R33"  Part="1" 
AR Path="/4F79F575/4F79EBD8" Ref="R38"  Part="1" 
AR Path="/4F79F56D/4F79EBD8" Ref="R43"  Part="1" 
AR Path="/4F79F56C/4F79EBD8" Ref="R48"  Part="1" 
AR Path="/4F79F56B/4F79EBD8" Ref="R53"  Part="1" 
AR Path="/4F79F56A/4F79EBD8" Ref="R58"  Part="1" 
AR Path="/4F79F55E/4F79EBD8" Ref="R63"  Part="1" 
AR Path="/4F79F55D/4F79EBD8" Ref="R68"  Part="1" 
AR Path="/4F79F54D/4F79EBD8" Ref="R73"  Part="1" 
AR Path="/4F79E923/4F79EBD8" Ref="R78"  Part="1" 
F 0 "R73" V 4080 5650 50  0000 C CNN
F 1 "10k" V 4000 5650 50  0000 C CNN
	1    4000 5650
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 4F79EBD0
P 3550 5250
AR Path="/4F79F576/4F79EBD0" Ref="R32"  Part="1" 
AR Path="/4F79F575/4F79EBD0" Ref="R37"  Part="1" 
AR Path="/4F79F56D/4F79EBD0" Ref="R42"  Part="1" 
AR Path="/4F79F56C/4F79EBD0" Ref="R47"  Part="1" 
AR Path="/4F79F56B/4F79EBD0" Ref="R52"  Part="1" 
AR Path="/4F79F56A/4F79EBD0" Ref="R57"  Part="1" 
AR Path="/4F79F55E/4F79EBD0" Ref="R62"  Part="1" 
AR Path="/4F79F55D/4F79EBD0" Ref="R67"  Part="1" 
AR Path="/4F79F54D/4F79EBD0" Ref="R72"  Part="1" 
AR Path="/4F79E923/4F79EBD0" Ref="R77"  Part="1" 
F 0 "R72" V 3630 5250 50  0000 C CNN
F 1 "1k" V 3550 5250 50  0000 C CNN
	1    3550 5250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR30
U 1 1 4F79EBCA
P 4450 5750
AR Path="/4F79F576/4F79EBCA" Ref="#PWR30"  Part="1" 
AR Path="/4F79F575/4F79EBCA" Ref="#PWR33"  Part="1" 
AR Path="/4F79F56D/4F79EBCA" Ref="#PWR36"  Part="1" 
AR Path="/4F79F56C/4F79EBCA" Ref="#PWR39"  Part="1" 
AR Path="/4F79F56B/4F79EBCA" Ref="#PWR42"  Part="1" 
AR Path="/4F79F56A/4F79EBCA" Ref="#PWR45"  Part="1" 
AR Path="/4F79F55E/4F79EBCA" Ref="#PWR48"  Part="1" 
AR Path="/4F79F55D/4F79EBCA" Ref="#PWR51"  Part="1" 
AR Path="/4F79F54D/4F79EBCA" Ref="#PWR54"  Part="1" 
AR Path="/4F79E923/4F79EBCA" Ref="#PWR57"  Part="1" 
F 0 "#PWR54" H 4450 5750 30  0001 C CNN
F 1 "GND" H 4450 5680 30  0001 C CNN
	1    4450 5750
	1    0    0    -1  
$EndComp
$Comp
L R R30
U 1 1 4F79EBB8
P 4450 4650
AR Path="/4F79F576/4F79EBB8" Ref="R30"  Part="1" 
AR Path="/4F79F575/4F79EBB8" Ref="R35"  Part="1" 
AR Path="/4F79F56D/4F79EBB8" Ref="R40"  Part="1" 
AR Path="/4F79F56C/4F79EBB8" Ref="R45"  Part="1" 
AR Path="/4F79F56B/4F79EBB8" Ref="R50"  Part="1" 
AR Path="/4F79F56A/4F79EBB8" Ref="R55"  Part="1" 
AR Path="/4F79F55E/4F79EBB8" Ref="R60"  Part="1" 
AR Path="/4F79F55D/4F79EBB8" Ref="R65"  Part="1" 
AR Path="/4F79F54D/4F79EBB8" Ref="R70"  Part="1" 
AR Path="/4F79E923/4F79EBB8" Ref="R75"  Part="1" 
F 0 "R70" V 4530 4650 50  0000 C CNN
F 1 "330" V 4450 4650 50  0000 C CNN
	1    4450 4650
	1    0    0    -1  
$EndComp
$Comp
L NPN Q9
U 1 1 4F79EB99
P 4350 5250
AR Path="/4F79F576/4F79EB99" Ref="Q9"  Part="1" 
AR Path="/4F79F575/4F79EB99" Ref="Q11"  Part="1" 
AR Path="/4F79F56D/4F79EB99" Ref="Q13"  Part="1" 
AR Path="/4F79F56C/4F79EB99" Ref="Q15"  Part="1" 
AR Path="/4F79F56B/4F79EB99" Ref="Q17"  Part="1" 
AR Path="/4F79F56A/4F79EB99" Ref="Q19"  Part="1" 
AR Path="/4F79F55E/4F79EB99" Ref="Q21"  Part="1" 
AR Path="/4F79F55D/4F79EB99" Ref="Q23"  Part="1" 
AR Path="/4F79F54D/4F79EB99" Ref="Q25"  Part="1" 
AR Path="/4F79E923/4F79EB99" Ref="Q27"  Part="1" 
F 0 "Q25" H 4350 5100 50  0000 R CNN
F 1 "bc847" H 4350 5400 50  0000 R CNN
	1    4350 5250
	1    0    0    -1  
$EndComp
$Comp
L PHDARL U8
U 1 1 4F79EB8E
P 5200 4000
AR Path="/4F79F576/4F79EB8E" Ref="U8"  Part="1" 
AR Path="/4F79F575/4F79EB8E" Ref="U9"  Part="1" 
AR Path="/4F79F56D/4F79EB8E" Ref="U10"  Part="1" 
AR Path="/4F79F56C/4F79EB8E" Ref="U11"  Part="1" 
AR Path="/4F79F56B/4F79EB8E" Ref="U12"  Part="1" 
AR Path="/4F79F56A/4F79EB8E" Ref="U13"  Part="1" 
AR Path="/4F79F55E/4F79EB8E" Ref="U14"  Part="1" 
AR Path="/4F79F55D/4F79EB8E" Ref="U15"  Part="1" 
AR Path="/4F79F54D/4F79EB8E" Ref="U16"  Part="1" 
AR Path="/4F79E923/4F79EB8E" Ref="U17"  Part="1" 
F 0 "U16" H 5210 4320 70  0000 C CNN
F 1 "PHDARL" H 5210 3680 70  0000 C CNN
	1    5200 4000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
