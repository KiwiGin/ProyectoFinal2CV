#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glut.h>
#include <vector>
#include <opencv2/opencv.hpp>

class Renderer {
public:
    void initOpenGL();
    void render(const std::vector<cv::Point3f>& points3D);
};

#endif
