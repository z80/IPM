EESchema Schematic File Version 2  date Wed 04 Apr 2012 04:27:02 PM MSK
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
Sheet 24 27
Title ""
Date "4 apr 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	4000 5900 4000 6150
Wire Wire Line
	7800 3000 7800 2700
Connection ~ 7800 3700
Wire Wire Line
	6900 5000 6900 5350
Connection ~ 6900 4200
Wire Wire Line
	6900 4500 6900 4200
Wire Wire Line
	5800 4200 6050 4200
Wire Wire Line
	4450 3350 4450 3800
Wire Wire Line
	4450 3800 4600 3800
Wire Wire Line
	3300 5250 3000 5250
Wire Wire Line
	3800 5250 4150 5250
Wire Wire Line
	4450 5050 4450 4900
Wire Wire Line
	4000 5400 4000 5250
Connection ~ 4000 5250
Wire Wire Line
	4450 4400 4450 4200
Wire Wire Line
	4450 4200 4600 4200
Wire Wire Line
	7450 4400 7450 4850
Wire Wire Line
	6550 4200 7150 4200
Wire Wire Line
	5800 3800 5950 3800
Wire Wire Line
	5950 3800 5950 3350
Wire Wire Line
	7450 4000 7450 3700
Wire Wire Line
	7450 3700 7900 3700
Wire Wire Line
	7800 3400 7800 4000
Wire Wire Line
	7800 4400 7800 4850
Wire Wire Line
	4450 5450 4450 5750
Text GLabel 7800 2700 1    60   Input ~ 0
vcc-24v
Text GLabel 7800 4850 3    60   Input ~ 0
gnd-24v
$Comp
L DIODE D1
U 1 1 4F79EE31
P 7800 3200
AR Path="/4F79F575/4F79EE31" Ref="D1"  Part="1" 
AR Path="/4F79F56D/4F79EE31" Ref="D3"  Part="1" 
AR Path="/4F79F56C/4F79EE31" Ref="D5"  Part="1" 
AR Path="/4F79F56B/4F79EE31" Ref="D7"  Part="1" 
AR Path="/4F79F56A/4F79EE31" Ref="D9"  Part="1" 
AR Path="/4F79F55E/4F79EE31" Ref="D11"  Part="1" 
AR Path="/4F79F54D/4F79EE31" Ref="D13"  Part="1" 
AR Path="/4F79E923/4F79EE31" Ref="D15"  Part="1" 
F 0 "D15" H 7800 3300 40  0000 C CNN
F 1 "DIODE" H 7800 3100 40  0000 C CNN
	1    7800 3200
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D2
U 1 1 4F79EE29
P 7800 4200
AR Path="/4F79F575/4F79EE29" Ref="D2"  Part="1" 
AR Path="/4F79F56D/4F79EE29" Ref="D4"  Part="1" 
AR Path="/4F79F56C/4F79EE29" Ref="D6"  Part="1" 
AR Path="/4F79F56B/4F79EE29" Ref="D8"  Part="1" 
AR Path="/4F79F56A/4F79EE29" Ref="D10"  Part="1" 
AR Path="/4F79F55E/4F79EE29" Ref="D12"  Part="1" 
AR Path="/4F79F54D/4F79EE29" Ref="D14"  Part="1" 
AR Path="/4F79E923/4F79EE29" Ref="D16"  Part="1" 
F 0 "D16" H 7800 4300 40  0000 C CNN
F 1 "DIODE" H 7800 4100 40  0000 C CNN
	1    7800 4200
	0    -1   -1   0   
$EndComp
Text HLabel 3000 5250 0    60   Input ~ 0
in
Text HLabel 7900 3700 2    60   Input ~ 0
out
$Comp
L VCC #PWR067
U 1 1 4F79ED4B
P 4450 3350
AR Path="/4F79F575/4F79ED4B" Ref="#PWR067"  Part="1" 
AR Path="/4F79F56D/4F79ED4B" Ref="#PWR070"  Part="1" 
AR Path="/4F79F56C/4F79ED4B" Ref="#PWR073"  Part="1" 
AR Path="/4F79F56B/4F79ED4B" Ref="#PWR076"  Part="1" 
AR Path="/4F79F56A/4F79ED4B" Ref="#PWR079"  Part="1" 
AR Path="/4F79F55E/4F79ED4B" Ref="#PWR082"  Part="1" 
AR Path="/4F79F54D/4F79ED4B" Ref="#PWR085"  Part="1" 
AR Path="/4F79E923/4F79ED4B" Ref="#PWR088"  Part="1" 
F 0 "#PWR088" H 4450 3450 30  0001 C CNN
F 1 "VCC" H 4450 3450 30  0000 C CNN
	1    4450 3350
	1    0    0    -1  
$EndComp
Text GLabel 6900 5350 3    60   Input ~ 0
gnd-24v
Text GLabel 5950 3350 1    60   Input ~ 0
vcc-24v
$Comp
L R R64
U 1 1 4F79EC92
P 6300 4200
AR Path="/4F79F575/4F79EC92" Ref="R64"  Part="1" 
AR Path="/4F79F56D/4F79EC92" Ref="R69"  Part="1" 
AR Path="/4F79F56C/4F79EC92" Ref="R74"  Part="1" 
AR Path="/4F79F56B/4F79EC92" Ref="R79"  Part="1" 
AR Path="/4F79F56A/4F79EC92" Ref="R84"  Part="1" 
AR Path="/4F79F55E/4F79EC92" Ref="R89"  Part="1" 
AR Path="/4F79F54D/4F79EC92" Ref="R94"  Part="1" 
AR Path="/4F79E923/4F79EC92" Ref="R99"  Part="1" 
F 0 "R99" V 6380 4200 50  0000 C CNN
F 1 "1k" V 6300 4200 50  0000 C CNN
	1    6300 4200
	0    -1   -1   0   
$EndComp
$Comp
L R R65
U 1 1 4F79EC7E
P 6900 4750
AR Path="/4F79F575/4F79EC7E" Ref="R65"  Part="1" 
AR Path="/4F79F56D/4F79EC7E" Ref="R70"  Part="1" 
AR Path="/4F79F56C/4F79EC7E" Ref="R75"  Part="1" 
AR Path="/4F79F56B/4F79EC7E" Ref="R80"  Part="1" 
AR Path="/4F79F56A/4F79EC7E" Ref="R85"  Part="1" 
AR Path="/4F79F55E/4F79EC7E" Ref="R90"  Part="1" 
AR Path="/4F79F54D/4F79EC7E" Ref="R95"  Part="1" 
AR Path="/4F79E923/4F79EC7E" Ref="R100"  Part="1" 
F 0 "R100" V 6980 4750 50  0000 C CNN
F 1 "1k" V 6900 4750 50  0000 C CNN
	1    6900 4750
	1    0    0    -1  
$EndComp
Text GLabel 7450 4850 3    60   Input ~ 0
gnd-24v
$Comp
L MOSFET_N Q17
U 1 1 4F79EC1C
P 7350 4200
AR Path="/4F79F575/4F79EC1C" Ref="Q17"  Part="1" 
AR Path="/4F79F56D/4F79EC1C" Ref="Q19"  Part="1" 
AR Path="/4F79F56C/4F79EC1C" Ref="Q21"  Part="1" 
AR Path="/4F79F56B/4F79EC1C" Ref="Q23"  Part="1" 
AR Path="/4F79F56A/4F79EC1C" Ref="Q25"  Part="1" 
AR Path="/4F79F55E/4F79EC1C" Ref="Q27"  Part="1" 
AR Path="/4F79F54D/4F79EC1C" Ref="Q29"  Part="1" 
AR Path="/4F79E923/4F79EC1C" Ref="Q31"  Part="1" 
F 0 "Q31" H 7360 4370 60  0000 R CNN
F 1 "MOSFET_N" H 7360 4050 60  0000 R CNN
	1    7350 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR068
U 1 1 4F79EBE4
P 4000 6150
AR Path="/4F79F575/4F79EBE4" Ref="#PWR068"  Part="1" 
AR Path="/4F79F56D/4F79EBE4" Ref="#PWR071"  Part="1" 
AR Path="/4F79F56C/4F79EBE4" Ref="#PWR074"  Part="1" 
AR Path="/4F79F56B/4F79EBE4" Ref="#PWR077"  Part="1" 
AR Path="/4F79F56A/4F79EBE4" Ref="#PWR080"  Part="1" 
AR Path="/4F79F55E/4F79EBE4" Ref="#PWR083"  Part="1" 
AR Path="/4F79F54D/4F79EBE4" Ref="#PWR086"  Part="1" 
AR Path="/4F79E923/4F79EBE4" Ref="#PWR089"  Part="1" 
F 0 "#PWR089" H 4000 6150 30  0001 C CNN
F 1 "GND" H 4000 6080 30  0001 C CNN
	1    4000 6150
	1    0    0    -1  
$EndComp
$Comp
L R R62
U 1 1 4F79EBD8
P 4000 5650
AR Path="/4F79F575/4F79EBD8" Ref="R62"  Part="1" 
AR Path="/4F79F56D/4F79EBD8" Ref="R67"  Part="1" 
AR Path="/4F79F56C/4F79EBD8" Ref="R72"  Part="1" 
AR Path="/4F79F56B/4F79EBD8" Ref="R77"  Part="1" 
AR Path="/4F79F56A/4F79EBD8" Ref="R82"  Part="1" 
AR Path="/4F79F55E/4F79EBD8" Ref="R87"  Part="1" 
AR Path="/4F79F54D/4F79EBD8" Ref="R92"  Part="1" 
AR Path="/4F79E923/4F79EBD8" Ref="R97"  Part="1" 
F 0 "R97" V 4080 5650 50  0000 C CNN
F 1 "10k" V 4000 5650 50  0000 C CNN
	1    4000 5650
	1    0    0    -1  
$EndComp
$Comp
L R R61
U 1 1 4F79EBD0
P 3550 5250
AR Path="/4F79F575/4F79EBD0" Ref="R61"  Part="1" 
AR Path="/4F79F56D/4F79EBD0" Ref="R66"  Part="1" 
AR Path="/4F79F56C/4F79EBD0" Ref="R71"  Part="1" 
AR Path="/4F79F56B/4F79EBD0" Ref="R76"  Part="1" 
AR Path="/4F79F56A/4F79EBD0" Ref="R81"  Part="1" 
AR Path="/4F79F55E/4F79EBD0" Ref="R86"  Part="1" 
AR Path="/4F79F54D/4F79EBD0" Ref="R91"  Part="1" 
AR Path="/4F79E923/4F79EBD0" Ref="R96"  Part="1" 
F 0 "R96" V 3630 5250 50  0000 C CNN
F 1 "1k" V 3550 5250 50  0000 C CNN
	1    3550 5250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR069
U 1 1 4F79EBCA
P 4450 5750
AR Path="/4F79F575/4F79EBCA" Ref="#PWR069"  Part="1" 
AR Path="/4F79F56D/4F79EBCA" Ref="#PWR072"  Part="1" 
AR Path="/4F79F56C/4F79EBCA" Ref="#PWR075"  Part="1" 
AR Path="/4F79F56B/4F79EBCA" Ref="#PWR078"  Part="1" 
AR Path="/4F79F56A/4F79EBCA" Ref="#PWR081"  Part="1" 
AR Path="/4F79F55E/4F79EBCA" Ref="#PWR084"  Part="1" 
AR Path="/4F79F54D/4F79EBCA" Ref="#PWR087"  Part="1" 
AR Path="/4F79E923/4F79EBCA" Ref="#PWR090"  Part="1" 
F 0 "#PWR090" H 4450 5750 30  0001 C CNN
F 1 "GND" H 4450 5680 30  0001 C CNN
	1    4450 5750
	1    0    0    -1  
$EndComp
$Comp
L R R63
U 1 1 4F79EBB8
P 4450 4650
AR Path="/4F79F575/4F79EBB8" Ref="R63"  Part="1" 
AR Path="/4F79F56D/4F79EBB8" Ref="R68"  Part="1" 
AR Path="/4F79F56C/4F79EBB8" Ref="R73"  Part="1" 
AR Path="/4F79F56B/4F79EBB8" Ref="R78"  Part="1" 
AR Path="/4F79F56A/4F79EBB8" Ref="R83"  Part="1" 
AR Path="/4F79F55E/4F79EBB8" Ref="R88"  Part="1" 
AR Path="/4F79F54D/4F79EBB8" Ref="R93"  Part="1" 
AR Path="/4F79E923/4F79EBB8" Ref="R98"  Part="1" 
F 0 "R98" V 4530 4650 50  0000 C CNN
F 1 "330" V 4450 4650 50  0000 C CNN
	1    4450 4650
	1    0    0    -1  
$EndComp
$Comp
L NPN Q16
U 1 1 4F79EB99
P 4350 5250
AR Path="/4F79F575/4F79EB99" Ref="Q16"  Part="1" 
AR Path="/4F79F56D/4F79EB99" Ref="Q18"  Part="1" 
AR Path="/4F79F56C/4F79EB99" Ref="Q20"  Part="1" 
AR Path="/4F79F56B/4F79EB99" Ref="Q22"  Part="1" 
AR Path="/4F79F56A/4F79EB99" Ref="Q24"  Part="1" 
AR Path="/4F79F55E/4F79EB99" Ref="Q26"  Part="1" 
AR Path="/4F79F54D/4F79EB99" Ref="Q28"  Part="1" 
AR Path="/4F79E923/4F79EB99" Ref="Q30"  Part="1" 
F 0 "Q30" H 4350 5100 50  0000 R CNN
F 1 "bc847" H 4350 5400 50  0000 R CNN
	1    4350 5250
	1    0    0    -1  
$EndComp
$Comp
L PHDARL U16
U 1 1 4F79EB8E
P 5200 4000
AR Path="/4F79F575/4F79EB8E" Ref="U16"  Part="1" 
AR Path="/4F79F56D/4F79EB8E" Ref="U17"  Part="1" 
AR Path="/4F79F56C/4F79EB8E" Ref="U18"  Part="1" 
AR Path="/4F79F56B/4F79EB8E" Ref="U19"  Part="1" 
AR Path="/4F79F56A/4F79EB8E" Ref="U20"  Part="1" 
AR Path="/4F79F55E/4F79EB8E" Ref="U21"  Part="1" 
AR Path="/4F79F54D/4F79EB8E" Ref="U22"  Part="1" 
AR Path="/4F79E923/4F79EB8E" Ref="U23"  Part="1" 
F 0 "U23" H 5210 4320 70  0000 C CNN
F 1 "PHDARL" H 5210 3680 70  0000 C CNN
	1    5200 4000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
