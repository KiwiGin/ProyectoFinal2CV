#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <opencv2/opencv.hpp>
#include <vector>

class ImageProcessor {
public:
    std::vector<cv::Point2f> processFrame(const cv::Mat& frame);
    std::vector<cv::Point3f> convertTo3D(const std::vector<cv::Point2f>& points2D);

private:
    cv::Mat thresholdImage(const cv::Mat& gray);
};

#endif
