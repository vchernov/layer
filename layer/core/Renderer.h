#pragma once

#include <SDL.h>

namespace layer {

class Texture;

class Renderer {
public:
    static const uint32_t DEFAULT_FLAGS = 0; // providing no flags gives priority to available SDL_RENDERER_ACCELERATED renderers
    static const int DEFAULT_DRIVER_INDEX = -1; // to initialize the first one supporting the requested flags

    Renderer(SDL_Window* window, uint32_t flags = DEFAULT_FLAGS, int driverIndex = DEFAULT_DRIVER_INDEX);
    virtual ~Renderer();

    SDL_Renderer* getNativeRenderer() const;

    // update the screen with any rendering performed since the previous call
    void present();

    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF);
    void clear();

    void render(const Texture& texture);
    void render(const Texture& texture, int x, int y);
    void render(const Texture& texture, int x, int y, int width, int height);

    void drawLine(int x1, int y1, int x2, int y2);
    void fillRect(int x, int y, int width, int height);

    void drawGrid(int x, int y, int cellWidth, int cellHeight, int rows, int columns);

private:
    SDL_Renderer* renderer;
};

}
