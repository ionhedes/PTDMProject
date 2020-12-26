/*
 * Driver source code for the project;
 * 
 * How it works?
 *  - faces are detected using the pretrained LBP Cascades included in the OpenCV libraries;
 *  - the facial traits are found using the FacemarkAPI, and the trained model lbfmodel.yaml;
 * 
 * Current development status:
 *  - faces are being detected and their landmarks drawn on top of the video feed;
 *  - for good detection, the face must be properly lit;
 *  - nothing else is done with the facemarks, in the future this data will be used to determine different facial gestures;
 * 
 * The trained model for the face landmarking, lbfmodel.yaml belongs to Github user kurnianggoro
 * https://github.com/kurnianggoro/GSOC2017
*/

#include <opencv2/opencv.hpp>
#include <opencv2/face/facemarkLBF.hpp>
#include <iostream>
// #include <RF24/RF24.h>

// Necessary objects for facemarking;
cv::Ptr<cv::face::Facemark> facemark = cv::face::createFacemarkLBF();
cv::face::CParams params("/home/pi/opencv/data/lbpcascades/lbpcascade_frontalface.xml");

void detectLandmarks(cv::Mat &frame)
{
    std::vector<cv::Rect> faces;
    std::vector<std::vector<cv::Point2f> > landmarks;

    // Detect the faces using the LBP Cascade;
    cv::face::getFaces(frame, faces, &params);
    // For each face, find the facial traits (eyes, nose, etc..);
    facemark->fit(frame, faces, landmarks);
    
    // Mark each face inside the frame;
    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::face::drawFacemarks(frame, landmarks [i], cv::Scalar(0, 0, 255));
    }
}

int main(void)
{
    // Load the face landmarking model;
    facemark->loadModel("/home/pi/Documents/PTDMProject/lbfmodel.yaml");

    // Load the video stream from the camera;
    cv::VideoCapture vc(0, cv::CAP_ANY);
    if (vc.isOpened() == false)
    {
        std::cout << "Failed to open video stream from camera;\n";
        return -1;
    }
    
    // Process frames, one by one;
    while (1)
    {
        cv::Mat frame;
        vc >> frame;

        if (frame.empty() == true)
        {
            std::cout << "Next frame not captured;\n";
            return -1;
        }

        // Detect and mark faces inside the frame, and then print it;
        detectLandmarks(frame);
        cv::imshow("Frame", frame);
    
        // Check if the abort key wasn't pressed;
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
