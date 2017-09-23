EESchema Schematic File Version 3
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
LIBS:Mega2560EEPROMProgrammer-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Arduino Mega2560 Flash Memory Programmer"
Date "23 September 2017"
Rev "A"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_02X18 P1
U 1 1 597F01BE
P 4020 2845
F 0 "P1" H 4020 3795 50  0000 C CNN
F 1 "Mega2560 I/O" V 4020 2845 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x18_Pitch2.54mm" H 4020 1795 50  0001 C CNN
F 3 "" H 4020 1795 50  0000 C CNN
	1    4020 2845
	1    0    0    -1  
$EndComp
Text GLabel 6455 2375 2    40   Input ~ 0
+5v
Text GLabel 5545 3870 0    40   Input ~ 0
GND
Text GLabel 6455 2475 2    40   Input ~ 0
-WE
Text GLabel 6455 2575 2    40   Input ~ 0
A17
Text GLabel 6455 2675 2    40   Input ~ 0
A14
Text GLabel 6455 2775 2    40   Input ~ 0
A13
Text GLabel 6455 2875 2    40   Input ~ 0
A8
Text GLabel 6455 2975 2    40   Input ~ 0
A9
Text GLabel 6455 3075 2    40   Input ~ 0
A11
Text GLabel 6455 3175 2    40   Input ~ 0
-OE
Text GLabel 6455 3275 2    40   Input ~ 0
A10
Text GLabel 6455 3375 2    40   Input ~ 0
-CE
Text GLabel 6455 3475 2    40   Input ~ 0
D7
Text GLabel 6455 3575 2    40   Input ~ 0
D6
Text GLabel 6455 3675 2    40   Input ~ 0
D5
Text GLabel 6455 3775 2    40   Input ~ 0
D4
Text GLabel 6455 3875 2    40   Input ~ 0
D3
Text GLabel 5545 2370 0    40   Input ~ 0
A18
Text GLabel 5545 2470 0    40   Input ~ 0
A16
Text GLabel 5545 2570 0    40   Input ~ 0
A15
Text GLabel 5545 2670 0    40   Input ~ 0
A12
Text GLabel 5545 2770 0    40   Input ~ 0
A7
Text GLabel 5545 2870 0    40   Input ~ 0
A6
Text GLabel 5545 2970 0    40   Input ~ 0
A5
Text GLabel 5545 3070 0    40   Input ~ 0
A4
Text GLabel 5545 3170 0    40   Input ~ 0
A3
Text GLabel 5545 3270 0    40   Input ~ 0
A2
Text GLabel 5545 3370 0    40   Input ~ 0
A1
Text GLabel 5545 3470 0    40   Input ~ 0
A0
Text GLabel 5545 3570 0    40   Input ~ 0
D0
Text GLabel 5545 3670 0    40   Input ~ 0
D1
Text GLabel 5545 3770 0    40   Input ~ 0
D2
Text GLabel 3770 3695 0    40   Input ~ 0
GND
Text GLabel 4270 3695 2    40   Input ~ 0
GND
Text GLabel 4270 1995 2    40   Input ~ 0
+5v
Text GLabel 3770 1995 0    40   Input ~ 0
+5v
Text GLabel 4270 3395 2    40   Input ~ 0
D0
Text GLabel 3770 3395 0    40   Input ~ 0
D1
Text GLabel 4270 3295 2    40   Input ~ 0
D2
Text GLabel 4270 3195 2    40   Input ~ 0
D4
Text GLabel 4270 3095 2    40   Input ~ 0
D6
Text GLabel 3770 3295 0    40   Input ~ 0
D3
Text GLabel 3770 3195 0    40   Input ~ 0
D5
Text GLabel 3770 3095 0    40   Input ~ 0
D7
Text GLabel 3770 2095 0    40   Input ~ 0
A0
Text GLabel 3770 2195 0    40   Input ~ 0
A2
Text GLabel 3770 2295 0    40   Input ~ 0
A4
Text GLabel 3770 2395 0    40   Input ~ 0
A6
Text GLabel 4270 2095 2    40   Input ~ 0
A1
Text GLabel 4270 2195 2    40   Input ~ 0
A3
Text GLabel 4270 2295 2    40   Input ~ 0
A5
Text GLabel 4270 2395 2    40   Input ~ 0
A7
Text GLabel 4270 2795 2    40   Input ~ 0
A8
Text GLabel 3770 2795 0    40   Input ~ 0
A9
Text GLabel 4270 2695 2    40   Input ~ 0
A10
Text GLabel 3770 2695 0    40   Input ~ 0
A11
Text GLabel 4270 2595 2    40   Input ~ 0
A12
Text GLabel 3770 2595 0    40   Input ~ 0
A13
Text GLabel 4270 2495 2    40   Input ~ 0
A14
Text GLabel 3770 2495 0    40   Input ~ 0
A15
Text GLabel 4270 3595 2    40   Input ~ 0
A16
Text GLabel 3770 3595 0    40   Input ~ 0
A17
Text GLabel 4270 3495 2    40   Input ~ 0
A18
Text GLabel 4270 2995 2    40   Input ~ 0
-WE
Text GLabel 3770 2995 0    40   Input ~ 0
-CE
Text GLabel 4270 2895 2    40   Input ~ 0
-OE
$Comp
L Led_Small LED1
U 1 1 597F072C
P 3230 2895
F 0 "LED1" H 3180 3020 50  0000 L CNN
F 1 "Red" H 3055 2795 50  0000 L CNN
F 2 "LEDs:LED-3MM" V 3230 2895 50  0001 C CNN
F 3 "" V 3230 2895 50  0000 C CNN
	1    3230 2895
	1    0    0    -1  
$EndComp
$Comp
L Led_Small LED2
U 1 1 597F07B3
P 3310 3495
F 0 "LED2" H 3260 3620 50  0000 L CNN
F 1 "Green" H 3135 3395 50  0000 L CNN
F 2 "LEDs:LED-3MM" V 3310 3495 50  0001 C CNN
F 3 "" V 3310 3495 50  0000 C CNN
	1    3310 3495
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 597F08BB
P 2750 3670
F 0 "R2" V 2830 3670 50  0000 C CNN
F 1 "220R" V 2750 3670 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2680 3670 50  0001 C CNN
F 3 "" H 2750 3670 50  0000 C CNN
	1    2750 3670
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 597F0954
P 2465 3045
F 0 "R1" V 2545 3045 50  0000 C CNN
F 1 "220R" V 2465 3045 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2395 3045 50  0001 C CNN
F 3 "" H 2465 3045 50  0000 C CNN
	1    2465 3045
	1    0    0    -1  
$EndComp
Text GLabel 2750 3895 3    40   Input ~ 0
GND
Text GLabel 2465 3265 3    40   Input ~ 0
GND
Wire Wire Line
	3330 2895 3770 2895
Wire Wire Line
	3410 3495 3770 3495
Wire Wire Line
	3210 3495 2750 3495
Wire Wire Line
	2750 3495 2750 3520
Wire Wire Line
	3130 2895 2465 2895
Wire Wire Line
	2465 3195 2465 3265
Wire Wire Line
	2750 3820 2750 3895
$Comp
L CONN_01X20 P21
U 1 1 597F0D2D
P 5745 2920
F 0 "P21" H 5745 3970 50  0000 C CNN
F 1 "CONN_01X20" V 5845 2920 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x20_Pitch2.54mm" H 5745 2920 50  0001 C CNN
F 3 "" H 5745 2920 50  0000 C CNN
	1    5745 2920
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X20 P22
U 1 1 597F0E3F
P 6255 2925
F 0 "P22" H 6255 3975 50  0000 C CNN
F 1 "CONN_01X20" V 6355 2925 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x20_Pitch2.54mm" H 6255 2925 50  0001 C CNN
F 3 "" H 6255 2925 50  0000 C CNN
	1    6255 2925
	-1   0    0    -1  
$EndComp
NoConn ~ 6455 1975
NoConn ~ 6455 2075
NoConn ~ 6455 2175
NoConn ~ 6455 2275
NoConn ~ 5540 2270
NoConn ~ 5545 2170
NoConn ~ 5545 2070
NoConn ~ 5545 1970
$EndSCHEMATC
