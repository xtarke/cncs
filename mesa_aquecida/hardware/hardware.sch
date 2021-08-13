EESchema Schematic File Version 4
EELAYER 30 0
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
L Device:R R1
U 1 1 61159B31
P 2650 2800
F 0 "R1" H 2720 2846 50  0000 L CNN
F 1 "47K" H 2720 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 2580 2800 50  0001 C CNN
F 3 "~" H 2650 2800 50  0001 C CNN
	1    2650 2800
	1    0    0    -1  
$EndComp
$Comp
L MCU_Texas_MSP430:MSP430G2452IN20 U1
U 1 1 611571CF
P 4400 3450
F 0 "U1" H 3650 4400 50  0000 C CNN
F 1 "MSP430G2452IN20" H 3900 4250 50  0000 C CNN
F 2 "Package_DIP:DIP-20_W7.62mm" H 3100 2900 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/msp430g2452.pdf" H 4400 3450 50  0001 C CNN
	1    4400 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 6115C1FA
P 4700 2250
F 0 "C3" H 4815 2296 50  0000 L CNN
F 1 "10u" H 4815 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 4738 2100 50  0001 C CNN
F 3 "~" H 4700 2250 50  0001 C CNN
	1    4700 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 6115CCBD
P 5150 2250
F 0 "C4" H 5265 2296 50  0000 L CNN
F 1 "100n" H 5265 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 5188 2100 50  0001 C CNN
F 3 "~" H 5150 2250 50  0001 C CNN
	1    5150 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR014
U 1 1 6115DAE6
P 4400 1950
F 0 "#PWR014" H 4400 1800 50  0001 C CNN
F 1 "+3V3" H 4415 2123 50  0000 C CNN
F 2 "" H 4400 1950 50  0001 C CNN
F 3 "" H 4400 1950 50  0001 C CNN
	1    4400 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2000 4700 2000
Wire Wire Line
	4700 2000 4700 2100
Connection ~ 4400 2000
Wire Wire Line
	4400 2000 4400 1950
Wire Wire Line
	4700 2000 5150 2000
Wire Wire Line
	5150 2000 5150 2100
Connection ~ 4700 2000
$Comp
L power:GND #PWR017
U 1 1 61161859
P 4700 2550
F 0 "#PWR017" H 4700 2300 50  0001 C CNN
F 1 "GND" H 4705 2377 50  0000 C CNN
F 2 "" H 4700 2550 50  0001 C CNN
F 3 "" H 4700 2550 50  0001 C CNN
	1    4700 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 61163A17
P 5150 2550
F 0 "#PWR020" H 5150 2300 50  0001 C CNN
F 1 "GND" H 5155 2377 50  0000 C CNN
F 2 "" H 5150 2550 50  0001 C CNN
F 3 "" H 5150 2550 50  0001 C CNN
	1    5150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2400 4700 2550
Wire Wire Line
	5150 2400 5150 2550
Wire Wire Line
	4400 2000 4400 2650
$Comp
L power:GND #PWR015
U 1 1 611645A3
P 4400 4350
F 0 "#PWR015" H 4400 4100 50  0001 C CNN
F 1 "GND" H 4405 4177 50  0000 C CNN
F 2 "" H 4400 4350 50  0001 C CNN
F 3 "" H 4400 4350 50  0001 C CNN
	1    4400 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 4350 4400 4200
$Comp
L Device:C C1
U 1 1 6115A19B
P 2650 4100
F 0 "C1" H 2765 4146 50  0000 L CNN
F 1 "100n" H 2765 4055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 2688 3950 50  0001 C CNN
F 3 "~" H 2650 4100 50  0001 C CNN
	1    2650 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 61168593
P 2650 4350
F 0 "#PWR011" H 2650 4100 50  0001 C CNN
F 1 "GND" H 2655 4177 50  0000 C CNN
F 2 "" H 2650 4350 50  0001 C CNN
F 3 "" H 2650 4350 50  0001 C CNN
	1    2650 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4250 2650 4350
Wire Wire Line
	2650 2950 2650 3000
Wire Wire Line
	2650 3000 2900 3000
Connection ~ 2650 3000
Wire Wire Line
	2650 3000 2650 3950
$Comp
L power:+3V3 #PWR010
U 1 1 6116A6D2
P 2650 2500
F 0 "#PWR010" H 2650 2350 50  0001 C CNN
F 1 "+3V3" H 2665 2673 50  0000 C CNN
F 2 "" H 2650 2500 50  0001 C CNN
F 3 "" H 2650 2500 50  0001 C CNN
	1    2650 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 2650 2650 2500
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 6116C18F
P 1400 950
F 0 "J3" H 1500 1300 50  0000 C CNN
F 1 "Conn_01x04_Male" H 1550 1200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1400 950 50  0001 C CNN
F 3 "~" H 1400 950 50  0001 C CNN
	1    1400 950 
	1    0    0    -1  
$EndComp
Text GLabel 6150 2900 2    50   Input ~ 0
SBWTCK
Wire Wire Line
	5900 2900 6150 2900
Text GLabel 1800 1050 2    50   Input ~ 0
SBWTCK
Text GLabel 1800 1150 2    50   Input ~ 0
RST
Wire Wire Line
	1600 1050 1800 1050
Wire Wire Line
	1800 1150 1600 1150
$Comp
L power:+3V3 #PWR09
U 1 1 61173BD8
P 2300 750
F 0 "#PWR09" H 2300 600 50  0001 C CNN
F 1 "+3V3" H 2315 923 50  0000 C CNN
F 2 "" H 2300 750 50  0001 C CNN
F 3 "" H 2300 750 50  0001 C CNN
	1    2300 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D1
U 1 1 61175D51
P 2000 850
F 0 "D1" H 1600 850 50  0000 C CNN
F 1 "D_Schottky" H 1450 950 50  0000 C CNN
F 2 "Diode_SMD:D_SMB" H 2000 850 50  0001 C CNN
F 3 "~" H 2000 850 50  0001 C CNN
	1    2000 850 
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 850  2300 850 
Wire Wire Line
	2300 850  2300 750 
Wire Wire Line
	1600 850  1850 850 
$Comp
L power:GND #PWR05
U 1 1 6117872D
P 1700 1300
F 0 "#PWR05" H 1700 1050 50  0001 C CNN
F 1 "GND" H 1705 1127 50  0000 C CNN
F 2 "" H 1700 1300 50  0001 C CNN
F 3 "" H 1700 1300 50  0001 C CNN
	1    1700 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 950  1700 950 
Wire Wire Line
	1700 950  1700 1300
Text GLabel 2500 3000 0    50   Input ~ 0
RST
Wire Wire Line
	2650 3000 2500 3000
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 6118244D
P 5000 6850
F 0 "J2" H 5108 7131 50  0000 C CNN
F 1 "Conn_01x04_Male" H 5108 7040 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5000 6850 50  0001 C CNN
F 3 "~" H 5000 6850 50  0001 C CNN
	1    5000 6850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 61185526
P 5450 6300
F 0 "#PWR01" H 5450 6150 50  0001 C CNN
F 1 "+5V" H 5465 6473 50  0000 C CNN
F 2 "" H 5450 6300 50  0001 C CNN
F 3 "" H 5450 6300 50  0001 C CNN
	1    5450 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 61185F13
P 5450 7200
F 0 "#PWR02" H 5450 6950 50  0001 C CNN
F 1 "GND" H 5455 7027 50  0000 C CNN
F 2 "" H 5450 7200 50  0001 C CNN
F 3 "" H 5450 7200 50  0001 C CNN
	1    5450 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 6850 5450 7200
Text GLabel 6000 6950 2    50   Input ~ 0
SDA
Text GLabel 6000 7050 2    50   Input ~ 0
SCL
$Comp
L Device:R R3
U 1 1 6118C40C
P 5650 6600
F 0 "R3" H 5720 6646 50  0000 L CNN
F 1 "2k2" H 5720 6555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5580 6600 50  0001 C CNN
F 3 "~" H 5650 6600 50  0001 C CNN
	1    5650 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 6750 5450 6750
Wire Wire Line
	5200 6850 5450 6850
Wire Wire Line
	5200 6950 5650 6950
Wire Wire Line
	6000 7050 5950 7050
$Comp
L Device:R R5
U 1 1 61193A9B
P 5950 6600
F 0 "R5" H 6020 6646 50  0000 L CNN
F 1 "2k2" H 6020 6555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 5880 6600 50  0001 C CNN
F 3 "~" H 5950 6600 50  0001 C CNN
	1    5950 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 6950 5650 6750
Connection ~ 5650 6950
Wire Wire Line
	5650 6950 6000 6950
Wire Wire Line
	5950 7050 5950 6750
Connection ~ 5950 7050
Wire Wire Line
	5950 7050 5200 7050
$Comp
L power:+3V3 #PWR04
U 1 1 61195B85
P 5650 6300
F 0 "#PWR04" H 5650 6150 50  0001 C CNN
F 1 "+3V3" H 5665 6473 50  0000 C CNN
F 2 "" H 5650 6300 50  0001 C CNN
F 3 "" H 5650 6300 50  0001 C CNN
	1    5650 6300
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR07
U 1 1 61197441
P 5950 6300
F 0 "#PWR07" H 5950 6150 50  0001 C CNN
F 1 "+3V3" H 5965 6473 50  0000 C CNN
F 2 "" H 5950 6300 50  0001 C CNN
F 3 "" H 5950 6300 50  0001 C CNN
	1    5950 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 6450 5650 6300
Wire Wire Line
	5950 6450 5950 6300
Wire Wire Line
	5450 6300 5450 6750
$Comp
L Transistor_FET:IRF540N Q2
U 1 1 611ADFAE
P 9600 4800
F 0 "Q2" H 9804 4846 50  0000 L CNN
F 1 "IRF540N" H 9804 4755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9850 4725 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 9600 4800 50  0001 L CNN
	1    9600 4800
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 611B089C
P 9000 5250
F 0 "Q1" H 9204 5296 50  0000 L CNN
F 1 "2N7002" H 9204 5205 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 9200 5175 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 9000 5250 50  0001 L CNN
	1    9000 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 611C0A7E
P 6400 5000
F 0 "R7" H 6470 5046 50  0000 L CNN
F 1 "62k" H 6470 4955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 6330 5000 50  0001 C CNN
F 3 "~" H 6400 5000 50  0001 C CNN
	1    6400 5000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR018
U 1 1 611C2499
P 6400 4750
F 0 "#PWR018" H 6400 4600 50  0001 C CNN
F 1 "+3V3" H 6415 4923 50  0000 C CNN
F 2 "" H 6400 4750 50  0001 C CNN
F 3 "" H 6400 4750 50  0001 C CNN
	1    6400 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR031
U 1 1 611D8A9F
P 9700 5650
F 0 "#PWR031" H 9700 5400 50  0001 C CNN
F 1 "GND" H 9705 5477 50  0000 C CNN
F 2 "" H 9700 5650 50  0001 C CNN
F 3 "" H 9700 5650 50  0001 C CNN
	1    9700 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 611DD321
P 9100 4400
F 0 "R9" H 9170 4446 50  0000 L CNN
F 1 "10k" H 9170 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 9030 4400 50  0001 C CNN
F 3 "~" H 9100 4400 50  0001 C CNN
	1    9100 4400
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR027
U 1 1 611DE5D2
P 9100 3900
F 0 "#PWR027" H 9100 3750 50  0001 C CNN
F 1 "+12V" H 9115 4073 50  0000 C CNN
F 2 "" H 9100 3900 50  0001 C CNN
F 3 "" H 9100 3900 50  0001 C CNN
	1    9100 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 4800 9100 4550
Wire Wire Line
	9400 4800 9100 4800
Wire Wire Line
	9100 4800 9100 5050
Connection ~ 9100 4800
Wire Wire Line
	8800 5250 8450 5250
$Comp
L Device:R R8
U 1 1 611F5185
P 8450 5450
F 0 "R8" H 8520 5496 50  0000 L CNN
F 1 "500R" H 8520 5405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8380 5450 50  0001 C CNN
F 3 "~" H 8450 5450 50  0001 C CNN
	1    8450 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR028
U 1 1 611E1CF4
P 9100 5650
F 0 "#PWR028" H 9100 5400 50  0001 C CNN
F 1 "GND" H 9105 5477 50  0000 C CNN
F 2 "" H 9100 5650 50  0001 C CNN
F 3 "" H 9100 5650 50  0001 C CNN
	1    9100 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 611FA791
P 8450 5650
F 0 "#PWR025" H 8450 5400 50  0001 C CNN
F 1 "GND" H 8455 5477 50  0000 C CNN
F 2 "" H 8450 5650 50  0001 C CNN
F 3 "" H 8450 5650 50  0001 C CNN
	1    8450 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 5250 8450 5300
Wire Wire Line
	8450 5600 8450 5650
Wire Wire Line
	9100 5450 9100 5650
Wire Wire Line
	9700 5000 9700 5650
Text GLabel 8200 5250 0    50   Input ~ 0
POWER
Wire Wire Line
	8200 5250 8450 5250
Connection ~ 8450 5250
$Comp
L pspice:DIODE D3
U 1 1 61203C01
P 10700 4300
F 0 "D3" V 10746 4172 50  0000 R CNN
F 1 "DIODE" V 10655 4172 50  0000 R CNN
F 2 "Diode_SMD:D_SMB" H 10700 4300 50  0001 C CNN
F 3 "~" H 10700 4300 50  0001 C CNN
	1    10700 4300
	0    -1   -1   0   
$EndComp
$Comp
L power:+12V #PWR033
U 1 1 6120454B
P 10700 3900
F 0 "#PWR033" H 10700 3750 50  0001 C CNN
F 1 "+12V" H 10715 4073 50  0000 C CNN
F 2 "" H 10700 3900 50  0001 C CNN
F 3 "" H 10700 3900 50  0001 C CNN
	1    10700 3900
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR030
U 1 1 6120CDDD
P 9700 3900
F 0 "#PWR030" H 9700 3750 50  0001 C CNN
F 1 "+12V" H 9715 4073 50  0000 C CNN
F 2 "" H 9700 3900 50  0001 C CNN
F 3 "" H 9700 3900 50  0001 C CNN
	1    9700 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10700 3900 10700 4100
Wire Wire Line
	9700 4050 9700 3900
Wire Wire Line
	9100 3900 9100 4250
$Comp
L Connector:Conn_01x02_Female J4
U 1 1 6121A06C
P 6750 5500
F 0 "J4" H 6778 5476 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6650 5250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6750 5500 50  0001 C CNN
F 3 "~" H 6750 5500 50  0001 C CNN
	1    6750 5500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR019
U 1 1 61238ECF
P 6400 5700
F 0 "#PWR019" H 6400 5450 50  0001 C CNN
F 1 "GND" H 6405 5527 50  0000 C CNN
F 2 "" H 6400 5700 50  0001 C CNN
F 3 "" H 6400 5700 50  0001 C CNN
	1    6400 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 5600 6400 5600
Wire Wire Line
	6400 5600 6400 5700
Wire Wire Line
	6550 5500 6400 5500
Wire Wire Line
	6400 4850 6400 4750
Wire Wire Line
	6400 5150 6400 5250
Connection ~ 6400 5250
Wire Wire Line
	6400 5250 6400 5500
Text GLabel 6600 5250 2    50   Input ~ 0
NTC
Wire Wire Line
	6400 5250 6600 5250
Text GLabel 7000 3350 2    50   Input ~ 0
NTC
$Comp
L Device:C C2
U 1 1 6126C7C1
P 6600 3700
F 0 "C2" H 6715 3746 50  0000 L CNN
F 1 "100n" H 6715 3655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 6638 3550 50  0001 C CNN
F 3 "~" H 6600 3700 50  0001 C CNN
	1    6600 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 6126D21C
P 6600 3900
F 0 "#PWR016" H 6600 3650 50  0001 C CNN
F 1 "GND" H 6605 3727 50  0000 C CNN
F 2 "" H 6600 3900 50  0001 C CNN
F 3 "" H 6600 3900 50  0001 C CNN
	1    6600 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3850 6600 3900
Text GLabel 6150 3750 2    50   Input ~ 0
SDA
Text GLabel 6150 3650 2    50   Input ~ 0
SCL
Wire Wire Line
	5900 3650 6150 3650
Wire Wire Line
	6150 3750 5900 3750
Wire Wire Line
	1050 3150 1400 3150
Wire Wire Line
	1050 3250 1700 3250
Wire Wire Line
	1050 3350 2000 3350
$Comp
L Device:R R4
U 1 1 6129A88E
P 1700 2750
F 0 "R4" H 1770 2796 50  0000 L CNN
F 1 "2k2" H 1770 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1630 2750 50  0001 C CNN
F 3 "~" H 1700 2750 50  0001 C CNN
	1    1700 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 6129AC41
P 2000 2750
F 0 "R6" H 2070 2796 50  0000 L CNN
F 1 "2k2" H 2070 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1930 2750 50  0001 C CNN
F 3 "~" H 2000 2750 50  0001 C CNN
	1    2000 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 6129E92E
P 1400 2750
F 0 "R2" H 1470 2796 50  0000 L CNN
F 1 "2k2" H 1470 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1330 2750 50  0001 C CNN
F 3 "~" H 1400 2750 50  0001 C CNN
	1    1400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3150 1400 2900
Connection ~ 1400 3150
Wire Wire Line
	1700 2900 1700 3250
Connection ~ 1700 3250
Wire Wire Line
	2000 2900 2000 3350
Connection ~ 2000 3350
$Comp
L power:+3V3 #PWR03
U 1 1 612A3E65
P 1400 2450
F 0 "#PWR03" H 1400 2300 50  0001 C CNN
F 1 "+3V3" H 1415 2623 50  0000 C CNN
F 2 "" H 1400 2450 50  0001 C CNN
F 3 "" H 1400 2450 50  0001 C CNN
	1    1400 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR06
U 1 1 612A41E3
P 1700 2450
F 0 "#PWR06" H 1700 2300 50  0001 C CNN
F 1 "+3V3" H 1715 2623 50  0000 C CNN
F 2 "" H 1700 2450 50  0001 C CNN
F 3 "" H 1700 2450 50  0001 C CNN
	1    1700 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR08
U 1 1 612A45EF
P 2000 2450
F 0 "#PWR08" H 2000 2300 50  0001 C CNN
F 1 "+3V3" H 2015 2623 50  0000 C CNN
F 2 "" H 2000 2450 50  0001 C CNN
F 3 "" H 2000 2450 50  0001 C CNN
	1    2000 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 2450 1400 2600
Wire Wire Line
	1700 2600 1700 2450
Wire Wire Line
	2000 2450 2000 2600
Wire Wire Line
	1400 3150 2900 3150
Wire Wire Line
	1700 3250 2900 3250
Wire Wire Line
	2000 3350 2900 3350
Text Notes 5000 7550 0    50   ~ 0
LCD 16x2 with I2C
Text Notes 1950 1350 0    50   ~ 0
Debugger connector
Text Notes 600  3850 0    50   ~ 0
Buttons connector
Text Notes 6950 5300 0    50   ~ 0
NTC connector\nNTC = 152k @ 15°
Text Notes 8100 4000 0    50   ~ 0
Heater connection
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 612F3D49
P 7300 1150
F 0 "J5" H 7408 1331 50  0000 C CNN
F 1 "Conn_01x02_Male" H 7408 1240 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7300 1150 50  0001 C CNN
F 3 "~" H 7300 1150 50  0001 C CNN
	1    7300 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J7
U 1 1 612F42C8
P 8150 1150
F 0 "J7" H 8258 1331 50  0000 C CNN
F 1 "Conn_01x02_Male" H 8258 1240 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8150 1150 50  0001 C CNN
F 3 "~" H 8150 1150 50  0001 C CNN
	1    8150 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 612F49FD
P 7300 1550
F 0 "J6" H 7408 1731 50  0000 C CNN
F 1 "Conn_01x02_Male" H 7408 1640 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7300 1550 50  0001 C CNN
F 3 "~" H 7300 1550 50  0001 C CNN
	1    7300 1550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 612F4F0E
P 8150 1550
F 0 "J8" H 8258 1731 50  0000 C CNN
F 1 "Conn_01x02_Male" H 8258 1640 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8150 1550 50  0001 C CNN
F 3 "~" H 8150 1550 50  0001 C CNN
	1    8150 1550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR021
U 1 1 612F7F42
P 7800 900
F 0 "#PWR021" H 7800 750 50  0001 C CNN
F 1 "+12V" H 7815 1073 50  0000 C CNN
F 2 "" H 7800 900 50  0001 C CNN
F 3 "" H 7800 900 50  0001 C CNN
	1    7800 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1150 7800 1150
Wire Wire Line
	7800 1150 7800 900 
Wire Wire Line
	7500 1250 7800 1250
Wire Wire Line
	7800 1250 7800 1150
Connection ~ 7800 1150
$Comp
L power:GND #PWR022
U 1 1 613013C4
P 7800 1750
F 0 "#PWR022" H 7800 1500 50  0001 C CNN
F 1 "GND" H 7805 1577 50  0000 C CNN
F 2 "" H 7800 1750 50  0001 C CNN
F 3 "" H 7800 1750 50  0001 C CNN
	1    7800 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1650 7800 1650
Wire Wire Line
	7800 1650 7800 1750
Wire Wire Line
	7500 1550 7800 1550
Wire Wire Line
	7800 1550 7800 1650
Connection ~ 7800 1650
$Comp
L power:+5V #PWR023
U 1 1 6130AA00
P 8750 900
F 0 "#PWR023" H 8750 750 50  0001 C CNN
F 1 "+5V" H 8765 1073 50  0000 C CNN
F 2 "" H 8750 900 50  0001 C CNN
F 3 "" H 8750 900 50  0001 C CNN
	1    8750 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 1150 8750 1150
Wire Wire Line
	8750 1150 8750 900 
Wire Wire Line
	8350 1250 8750 1250
Wire Wire Line
	8750 1250 8750 1150
Connection ~ 8750 1150
$Comp
L power:GND #PWR024
U 1 1 61311A94
P 8750 1750
F 0 "#PWR024" H 8750 1500 50  0001 C CNN
F 1 "GND" H 8755 1577 50  0000 C CNN
F 2 "" H 8750 1750 50  0001 C CNN
F 3 "" H 8750 1750 50  0001 C CNN
	1    8750 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 1650 8750 1650
Wire Wire Line
	8750 1650 8750 1750
Wire Wire Line
	8350 1550 8750 1550
Wire Wire Line
	8750 1550 8750 1650
Connection ~ 8750 1650
$Comp
L Regulator_Linear:NCP1117-3.3_SOT223 U2
U 1 1 6131FE57
P 10050 1150
F 0 "U2" H 10050 1392 50  0000 C CNN
F 1 "NCP1117-3.3_SOT223" H 10050 1301 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 10050 1350 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/NCP1117-D.PDF" H 10150 900 50  0001 C CNN
	1    10050 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR026
U 1 1 61322E88
P 9500 900
F 0 "#PWR026" H 9500 750 50  0001 C CNN
F 1 "+5V" H 9515 1073 50  0000 C CNN
F 2 "" H 9500 900 50  0001 C CNN
F 3 "" H 9500 900 50  0001 C CNN
	1    9500 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 1150 9500 1150
Wire Wire Line
	9500 1150 9500 900 
$Comp
L power:GND #PWR029
U 1 1 61325E26
P 10050 1550
F 0 "#PWR029" H 10050 1300 50  0001 C CNN
F 1 "GND" H 10055 1377 50  0000 C CNN
F 2 "" H 10050 1550 50  0001 C CNN
F 3 "" H 10050 1550 50  0001 C CNN
	1    10050 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1450 10050 1550
$Comp
L power:+3V3 #PWR032
U 1 1 6132A45E
P 10650 900
F 0 "#PWR032" H 10650 750 50  0001 C CNN
F 1 "+3V3" H 10665 1073 50  0000 C CNN
F 2 "" H 10650 900 50  0001 C CNN
F 3 "" H 10650 900 50  0001 C CNN
	1    10650 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 1150 10650 1150
Wire Wire Line
	10650 1150 10650 900 
Text Notes 9150 1700 0    50   ~ 0
Power supply
Text Notes 7450 2100 0    50   ~ 0
Buck 12V to 5V
Text GLabel 2400 3650 0    50   Input ~ 0
POWER
Wire Wire Line
	2900 3650 2400 3650
$Comp
L Device:C C6
U 1 1 61175D0A
P 5650 5050
F 0 "C6" H 5765 5096 50  0000 L CNN
F 1 "100n" H 5765 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 5688 4900 50  0001 C CNN
F 3 "~" H 5650 5050 50  0001 C CNN
	1    5650 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 61176977
P 5250 5050
F 0 "C5" H 5365 5096 50  0000 L CNN
F 1 "10u" H 5365 5005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 5288 4900 50  0001 C CNN
F 3 "~" H 5250 5050 50  0001 C CNN
	1    5250 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 61176CDE
P 5650 5250
F 0 "#PWR013" H 5650 5000 50  0001 C CNN
F 1 "GND" H 5655 5077 50  0000 C CNN
F 2 "" H 5650 5250 50  0001 C CNN
F 3 "" H 5650 5250 50  0001 C CNN
	1    5650 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 61176FB0
P 5250 5250
F 0 "#PWR012" H 5250 5000 50  0001 C CNN
F 1 "GND" H 5255 5077 50  0000 C CNN
F 2 "" H 5250 5250 50  0001 C CNN
F 3 "" H 5250 5250 50  0001 C CNN
	1    5250 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4900 5650 4750
Wire Wire Line
	5650 4750 6400 4750
Connection ~ 6400 4750
Wire Wire Line
	5650 4750 5250 4750
Wire Wire Line
	5250 4750 5250 4900
Connection ~ 5650 4750
Wire Wire Line
	5250 5200 5250 5250
Wire Wire Line
	5650 5200 5650 5250
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 61191F69
P 850 3250
F 0 "J1" H 950 3600 50  0000 C CNN
F 1 "Conn_01x04_Male" H 1000 3500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 850 3250 50  0001 C CNN
F 3 "~" H 850 3250 50  0001 C CNN
	1    850  3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 611942CF
P 1150 3500
F 0 "#PWR0101" H 1150 3250 50  0001 C CNN
F 1 "GND" H 1155 3327 50  0000 C CNN
F 2 "" H 1150 3500 50  0001 C CNN
F 3 "" H 1150 3500 50  0001 C CNN
	1    1150 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3450 1150 3450
Wire Wire Line
	1150 3450 1150 3500
$Comp
L Connector:Screw_Terminal_01x03 J9
U 1 1 611C78D1
P 10200 4150
F 0 "J9" H 10280 4142 50  0000 L CNN
F 1 "Screw_Terminal_01x03" V 9500 3700 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 10200 4150 50  0001 C CNN
F 3 "~" H 10200 4150 50  0001 C CNN
	1    10200 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 4050 10000 4050
Wire Wire Line
	9700 4150 10000 4150
Wire Wire Line
	10700 4550 10700 4500
Wire Wire Line
	9700 4150 9700 4550
Wire Wire Line
	9700 4550 10700 4550
Connection ~ 9700 4550
Wire Wire Line
	9700 4550 9700 4600
$Comp
L power:GND #PWR0102
U 1 1 61209A47
P 9900 4300
F 0 "#PWR0102" H 9900 4050 50  0001 C CNN
F 1 "GND" H 9905 4127 50  0000 C CNN
F 2 "" H 9900 4300 50  0001 C CNN
F 3 "" H 9900 4300 50  0001 C CNN
	1    9900 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 4300 9900 4250
Wire Wire Line
	9900 4250 10000 4250
$Comp
L Mechanical:Heatsink HS1
U 1 1 61216347
P 9900 5100
F 0 "HS1" H 10042 5221 50  0000 L CNN
F 1 "Heatsink" H 10042 5130 50  0000 L CNN
F 2 "Heatsink:Heatsink_Fischer_SK104-STCB_35x13mm__2xDrill3.5mm_ScrewM3" H 9912 5100 50  0001 C CNN
F 3 "~" H 9912 5100 50  0001 C CNN
	1    9900 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3350 6600 3550
Wire Wire Line
	5900 3350 6600 3350
Wire Wire Line
	6600 3350 7000 3350
Connection ~ 6600 3350
$Comp
L Switch:SW_Push SW1
U 1 1 611C400F
P 1600 6150
F 0 "SW1" H 1600 6525 50  0000 C CNN
F 1 "SW_MEC_5E" H 1600 6434 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1600 6343 50  0000 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1600 6450 50  0001 C CNN
	1    1600 6150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J10
U 1 1 611C5C93
P 750 6450
F 0 "J10" H 850 6800 50  0000 C CNN
F 1 "Conn_01x04_Male" V 650 6400 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 750 6450 50  0001 C CNN
F 3 "~" H 750 6450 50  0001 C CNN
	1    750  6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 6350 1200 6150
Wire Wire Line
	950  6350 1200 6350
Wire Wire Line
	950  6450 1200 6450
Wire Wire Line
	1200 6450 1200 6550
Wire Wire Line
	1200 6550 1400 6550
Wire Wire Line
	950  6550 1100 6550
Wire Wire Line
	1100 6550 1100 7100
Wire Wire Line
	1100 7100 1400 7100
Wire Wire Line
	950  6650 1000 6650
$Comp
L power:GND1 #PWR034
U 1 1 611F4450
P 1000 7250
F 0 "#PWR034" H 1000 7000 50  0001 C CNN
F 1 "GND1" H 1005 7077 50  0000 C CNN
F 2 "" H 1000 7250 50  0001 C CNN
F 3 "" H 1000 7250 50  0001 C CNN
	1    1000 7250
	1    0    0    -1  
$EndComp
$Comp
L power:GND1 #PWR035
U 1 1 611F497C
P 1950 7250
F 0 "#PWR035" H 1950 7000 50  0001 C CNN
F 1 "GND1" H 1955 7077 50  0000 C CNN
F 2 "" H 1950 7250 50  0001 C CNN
F 3 "" H 1950 7250 50  0001 C CNN
	1    1950 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 6650 1000 7250
Wire Wire Line
	1800 6150 1950 6150
Wire Wire Line
	1800 7100 1950 7100
Connection ~ 1950 7100
Text Notes 1100 7650 0    50   ~ 0
Buttons Board
$Comp
L Switch:SW_Push SW2
U 1 1 6127F3F0
P 1600 6550
F 0 "SW2" H 1600 6450 50  0000 C CNN
F 1 "SW_MEC_5E" H 1600 6350 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2650 6700 50  0000 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1600 6850 50  0001 C CNN
	1    1600 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 6150 1200 6150
Wire Wire Line
	1950 7100 1950 7250
$Comp
L Switch:SW_Push SW3
U 1 1 6128F23B
P 1600 7100
F 0 "SW3" H 1600 7000 50  0000 C CNN
F 1 "SW_MEC_5E" H 1600 6900 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 2650 7250 50  0000 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=1371" H 1600 7400 50  0001 C CNN
	1    1600 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 6150 1950 6550
Wire Wire Line
	1800 6550 1950 6550
Connection ~ 1950 6550
Wire Wire Line
	1950 6550 1950 7100
$EndSCHEMATC
