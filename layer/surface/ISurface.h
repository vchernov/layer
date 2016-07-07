#pragma once

#include <cstdint>

namespace layer {

class ISurface {
public:
    virtual ~ISurface() = default;

    virtual SDL_Surface* getNativeSurface() const = 0;

    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;

    virtual void fill(uint8_t r, uint8_t g, uint8_t b) = 0;
    virtual void fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;

    virtual void fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b) = 0;
    virtual void fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;

    virtual void blit(ISurface& other, int x, int y) = 0;
};

}
