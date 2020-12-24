# PTDMProject
This is a Face Motion Capture based school project for a Measurements course
## Table of contents
* [General Info](#general-info)
* [Technologies](#technologies)
* [Components](#components)
* [Setup](#setup)
* [Building](#building)

## General Info
This is a simple project involving detecting face gestures and translating them into commands given to systems performing automated tasks, using common prototyping boards and technologies (Raspberry, Arduino, etc..).
It is developed as a project assignment for the second year Measurement Devices and Techniques course, at the Polytechnic University of Timișoara, Romania.

## Technologies
For this project the following software technologies are used:

* [OpenCV 4.5.0](https://opencv.org/)

## Components
* Raspberry Pi 4B (it should work with whatever version of the board you have)
* Arduino Uno Prototyping Board
* Pi NoIR V2 Camera
* nRF24L01 Wireless Transceiver Module
* microSD card (minimum 32GB)
* WS2812 Circular LED Strip

## Setup

### Setting up Raspbian OS
[Link to installation steps](https://www.raspberrypi.org/documentation/installation/installing-images/)

### Installing OpenCV 4.5.0 on Raspberry PI
[Link to installation steps](https://qengineering.eu/install-opencv-4.1-on-raspberry-pi-4.html)

**Note**: By default, by referencing the Makefile downloadable from the given link, OpenCV will be installed under
```CMAKE_INSTALL_PREFIX=/usr/local```

In the following lines, we will be referring to the installation path as to ```CMAKE_INSTALL_PREFIX```, just in case you want to install it elsewhere.

OpenCV will work out of the box if you want to use Python3, but for C++, the following tweak has to be made:
* After a default installation, the ```.hpp``` headers are located in ```CMAKE_INSTALL_PREFIX/include/opencv4/opencv2/```.
However, headers expect themselves to have an absolute path that looks like this: ```CMAKE_INSTALL_PREFIX/include/opencv2/```. Including and using them in source files will **not be possible** with the current folder tree. 
Use ```sudo cp -r CMAKE_INSTALL_PREFIX/include/opencv4/opencv2 CMAKE_INSTALL_PREFIX/include/``` to fix this issue.

### Installing libraries for interfacing RF24 with the Raspberry Pi
[Link to installation steps](https://www.hackster.io/wirekraken/connecting-an-nrf24l01-to-raspberry-pi-9c0a57)

## Building
**Note**: this is all preliminary and may drastically change with time.

Will be added in future commit
