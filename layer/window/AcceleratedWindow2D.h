#pragma once

#include "Window.h"

namespace layer {

class AcceleratedWindow2D : public Window {
public:
    AcceleratedWindow2D(const std::string& title, int width, int height, uint32_t flags = 0);
    virtual ~AcceleratedWindow2D();

    void swapBuffers() override;

    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF);
    void clear();

protected:
    SDL_Renderer* renderer;
};

}
