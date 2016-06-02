#pragma once

#include <SDL.h>

namespace layer {

class Renderer {
public:
    static const uint32_t DEFAULT_FLAGS = 0; // providing no flags gives priority to available SDL_RENDERER_ACCELERATED renderers
    static const int DEFAULT_DRIVER_INDEX = -1; // to initialize the first one supporting the requested flags

    Renderer(SDL_Window* window, uint32_t flags = DEFAULT_FLAGS, int driverIndex = DEFAULT_DRIVER_INDEX);

    virtual ~Renderer();

    // update the screen with any rendering performed since the previous call
    void present();

    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF);
    void clear();

private:
    SDL_Renderer* renderer;
};

}
