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
$EndSCHEMATC
