#pragma once

#include "Window.h"

namespace layer {

class WindowGL : public Window {
public:
    WindowGL(const std::string& title, int width, int height, Uint32 flags = 0);
    virtual ~WindowGL();

    void swapBuffers() override;

    void makeCurrent();

private:
    SDL_GLContext context;
};

}
