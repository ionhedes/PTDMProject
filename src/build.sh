#!/bin/bash
echo "Building main file..."
g++ -Wall -o main main.cpp -I /usr/local/include -L /usr/local/bin -lopencv_videoio -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_objdetect -lopencv_face
echo "Done;"
