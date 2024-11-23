#include "CameraCapture.h"

bool CameraCapture::init(int cameraIndex) {
    cap.open(cameraIndex);
    return cap.isOpened();
}

cv::Mat CameraCapture::captureFrame() {
    cv::Mat frame;
    cap >> frame;
    return frame;
}
