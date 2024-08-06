# Micro:Bit OLED UI Demo

## A tech demo for the BBC Micro:Bit (V2) that demosrates a UI that can be navigated via the onboard A and B buttons. Orginally built for an revision to my educational toy called Plush:Bit. The code also has a section for math problem generation.

## Project assembly:

- Using a Micro:Bit (V2), micro:bit edge pin breakout board, breadbaord, and a I2C 1306 OLED.
- Connect the VCC and GND of the OLED to the 3V3 and GND to the microbit breakout.
- On the V2, SCL is 19 and SDA is 20

## Setup in Ardunio IDE

* Add the micro:bit in Additional Board Manager URLs:

```
https://sandeepmistry.github.io/arduino-nRF5/package_nRF5_boards_index.json

```

* Install the following Ardunio Libaries 
  - micro:bit by Adafruit
  - MicrobitV2-HHS by Grrtzm
  - Adafruit_SSD1306
  - Adafruit GFX

* Download the V0.1.ino file from the repo.

* Open it in Ardunio IDE

* Plug in the baord and select "micro:bit V2" in the proper serial port

* Select Upload, wait for the micro:bit to finish flashing
