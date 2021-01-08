# PTDMProject
This is a Face Motion Capture based school project for a Measurements course
## Table of contents
* [General Info](#general-info)
* [Technologies](#technologies)
* [Components](#components)
* [Setting up the Raspberry](#setting-up-the-raspberry)
* [Building the project](#building-the-project)
* [Development Status](#development-status)
* [Credits and Bibliography](#credits-and-bibliography)

## General Info
The goal of this project is to create a facial motion capture detection system like the one in the illustration below and use it for home automation based on facial gestures, using self-sourced or open-sourced components and prototyping boards (Raspberry, Arduino, etc...).

![Facial Capture Helmet](https://www.norpix.com/applications/images/face-camera-helmet.jpg)

It is developed by students **Ioan-Alexandru Hedeș** and **Grămescu Dan-Mihai**, as a project assignment for the second year Measurement Devices and Techniques course, at the Polytechnic University of Timișoara, Romania.

## Technologies
For this project the following software technologies are used:

* [OpenCV 4.5.0](https://opencv.org/) - for image processing and pattern recognition;
* [3DF Zephyr](https://www.3dflow.net/3df-zephyr-photogrammetry-software/) - for designing Face Motion Capture models from real-life pictures;
* [3DS Max](https://www.autodesk.com/products/3ds-max/overview?support=ADVANCED&plc=3DSMAX&term=1-YEAR&quantity=1) - for designing different parts for our motion capture helmet;
* [Visual Studio Code](https://code.visualstudio.com/) - for coding remotely on the RPi through SSH;

## Components
* Raspberry Pi 4B (it should work with whatever version of the board you have) (+official charger)
* Arduino Uno Prototyping Board
* Pi NoIR V2 Camera
* nRF24L01 Wireless Transceiver Module
* microSD card (minimum 32GB)
* WS2812B Circular 16 LED Strip
* Several breadboards
* Bike helmet
* Straight aluminium rods (diameter 12mm)
* 3D-printed resin joints

## Setting up the Raspberry

**WARNING**: before continuing, it is necessary to use the official Raspberry Pi 4 Charger, it is the *only* one capable of feeding the board enough current for this project.

### Setting up Raspbian OS
[Link to installation steps](https://www.raspberrypi.org/documentation/installation/installing-images/)

### Enabling Raspberry native interfacing through different protocols
* SSH into the Pi, or connect it to a screen and fire a terminal and type ```sudo raspi-config```.
* Select ```Interfacing Options``` and enable ```Camera```, ```SPI```, ```Remote GPIO```, ```VNC``` (if you want a remote-controlled desktop environment), ```Serial```.


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

## Building the project
A building script can be found on branch ```add-basic-camera-functionality```.

## Development Status

**Note**: this is all preliminary and may drastically change with time.

### Face Recognition
Code for facial recognition can be found on branch ```add-basic-camera-functionality```.
It was written using the [OpenCV Documentation](https://docs.opencv.org/).

For face detection, an [openly available trained model](https://raw.githubusercontent.com/kurnianggoro/GSOC2017/master/data/lbfmodel.yaml) was used.


*29.12.2020* Currently, faces bigger than a certain threshold are detected, marked and the key positions on the face are tracked.
The next step is to create routines detecting some easy gestures (like blinking, or opening the mouth).
![Current progress](https://scontent.fsbz1-2.fna.fbcdn.net/v/t1.15752-9/133664750_1670144359823310_7777849030707191115_n.png?_nc_cat=100&ccb=2&_nc_sid=ae9488&_nc_ohc=h3VOXYiQByIAX9jmZlh&_nc_ht=scontent.fsbz1-2.fna&oh=6b05c37584147d4b1e4903a0dcc8b1b2&oe=601A7B2D)

### Hooking the LED Circles and RF24 module to GPIO
#### LED Circles

For easier control of LEDs using the GPIO port, the C/C++ Raspberry native wiringPi library will be used.

*05.01.2021* As per the [datasheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) of  WS2812B LEDs, they need to be powered by a 3.5-5.3V power supply. The high logic level needed to address the LEDs is based on the power supply. However, I could not get the circle to work with the 3.3V based Raspberry device.  

####RF24 radio transmission module

*Not yet in development*
Some candidate libraries for interfacing with this module will be tested after the helmet is built.

### Helmet
A cheap Bike Helmet bought from a store will be used as a base.

The camera and Raspberry will be placed in a case, mounted on iron rods connected to the helmet, with a fixed field of view on the face of the target.

The models for the components to be 3D printed can be found on branch ```add-body-3d-models```. All 3D models are self-sourced.

#### The Case Design and first attempts at 3D printing it
![Case_empty](https://cdn.discordapp.com/attachments/177419077688623104/796116953165070426/unknown.png)
![Case_full](https://cdn.discordapp.com/attachments/177419077688623104/796117099603820574/unknown.png)

*03.01.2021* The first rendition of the case suffered from a scaling problem during printing, so another one has to be done.
![Printed case](https://scontent.fsbz1-1.fna.fbcdn.net/v/t1.15752-9/135365838_3436042619953274_2375842809621320780_n.jpg?_nc_cat=106&ccb=2&_nc_sid=ae9488&_nc_ohc=xp0wdlD0JyEAX_awq9x&_nc_ht=scontent.fsbz1-1.fna&oh=b3369a8c6b3ff536a1cd384b4690f640&oe=60199E13)

*08.01.2021* The second one can house the RPi and Camera just fine, but not the LED circle. Now we have insight on how to make a better one to accomodate the wires without bends.
![Prototype](https://scontent.fsbz1-2.fna.fbcdn.net/v/t1.15752-9/136663733_247118643483240_4503122424718875494_n.jpg?_nc_cat=100&ccb=2&_nc_sid=ae9488&_nc_ohc=7jSSF-qAjYAAX8TBgqX&_nc_ht=scontent.fsbz1-2.fna&oh=9e15d24b37f87782322d6e45c3a5905c&oe=601D636F)

#### Ratchet Clutch 
Used for adjusting the position of the camera case on the helmet (up/down).
![Ratchet Clutch](https://cdn.discordapp.com/attachments/177419077688623104/797201097449406514/unknown.png)

#### Joints for fixing the metal rods on the helmet
Angular piece for joining two rods:
![Angular joint](https://cdn.discordapp.com/attachments/177419077688623104/796131425077821510/unknown.png)


Clam for:
* attaching the rods to the ratchet (2x);
* attaching the raspberry case to the rods (2x);
These clams are screwed onto the helmet, or case respectively.

![Clam](https://cdn.discordapp.com/attachments/177419077688623104/796132164999053312/unknown.png)

### Bonus: creating an animated face model using our faces
Why only use our Facial Tracking System for home automation? Why not use the facial data to animate a model in computer graphics software?

This is a little side-quest of ours, trying to map our faces into 3DF Zephyr, to be animated later using the captured data from the Raspberry Camera:
![Face angle 1](https://cdn.discordapp.com/attachments/177419077688623104/796115778133950464/unknown.png)
![Face angle 2](https://cdn.discordapp.com/attachments/177419077688623104/796115847546273802/unknown.png)

## Credits and Bibliography
* [Menache, Alberto. Understanding Motion Capture For Computer Animation - Second Edition. Elsevier, 2011](https://www.elsevier.com/books/understanding-motion-capture-for-computer-animation/menache/978-0-12-381496-8)
* [Kurnianggoro's FaceMark pre-trained model](https://raw.githubusercontent.com/kurnianggoro/GSOC2017/master/data/lbfmodel.yaml)
