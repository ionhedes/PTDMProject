/**
 * This is an example taken from the official OpenCV documentation
 * which prints video from a stream to a window on the screen;
 */

#include <opencv2/opencv.hpp>
#include <iostream>
// #include <RF24/RF24.h>

int main(void)
{
    cv::VideoCapture vc(0, cv::CAP_ANY);
    
    // Check if the video stream was successfully opened;
    if (vc.isOpened() == false)
    {
        std::cout << "Failed to open video stream from camera;\n";
        return -1;
    }
    
    while (1)
    {
        cv::Mat frame;
        vc >> frame;

        if (frame.empty())
        {
            std::cout << "Next frame not captured;\n";
            return -1;
        }
        cv::imshow("Frame", frame);
    
        // At every frame, wait to see if the user inputs the ESC key;
        char ctrl_c = (char)cv::waitKey(25);
        if (ctrl_c == 27)
        {
            break;
        }
    }
    
    // Before exiting, release all video capture objects;
    // Also destroy the windows created by imshow();
    vc.release();
    cv::destroyAllWindows();

    return 0;
}
