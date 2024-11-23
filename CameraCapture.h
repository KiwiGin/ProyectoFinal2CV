#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include <opencv2/opencv.hpp>

class CameraCapture {
public:
    bool init(int cameraIndex);
    cv::Mat captureFrame();

private:
    cv::VideoCapture cap;
};

#endif
