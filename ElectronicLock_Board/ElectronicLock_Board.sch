EESchema Schematic File Version 2
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
LIBS:STM32F0_DIO-Slave_ver0.0.0board-cache
LIBS:ElectronicLock_Board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F042 U?
U 1 1 5879F6AD
P 4650 2350
F 0 "U?" H 5250 2250 60  0000 C CNN
F 1 "STM32F042" H 5250 2400 60  0000 C CNN
F 2 "" H 5200 2250 60  0000 C CNN
F 3 "" H 5200 2250 60  0000 C CNN
	1    4650 2350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5879F72B
P 9400 3800
F 0 "#PWR?" H 9400 3650 50  0001 C CNN
F 1 "+5V" H 9400 3940 50  0000 C CNN
F 2 "" H 9400 3800 50  0000 C CNN
F 3 "" H 9400 3800 50  0000 C CNN
	1    9400 3800
	1    0    0    -1  
$EndComp
$Comp
L 033EZ1H U?
U 1 1 5879F810
P 9800 4250
F 0 "U?" H 10400 4300 60  0000 C CNN
F 1 "033EZ1H" H 10400 4200 60  0000 C CNN
F 2 "" H 9800 4250 60  0000 C CNN
F 3 "" H 9800 4250 60  0000 C CNN
	1    9800 4250
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5879F885
P 9250 4050
F 0 "C?" H 9260 4120 50  0000 L CNN
F 1 "0.1u" H 9260 3970 50  0000 L CNN
F 2 "" H 9250 4050 50  0000 C CNN
F 3 "" H 9250 4050 50  0000 C CNN
	1    9250 4050
	0    1    1    0   
$EndComp
Wire Wire Line
	9450 4050 9350 4050
Wire Wire Line
	9400 3800 9400 4150
Connection ~ 9400 4050
Wire Wire Line
	9400 4150 9450 4150
$Comp
L CP1_Small C?
U 1 1 5879F937
P 9250 4450
F 0 "C?" H 9100 4500 50  0000 L CNN
F 1 "47u" H 9050 4400 50  0000 L CNN
F 2 "" H 9250 4450 50  0000 C CNN
F 3 "" H 9250 4450 50  0000 C CNN
	1    9250 4450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 4450 9450 4450
Wire Wire Line
	9400 4450 9400 4600
Connection ~ 9400 4450
$Comp
L GND #PWR?
U 1 1 5879F9FB
P 9400 4600
F 0 "#PWR?" H 9400 4350 50  0001 C CNN
F 1 "GND" H 9400 4450 50  0000 C CNN
F 2 "" H 9400 4600 50  0000 C CNN
F 3 "" H 9400 4600 50  0000 C CNN
	1    9400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 4250 9100 4250
Wire Wire Line
	9100 4450 9150 4450
Wire Wire Line
	9100 3800 9100 4450
Connection ~ 9100 4250
$Comp
L +3.3V #PWR?
U 1 1 5879FA6A
P 9100 3800
F 0 "#PWR?" H 9100 3650 50  0001 C CNN
F 1 "+3.3V" H 9100 3940 50  0000 C CNN
F 2 "" H 9100 3800 50  0000 C CNN
F 3 "" H 9100 3800 50  0000 C CNN
	1    9100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 4050 9100 4050
Connection ~ 9100 4050
Wire Wire Line
	8050 2500 8450 2500
Text Label 8450 2500 2    60   ~ 0
NRST
Wire Wire Line
	750  1750 1300 1750
Text Label 750  1750 0    60   ~ 0
ServoSignal
Wire Wire Line
	1300 1950 750  1950
Wire Wire Line
	750  2050 1300 2050
Wire Wire Line
	1300 2150 750  2150
Text Label 750  2150 0    60   ~ 0
SW_Out_3
Text Label 750  2050 0    60   ~ 0
SW_Out_2
Text Label 750  1950 0    60   ~ 0
SW_Out_1
Wire Wire Line
	1300 2250 750  2250
Text Label 750  2250 0    60   ~ 0
SW_Out_4
Wire Wire Line
	1300 2450 750  2450
Wire Wire Line
	1300 2550 750  2550
Text Label 750  2450 0    60   ~ 0
SWDIO
Text Label 750  2550 0    60   ~ 0
SWCLK
Wire Wire Line
	8050 1450 8550 1450
Wire Wire Line
	8550 1550 8050 1550
Wire Wire Line
	8050 1650 8550 1650
Text Label 8550 1450 2    60   ~ 0
SW_In_1
Text Label 8550 1550 2    60   ~ 0
SW_In_2
Text Label 8550 1650 2    60   ~ 0
SW_In_3
Wire Wire Line
	1300 1850 750  1850
Text Label 750  1850 0    60   ~ 0
Speaker
Wire Wire Line
	1300 2350 750  2350
Text Label 750  2350 0    60   ~ 0
SW_Lock
$Comp
L CONN_01X06 P?
U 1 1 589F1C4B
P 7750 4200
F 0 "P?" H 7750 4550 50  0000 C CNN
F 1 "CONN_01X06" V 7850 4200 50  0000 C CNN
F 2 "" H 7750 4200 50  0000 C CNN
F 3 "" H 7750 4200 50  0000 C CNN
	1    7750 4200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P?
U 1 1 589F1D2A
P 6250 4050
F 0 "P?" H 6250 4300 50  0000 C CNN
F 1 "CONN_01X04" V 6350 4050 50  0000 C CNN
F 2 "" H 6250 4050 50  0000 C CNN
F 3 "" H 6250 4050 50  0000 C CNN
	1    6250 4050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 589F1DEB
P 6250 4950
F 0 "P?" H 6250 5150 50  0000 C CNN
F 1 "CONN_01X03" V 6350 4950 50  0000 C CNN
F 2 "" H 6250 4950 50  0000 C CNN
F 3 "" H 6250 4950 50  0000 C CNN
	1    6250 4950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 589F2024
P 5850 3900
F 0 "R?" V 5930 3900 50  0000 C CNN
F 1 "R" V 5850 3900 50  0000 C CNN
F 2 "" V 5780 3900 50  0000 C CNN
F 3 "" H 5850 3900 50  0000 C CNN
	1    5850 3900
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 589F2061
P 5850 4000
F 0 "R?" V 5930 4000 50  0000 C CNN
F 1 "R" V 5850 4000 50  0000 C CNN
F 2 "" V 5780 4000 50  0000 C CNN
F 3 "" H 5850 4000 50  0000 C CNN
	1    5850 4000
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 589F208C
P 5850 4100
F 0 "R?" V 5930 4100 50  0000 C CNN
F 1 "R" V 5850 4100 50  0000 C CNN
F 2 "" V 5780 4100 50  0000 C CNN
F 3 "" H 5850 4100 50  0000 C CNN
	1    5850 4100
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 589F20BA
P 5850 4200
F 0 "R?" V 5930 4200 50  0000 C CNN
F 1 "R" V 5850 4200 50  0000 C CNN
F 2 "" V 5780 4200 50  0000 C CNN
F 3 "" H 5850 4200 50  0000 C CNN
	1    5850 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 4200 6000 4200
Wire Wire Line
	6000 4100 6050 4100
Wire Wire Line
	6000 4000 6050 4000
Wire Wire Line
	6000 3900 6050 3900
Wire Wire Line
	5700 3900 5200 3900
Wire Wire Line
	5200 4000 5700 4000
Wire Wire Line
	5700 4100 5200 4100
Wire Wire Line
	5200 4200 5700 4200
Text Label 5200 3900 0    60   ~ 0
SW_Out_1
Text Label 5200 4000 0    60   ~ 0
SW_Out_2
Text Label 5200 4100 0    60   ~ 0
SW_Out_3
Text Label 5200 4200 0    60   ~ 0
SW_Out_4
$Comp
L R R?
U 1 1 589F24D2
P 5850 4850
F 0 "R?" V 5930 4850 50  0000 C CNN
F 1 "R" V 5850 4850 50  0000 C CNN
F 2 "" V 5780 4850 50  0000 C CNN
F 3 "" H 5850 4850 50  0000 C CNN
	1    5850 4850
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 589F24D8
P 5850 4950
F 0 "R?" V 5930 4950 50  0000 C CNN
F 1 "R" V 5850 4950 50  0000 C CNN
F 2 "" V 5780 4950 50  0000 C CNN
F 3 "" H 5850 4950 50  0000 C CNN
	1    5850 4950
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 589F24DE
P 5850 5050
F 0 "R?" V 5930 5050 50  0000 C CNN
F 1 "R" V 5850 5050 50  0000 C CNN
F 2 "" V 5780 5050 50  0000 C CNN
F 3 "" H 5850 5050 50  0000 C CNN
	1    5850 5050
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 5050 6050 5050
Wire Wire Line
	6000 4950 6050 4950
Wire Wire Line
	6000 4850 6050 4850
Wire Wire Line
	5700 4850 5200 4850
Wire Wire Line
	5200 4950 5700 4950
Wire Wire Line
	5700 5050 5200 5050
Text Label 5200 4850 0    60   ~ 0
SW_In_1
Text Label 5200 4950 0    60   ~ 0
SW_In_2
Text Label 5200 5050 0    60   ~ 0
SW_In_3
$EndSCHEMATC
