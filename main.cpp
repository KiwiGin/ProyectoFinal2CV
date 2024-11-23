#include <GL/glut.h>
#include "CameraCapture.h"
#include "ImageProcessor.h"
#include "Renderer.h"

CameraCapture camera;
ImageProcessor processor;
Renderer renderer;

void displayCallback() {
    // Captura un cuadro de la cámara
    cv::Mat frame = camera.captureFrame();

    // Procesa la imagen y extrae los puntos en 3D
    std::vector<cv::Point2f> points2D = processor.processFrame(frame);
    std::vector<cv::Point3f> points3D = processor.convertTo3D(points2D);

    // Renderiza los puntos en 3D
    renderer.render(points3D);

    glutSwapBuffers(); // Actualiza la pantalla
}

int main(int argc, char** argv) {
    // Inicializa la cámara y verifica la conexión
    if (!camera.init(0)) {
        std::cerr << "Error al iniciar la cámara." << std::endl;
        return -1;
    }

    // Configura la ventana de OpenGL
    glutInit(&argc, argv);
    renderer.initOpenGL();

    // Establece la función de renderizado
    glutDisplayFunc(displayCallback);
    glutIdleFunc(displayCallback); // Llama a displayCallback continuamente

    glutMainLoop();
    return 0;
}
