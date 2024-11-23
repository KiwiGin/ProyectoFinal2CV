#include "ImageProcessor.h"

std::vector<cv::Point2f> ImageProcessor::processFrame(const cv::Mat& frame) {
    cv::Mat gray, flippedFrame, thresh;

    // Voltea la imagen verticalmente (flipCode = 0) o horizontalmente (flipCode = 1)
    cv::flip(frame, flippedFrame, 0); // Voltea la imagen en el eje y

    // Convertir a escala de grises y aplicar umbral
    cv::cvtColor(flippedFrame, gray, cv::COLOR_BGR2GRAY);
    thresh = thresholdImage(gray);
    thresh = thresholdImage(gray);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<cv::Point2f> points2D;
    for (const auto& contour : contours) {
        for (const auto& point : contour) {
            points2D.push_back(point);
        }
    }
    return points2D;
}

std::vector<cv::Point3f> ImageProcessor::convertTo3D(const std::vector<cv::Point2f>& points2D) {
    std::vector<cv::Point3f> points3D;
    for (const auto& point : points2D) {
        float x = point.x / 100.0f - 1.0f;
        float y = point.y / 100.0f - 1.0f;
        float z = 0.0f;
        points3D.push_back(cv::Point3f(x, y, z));
    }
    return points3D;
}

cv::Mat ImageProcessor::thresholdImage(const cv::Mat& gray) {
    cv::Mat thresh;
    cv::threshold(gray, thresh, 128, 255, cv::THRESH_BINARY);
    return thresh;
}
