#!/bin/bash
echo "Building main file..."
g++ -Wall -o main main.cpp -I /usr/local/include -L /usr/local/bin -lopencv_videoio -lopencv_core -lopencv_highgui
echo "Done;"
