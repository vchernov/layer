#pragma once

#include <SDL.h>

#include "ISurface.h"

namespace layer {

class SurfaceWrapper : public ISurface {
public:
    SurfaceWrapper() = default;
    explicit SurfaceWrapper(SDL_Surface* surface);

    void setNativeSurface(SDL_Surface* surface);

    SDL_Surface* getNativeSurface() const override;

    void fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) override;
    void fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) override;

protected:
    SDL_Surface* surface;
};

}
