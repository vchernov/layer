#pragma once

#include "Window.h"
#include "../surface/ISurface.h"

namespace layer {

class Window2D : public Window {
public:
    Window2D(const std::string& title, int width, int height, uint32_t flags = 0);
    virtual ~Window2D();

    void swapBuffers() override;

    ISurface& getSurface() const;
};

}
