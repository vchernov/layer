#include "AcceleratedWindow2D.h"

namespace layer {

AcceleratedWindow2D::AcceleratedWindow2D(const std::string& title,
        int width, int height, uint32_t windowFlags,
        uint32_t rendererFlags, int driverIndex) :
        Window(title, width, height, windowFlags) {
    renderer = std::make_unique<Renderer>(window, rendererFlags, driverIndex);
}

AcceleratedWindow2D::~AcceleratedWindow2D() {
}

void AcceleratedWindow2D::swapBuffers() {
    renderer->present();
}

Renderer& AcceleratedWindow2D::getRenderer() const {
    return *renderer;
}

}
