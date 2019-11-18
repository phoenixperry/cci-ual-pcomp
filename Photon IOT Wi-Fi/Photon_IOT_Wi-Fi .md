# Photon IOT Wi-Fi 

## Hookup and Pins

//BY Chong In Lei

## To Set up 
https://docs.particle.io/quickstart/photon/

![the app](https://blog.particle.io/wp-content/uploads/2019/09/app30design.jpg)

Here is the official web link to tell you how to setup your component and the basic pins to control the outcome. 

Set up your own Wifi (hotspot) and connect it to Photon via the app. (The WiFi is your own hotspot!!!! Not any wifi from the board!!!)

[![setup and blink tutorial](https://docs.particle.io/assets/images/photon-kit-new.jpg)](https://vimeo.com/178282058)

### Pins and Structure

[![Photon Board Detail](https://www.electronicwings.com/public/images/user_images/images/Particle_Photon/What%20is%20particle%20photon/Pin%20details%20copy2.jpg)](https://www.electronicwings.com/particle/particle-photon-board)

D7 is the pin with LED on it, so you don't really need to connect to a breadboard to test its connectivity. 

After you have setup through the app "Particle IoT" (ios/android), with set WiFi, go to the "Tinker" on the app and you can start control. 

As D7 comes with LED, you don't need to connect to any components for first time. Press D7 and set this as digitalWrite and this LED will lights up when it is HIGH, and off when it is LOW. 

Or if you are connected to a breadboard, simply hook up a LED on the pin A0-A7 (only A0-A5 shown on board, A6 and A7 are invisible but should be refer to DAC and WKP) and D0-D7.

#### D0-D7 => GIO pins

A GPIO pin is a 'general purpose input/output' pin. This is by default only high or low (voltage levels, high being the micro controller's supply voltage, low usually being ground, or 0V). But the levels of 'high' and 'low' are usually given as voltages as a proportion of the supply voltage. So anything usually above 66% of the supply voltage is considered a logic level 'high' which means some lower voltage devices can talk with high voltage devices as long as the levels fall within what is considered 'high'. A 1.8–2.7V low power microcontroller or GPS receiver for example will have trouble communicating directly to a 5V microcontroller because what the low voltage device sees as 'high' the higher voltage device will not think it's high at all. This is for using GPIO as an input pin, and output is basically the same - the output high is based on the supply of the controller, where it will drive current out and set the voltage of that pin to VCC, or sink current and pull the pin to 0V for a logic 'low'.

// information from https://electronics.stackexchange.com/questions/104456/understanding-gpio-analog-and-digital 

#### A0-A7 => analog-to-digital

In electronics, an analog-to-digital converter (ADC, A/D, or A-to-D) is a system that converts an analog signal, such as a sound picked up by a microphone or light entering a digital camera, into a digital signal. An ADC may also provide an isolated measurement such as an electronic device that converts an input analog voltage or current to a digital number representing the magnitude of the voltage or current. Typically the digital output is a two's complement binary number that is proportional to the input, but there are other possibilities.
// https://en.wikipedia.org/wiki/Analog-to-digital_converter   https://learn.sparkfun.com/tutorials/analog-to-digital-conversion/all 

The Arduino can input and output analog signals as well as digital signals. An analog signal is one that can take on any number of values, unlike a digital signal which has only two values: HIGH and LOW. ... The function used to output a PWM signal is analogWrite(pin, value). pin is the pin number used for the PWM output.

// https://www.allaboutcircuits.com/projects/using-the-arduinos-analog-io/

### Pin Detail Diagram of Particle Photon

3V3: This pin is the output of the on-board regulator and is internally connected to the VDD of the Wi-Fi module. When powering the Photon via VIN or the USB port, this pin will output a voltage of 3.3VDC. This pin can also be used to power the Photon directly (max input 3.3VDC).

NOTE: When powering the Photon via this pin, do not put power on the VIN pin.

GND

WKP: This is an active-high input that allows you to wake-up the module from sleep/deep sleep modes. When not used as a WAKEUP, this pin can also be used as a digital GPIO, 

ADC input or PWM.

VIN: This is the power supply pin to the Photon with a voltage range of 3.6 to 5.5VDC (internally regulated down to 3.3VDC). When the Photon is powered via its USB port, this pin will output a voltage of approximately 4.7VDC.

Why 4.7 and not 5?

Well, the actual voltage will be the USB voltage, which is normally 5, minus the forward voltage drop (0.3V) of the protection diode.

D0 - D7: These are digital only GPIO pins.

A0 - A5: These can be used as digital GPIOs or as ADC inputs channels.

DAC: This pin can be used as a digital GPIO, ADC input or as a DAC output.

RX: Primarily used as UART RX, but can also be used as a digital GPIO, ADC input or PWM.

TX: Primarily used as UART TX, but can also be used as a digital GPIO, ADC input or PWM.

PWM: It has On-board 9 pins or channels (i.e. D0, D1, D2, D3, A4, A5, WKP, RX and TX) for PWM generation. The PWM pins are shown in above image named as TIMx_CHx i.e. 

TIM3_CH1, TIM3_CH2, etc.

RST: This is an active-low reset pin for the Photon.

VBAT: Supply to the internal RTC, backup registers and SRAM (1.8 to 3.3VDC).

SPI: It has two On-board hardware SPI, namely SPI and SPI1.
      The SPI pins on Particle Photon are as follows,

SPI                                                             SPI1          

SS         - A2 (default)                                SS         - D5 (default)

SCK      - A3                                                SCK       - D4

MISO   - A4                                                MISO    - D3

MOSI   - A5                                                MOSI    - D2

I2C: It has one I2C port. SDA and SCL pins are available on D0 and D1 pin respectively.

//information from https://www.electronicwings.com/particle/particle-photon-board 



# SDKS 

//BY Yunhan-Wang

Photon is now available on **macOS*** and **Windows** platforms and will soon be available for Linux.

##  Installation
[The official website](https://www.particle.io/)

This tutorial is about how to connect it to the app.
https://www.youtube.com/watch?v=0nQia-OYfbw

![](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/Week8/IMG_9458.jpg)

### Now you can use your software on your phone to control this loT WI-FI board. 
There is an LED on the board, on the D7 pin. 
![](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/Week8/D7.JPG)

1. You can control the low and high of pin in the tinker part of the software.
![](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/Week8/IMG_9463.JPG)

2. You can also enter code to make changes to the LED（D7 pin） on the board or the parts connected to the board.

This is the web side of the app, and you can type in the code here. 👉 
[Particle build](https://build.particle.io/build/new)
(At the end of the video tutorial in part 1, there is information about how to enter code.) 

 ![](https://github.com/Yunhan-Wang/Arduino-Homework/blob/master/Week8/website.png)


# Particle Photon

//BY XIAOJIE LIN and Lan Yang

## Definition:

Photon is a miniature Wi-Fi IoT device for creating connected projects and products for the Internet of Things. It's easy to use, powerful and connected to the cloud. Particles combine the powerful STM32 ARM Cortex M3 microcontroller with the BCM43362 Wi-Fi chip in a miniature thumbnail module called PØ (P-zero)

## Particle's core philosophy:

Help rapid IoT product development with a cloud-based hardware development platform.

Help enable cloud connectivity from a single prototype to a high-volume finished product with a cloud platform.

Help manage online hardware products

## Using cases:

![alt text](https://github.com/lalisa777/xiaojielin/blob/master/Advanced%20Physical%20Computing/file/1.png)

* Step 1: Tools and Components

![alt text](https://github.com/lalisa777/xiaojielin/blob/master/Advanced%20Physical%20Computing/file/2.png)

Particle Photon

Breadboard

LEDs

220ohm Resistor

Micro USB Cable

* Step 2: Getting the Photon Connected

![alt text](https://github.com/lalisa777/xiaojielin/blob/master/Advanced%20Physical%20Computing/file/2.png)

First before we start to program a board you need to open up the web based ide for the particle photon. You can do this by creating an account at Particle website. After registering for an account next we need to claim the photon to your account. This can be done by two ways one uses an android phone to claim the photon and next uses particle CLI (Terminal Application) to claim your core. I will be showing you how to do it both the ways.

First I will show you how to claim your photon using a smart phone either android or Iphone. Start by going to the play store or apple store and downloading the Particle.io application.

Next login in to the application and click on the add new photon icon. Plug in the core and you should see it blinking blue, connect your phone to the WiFi network though which your photon connects to the internet. And you should see your photon on the app. Next enter your WiFi details and your photon will blink green indicating it is trying to connect to the WiFi network and then it will fade cyan (indicating successful connection). Now you are ready to upload your code to the photon.

* Step 3: Getting Photon Connected Via CLI

![alt text](https://github.com/lalisa777/xiaojielin/blob/master/Advanced%20Physical%20Computing/file/3.png)

Another way to get your photon connected to the particle cloud is via CLI (Terminal). For this you will need to install nodeJs, you can download it from here and install it. This method does not need an smart phone to get the photon setup.

Then enter the below command to install particle CLI, make user to run it in administrative or root privileges.

npm install particle-cli
After installing the particle cli, connect your core to the computer (via micro USB) and run the below command.

particle setup
Follow the on screen instructions and you should have you photon breathing cyan and you are now ready to upload the code.

* Step 4: Hardware

![alt text](https://github.com/lalisa777/xiaojielin/blob/master/Advanced%20Physical%20Computing/file/4.png)

Before we upload the code to the photon lets, add an led to the photon. The anode of the LED connects to the D0 pin of the photon and the cathode pin connects to the Gnd pin of the photon via a 220ohm resistor.

You can test out the connections by using the particle app to control the led by changing the state of the D0 pin to digital write and then set it to high and you should see the led glow and turn it off by setting the state of the pin to low.

If you got the led to glow, next lets upload the code to the arduino and control it over the internet.

* Step 5: Code Upload

![alt text](https://github.com/lalisa777/xiaojielin/blob/master/Advanced%20Physical%20Computing/file/5.png)

Now to upload the code you will need to visit particles web based IDE and paste in the below code and then select the photon from the list of devices on the left of your screen. And then give the new program a name and hit flash. You should see your photon blink pink indicating that the code is uploading on to the board. After uploading the reset and connect to the internet.


## More examples from others

https://github.com/johnsdiyplayground/Particle-Photon

https://youtu.be/LkH4tAueexc

https://youtu.be/0nQia-OYfbw
