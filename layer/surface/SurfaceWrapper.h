#pragma once

#include <SDL.h>

#include "ISurface.h"

namespace layer {

class SurfaceWrapper : public ISurface {
public:
    explicit SurfaceWrapper(SDL_Surface* surface);
    ~SurfaceWrapper() override = default;

    SDL_Surface* getNativeSurface() const override;

    void fill(uint8_t r, uint8_t g, uint8_t b) override;
    void fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;

    void fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b) override;
    void fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;

    void blit(ISurface& other, int x, int y) override;

protected:
    SDL_Surface* surface;
};

}
