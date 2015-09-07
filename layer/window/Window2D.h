#pragma once

#include "Window.h"

namespace layer {

class Window2D : public Window {
public:
    Window2D(const std::string& title, int width, int height, Uint32 flags = 0);
    virtual ~Window2D();

    void swapBuffers() override;

    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    void clear();

private:
    SDL_Renderer* renderer;
};

}
