#include "FractalApp.h"

#include <sstream>

FractalApp::FractalApp() {
    window = layer::Window::createResizable<layer::Window2D>(windowTitle, 640, 480);
}

void FractalApp::update() {
    window->getSurface().fill(0xFF, 0xFF, 0xFF);

    window->swapBuffers();

    if (fpsCounter.update()) {
        std::stringstream title;
        title << windowTitle << " (FPS: " << fpsCounter.framesPerSec() << ")";
        window->setTitle(title.str());
    }
}
