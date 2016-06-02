#pragma once

#include "Window.h"
#include "../core/Renderer.h"

namespace layer {

class AcceleratedWindow2D : public Window {
public:
    AcceleratedWindow2D(const std::string& title, int width, int height, uint32_t windowFlags = 0, 
        uint32_t rendererFlags = Renderer::DEFAULT_FLAGS, int driverIndex = Renderer::DEFAULT_DRIVER_INDEX);

    virtual ~AcceleratedWindow2D();

    void swapBuffers() override;

    Renderer& getRenderer() const;

protected:
    std::unique_ptr<Renderer> renderer;
};

}
