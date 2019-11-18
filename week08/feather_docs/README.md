# Adafruit Feather nRF52840
!(Adafruit Logo)[https://www.adafruit.com/includes/templates/shop2019/images/adafruit-logo.png]

## SDK
### Drivers
To install the drivers, you know where to go by now. 

### API
(Arduino Bluefruit nRF52 API reference)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/bluefruit-nrf52-api]
The API is class-based, with the following classes being most commonly used (from Adafruit's documentation):
* (AdafruitBluefruit)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/adafruitbluefruit] - the essential most-used class
* (BLEService)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/bleservice] - wrapper class for (BLE GATT)[https://learn.adafruit.com/introduction-to-bluetooth-low-energy/gatt] custom services.
* (BLECharacteristic)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/blecharacteristic] - wrapper class for (BLE GATT)[https://learn.adafruit.com/introduction-to-bluetooth-low-energy/gatt] custom characteristics.
* (BLEDis)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/bledis] - helper for Device Information Services.
* (BLEUart)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/bleuart] - helper for (Nordic UART Service)[https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v15.2.0%2Fgroup__ble__nus.html]
* (BLEBeacon)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/blebeacon] - helper class to use the device as a Bluetooth beacon using the BT advertising packet.
* (BLEMidi)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/blemidi] - helper class to use MIDI data (audio, etc) over Bluetooth.
* (BLEHidAdafruit)[https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/blehidadafruit] - is a helper class to emulate an HID mouse or keyboard over BLE. (Related project)[https://learn.adafruit.com/circuitpython-essentials/circuitpython-hid-keyboard-and-mouse]

### Languages
* C++ (the default)
* [CircuitPython](https://circuitpython.org/) 

### IDEs
The Feather supports the usage of the Arduino IDE, but the IDE doesn't include the support out of the box. To install:
1. Download and install the Arduino IDE (At least v1.6.12)
2. Start the Arduino IDE
3. Go into Preferences
4. Add https://www.adafruit.com/package_adafruit_index.json as an 'Additional Board Manager URL'
5. Restart the Arduino IDE
6. Open the Boards Manager from the Tools -> Board menu and install 'Adafruit nRF52 by Adafruit'
7. Once the BSP is installed, select 'Adafruit Bluefruit nRF52 Feather' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the nRF52.
8. Write, compile, upload over USB.



#### Set up CircuitPython Quick Start
https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/circuitpython

##### Board Testing

1. Select the Board Target
2. Select the USB CDC Serial Port
3. Update the bootloader (nRF52832 Feather Only)
4. Run a Test Sketch
https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/arduino-board-setup

##### CircuitPython for nRF53840 Download
https://circuitpython.org/board/feather_nrf52840_express/

##### BootLoader & Source Code
https://github.com/adafruit/Adafruit_nRF52_Bootloader/releases/tag/0.2.13

#### Libraries

##### Adafruit nRF52 Library

- dafruit-nrfutil is based on Nordic Semiconductor ASA's pc-nrfutil
- freeRTOS as operating system
- tinyusb as usb stack
- nrfx for peripherals driver
- littlefs for internal file system

https://github.com/adafruit/Adafruit_nRF52_Arduino/tree/master/libraries

##### Adafruit Sponsored Libraries and Drivers from CircuitPython 

https://github.com/adafruit/Adafruit_CircuitPython_Bundle/blob/master/docs/drivers.rst

#### Bluefruit App

##### Using your iOS or Android phone/tablet as a controller

A USB bootloader lets you quickly use it with the Arduino IDE or to install CircuitPython.

###### Sent data Format
Each Controller data packet sent is prefixed with single byte char “!” (0x21) followed by a single byte char initial for identification.
Sensor data values are encoded as floats of 4 byte length.  
Each packet ends with a single byte checksum for validation.

###### Controller Test
https://github.com/CollinCunningham/BLE_UART_Controller_Test/blob/master/BLE_UART_Controller_Test.ino


- Sensors
Quaternion, Accelerometer, Gyro, Magnetometer and Location (GPS)

- 8-button Control Pad
![colourPicker](projects_IMG_2694.jpg)

- Colour Picker
![colourPicker](projects_ColorPicker.jpg)

