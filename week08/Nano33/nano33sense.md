# Arduino Nano 33 Sense Board (BLE)

> NB: Pins A2 an A3 on the CCI board are probably not working.

## Intro

The Arduino NANO 33 BLE Sense board has been designed to offer a power savvy and cost effective solution for makers seeking to have Bluetooth Low Energy connectivity in their projects. It has a number of sensors built in to the board such as an _Inertial Measurement Unit (IMU)_, _Digital Microphone_, _Gesture Sensor_, _Pressure and Temperature Sensor_ and a _Relative Humidity Sensor_.

The brains of the board is the [NINA B306 module](https://www.u-blox.com/sites/default/files/NINA-B3_DataSheet_%28UBX-17052099%29.pdf) and the [Nordic nRF52840](https://infocenter.nordicsemi.com/pdf/nRF52840_PS_v1.1.pdf) that contains a [Cortex M4F](https://developer.arm.com/ip-products/processors/cortex-m/cortex-m4) microcontroller (ARM). The USB connector of the board is directly connected to the native USB of the NINA B306 module. This routing enables you to use the Arduino NANO 33 BLE Sense as a client USB peripheral (acting as a mouse or a keyboard connected to the computer) or as a USB host device so that devices like a mouse, keyboard, or an Android phone can be connected to the Arduino NANO 33 BLE.

## Specification

| Thing        | Type |
|:-------------|:-----|
| Connectivity | BLE 5.0 |
| Chip         | NINA-b3 (nRF52840) |
| Clock        | 64 MHz |
| Memory       | 1 MB (Flash), 256 SRAM |
| Interfaces   | USB, SPI, I2C, I2S, UART |
| Voltages | 5V Input (USB), 4.5-21V Vin, 3.3V Operating |
| Pinout | 14 Digital, 6 PWM, 8 Analog |
| Dimensions | 18 x 45mm |


## Installation

You need to install the Arduino nRF528x mbed Core to your Ardiuno IDE before you can upload code to your board. This is done by going to _Tools > Boards > Boards Manager_ and searching for _nano 33 ble_:

![Driver installation](https://www.arduino.cc/en/uploads/Guide/MBED_Board_Insta.jpg)

You may also need to install a G++ compiler if you don't have this already installed. (See relevant steps for your machine). If you do see a compiler error in the Arduino IDE, after having installed GCC, you may need to __re-install__ the nRF528x mbed core. To do this delete this folder `/Users/username/Library/Arduino15/packages/arduino` and then re-install the core above. 

## __PLEASE NOTE:__

The microcontroller on the Arduino NANO 33 BLE Sense runs at 3.3V, which means that __you must never apply more than 3.3V to its Digital and Analog pins.__ Care must be taken when connecting sensors and actuators to assure that this limit of 3.3V is never exceeded. __Connecting higher voltage signals, like the 5V commonly used with the other Arduino boards, will damage the Arduino NANO 33 BLE Sense.__
