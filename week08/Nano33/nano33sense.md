# Arduino Nano 33 Sense Board (BLE)

> NB: Pins A2 an A3 on the CCI board are probably not working due to some soldering mishaps. Take your time when soldering header pins on a new board! Use a breadboard to make sure the pins start off in exactly the right place.

![Board Photo](https://store-cdn.arduino.cc/uni/catalog/product/cache/1/image/520x330/604a3538c15e081937dbfbd20aa60aad/a/b/abx00030_featured.jpg)

## Intro

The Arduino NANO 33 BLE (Bluetooth Low Energy) Sense board has been designed to offer a low power and cost effective solution for makers seeking to have Bluetooth Low Energy connectivity in their projects. It has a number of sensors built in to the board such as an _Inertial Measurement Unit (IMU)_, _Digital Microphone_, _Gesture Sensor_, _Pressure and Temperature Sensor_ and a _Relative Humidity Sensor_, more details on these later.

The brains of the board is the [NINA B306 module](https://www.u-blox.com/sites/default/files/NINA-B3_DataSheet_%28UBX-17052099%29.pdf) and the [Nordic nRF52840](https://infocenter.nordicsemi.com/pdf/nRF52840_PS_v1.1.pdf) that contains a [Cortex M4F](https://developer.arm.com/ip-products/processors/cortex-m/cortex-m4) microcontroller (ARM). The USB connector of the board is directly connected to the native USB of the NINA B306 module. This routing enables you to use the Arduino NANO 33 BLE Sense as a client USB peripheral (acting as a mouse or a keyboard connected to the computer) or as a USB host device so that devices like a mouse, keyboard, or an Android phone can be connected to the Arduino NANO 33 BLE.

## Specification

| Thing        | Type |
|:-------------|:-----|
| Connectivity | BLE 5.0 |
| Chip         | NINA-b3 (nRF52840) |
| Clock        | 64 MHz |
| Memory       | 1 MB (Flash), 256 SRAM |
| Interfaces   | USB Micro-B, SPI, I2C, I2S, UART |
| Voltages | 5V Input (USB), 4.5-21V Vin, 3.3V Operating |
| Pinout | 14 Digital, 6 PWM, 8 Analog |
| Dimensions | 18 x 45mm |


## Installation

You need to install the Arduino nRF528x mbed Core to your Ardiuno IDE before you can upload code to your board, which is unlike most Arduino boards. This is done by going to _Tools > Boards > Boards Manager_ and searching for _nano 33 ble_ (as below):

![Driver installation](https://www.arduino.cc/en/uploads/Guide/MBED_Board_Insta.jpg)

__NOTE:__ this core is made of many files and the installation process may require a few minutes, please be patient while the process is executed and it is normal that the progress bar stays for a long time on the same spot.

The Arduino NANO 33 BLE Sense is a hardware variation of the Arduino NANO 33 BLE; both boards are recognized as Arduino NANO 33 BLE and this is normal. In the board manager and the board selection, you will find listed only the Arduino NANO 33 BLE.

If you see an error similar to the error below in your Arduino IDE, you may also need to install a G++ compiler:


```c++
C:\\Users\\username\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\arm-none-eabi-gcc\\7-2017q4/bin/arm-none-eabi-g++
```

Head to the [GNU Compiler Collection (GCC)](https://gcc.gnu.org/) for more information. It's the sort of thing which will be specific to your machine and operating system, but a quick for __G++ Compiler Mac__ yeilded results on Aleksi's machine. If you see a compiler error in the Arduino IDE after having installed GCC, you may need to __re-install__ the nRF528x mbed core. To do this delete this folder `/Users/username/Library/Arduino15/packages/arduino` and then re-install the core above. You should now be ready to use the board!

## Is it all working?

You can now upload the classic Arduino 'Hello World' Blink sketch found in `File > Examples > Basics > Blink` to the board and you should see the built-in LED blink.

## Pinout

|Pin|Function|Type|Description
|:---|:---|:---|:---|
|1 |D13/SCK|Digital|SPI SCK; GPIO|
|2 |+3V3|Power Out|Internally generated power output to external devices|
|3 |AREF|Analog|Analog Reference; can be used as GPIO|
|4 |A0|Analog|ADC in; can be used as GPIO|
|5 |A1|Analog|ADC in; can be used as GPIO|
|6 |A2|Analog|ADC in; can be used as GPIO|
|7 |A3|Analog|ADC in; can be used as GPIO|
|8 |A4/SDA|Analog|ADC in; I2C SDA; Can be used as GPIO (\*)|
|9 |A5/SCL|Analog|ADC in; I2C SCL; Can be used as GPIO(\*)|
|10 | A6|Analog|ADC in; can be used as GPIO|
|11 | A7|Analog|ADC in; can be used as GPIO|
|12 | VUSB |Power In/Out|Normally NC; can be connected to VUSB pin of the USB connector by shorting a jumper|
|13 | RST|Digital In|Active low reset input (duplicate of pin 18)|
|14 | GND|Power|Power Ground|
|15 | VIN|Power In|Vin Power input|
|16 | TX|Digital|USART TX; can be used as GPIO|
|17 | RX|Digital|USART RX; can be used as GPIO|
|18 | RST|Digital|Active low reset input (duplicate of pin 13)|
|19 | GND|Power|Power Ground|
|20 | D2|Digital|GPIO|
|21 | D3/PWM|Digital|GPIO; can be used as PWM|
|22 | D4|Digital|GPIO|
|23 | D5/PWM|Digital|GPIO; can be used as PWM|
|24 | D6/PWM|Digital|GPIO; can be used as PWM|
|25 | D7|Digital|GPIO|
|26 | D8|Digital|GPIO|
|27 | D9/PWM|Digital|GPIO; can be used as PWM|
|28 | D10/PWM|Digital|GPIO; can be used as PWM|
|29 | D11/MOSI|Digital|SPI MOSI; can be used as GPIO|
|30 | D12/MISO|Digital|SPI MISO; can be used as GPIO|

## MIDI Controller Example Project

![Project Image](https://hackster.imgix.net/uploads/attachments/1012929/_bbQyIDflF5.blob?auto=compress%2Cformat&w=900&h=675&fit=min)

[This project](https://create.arduino.cc/projecthub/arichetta/air-drum-with-arduino-nano-33-iot-8e9d45?ref=platform&ref_id=424_trending___&offset=8) by Andrea Richetta demonstrates that with very little code, you can use the IMU built into the board and the USB to MIDI feature on the board (thanks to the ARM based chip, also available on atmega32u4 based boards) to appear as a MIDI peripheral over USB to a connected computer.

## Features

__Multiple Serial:__ The RX0 and TX1 pins are a second serial port available as `Serial1` (most Arduino boards have a single Serial I/O).

__ADC and PWM resolutions:__ The Arduino NANO 33 BLE has the ability to change its analog read resolution: it defaults to 10-bits and it can support up to 12-bit ADC. PWM has 8-bit resolution.

__IMU on the Arduino NANO 33 BLE Sense:__ The IMU is a LSM9DS1, it is a 3-axis accelerometer, 3-axis gyroscope and 3-axis magnetometer and is supported by the [ArduinoLSM9DS1 Library](https://www.arduino.cc/en/Reference/ArduinoLSM9DS1). 

__Digital Microphone:__ The digital microphone is a MP34DT05. This chip, made by ST Microelectronics, is an ultra-compact, low-power, omnidirectional, digital MEMS microphone built with a capacitive sensing element and an IC interface; it produces an output coded in [PDM (Pulse Density Modulation)](https://en.wikipedia.org/wiki/Pulse-density_modulation) which is compatible with the [Arduino Sound](https://www.arduino.cc/en/Reference/ArduinoSound) library. 

__Gesture Sensor:__ The APDS9960 chip senses gesture, color, ambience illumination and proximity which can be used with the [ArduinoAPDS9960 Library](https://www.arduino.cc/en/Reference/ArduinoAPDS9960).

__Pressure and Temperature:__ The barometer and temperature sensor is a HTS221 which functions as a digital output barometer and is supported by the [ArduinoLPS22HB Library](https://www.arduino.cc/en/Reference/ArduinoLPS22HB).

__Relative Humidity:__ The relative humidity sensor is a HTS221 which is capable of detecting relative humidity variations, returned as digital output on a serial interface. This chip is supported by the [ArduinoHTS221 Library](https://www.arduino.cc/en/Reference/ArduinoHTS221).

## __PLEASE NOTE:__

The microcontroller on the Arduino NANO 33 BLE Sense runs at 3.3V, which means that __you must never apply more than 3.3V to its Digital and Analog pins.__ Care must be taken when connecting sensors and actuators to assure that this limit of 3.3V is never exceeded. __Connecting higher voltage signals, like the 5V commonly used with the other Arduino boards, will damage the Arduino NANO 33 BLE Sense.__

> This guide was written by Aleksi Halttunen and Josh Murr (Creative Coding MSc, 2019)
