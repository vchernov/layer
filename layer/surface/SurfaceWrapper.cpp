﻿#include "SurfaceWrapper.h"

namespace layer {

SurfaceWrapper::SurfaceWrapper(SDL_Surface* surface) : surface(surface) {
}

SDL_Surface* SurfaceWrapper::getNativeSurface() const {
    return surface;
}

void SurfaceWrapper::fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_FillRect(surface, nullptr, SDL_MapRGBA(surface->format, r, g, b, a));
}

void SurfaceWrapper::fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_Rect rect = { x, y, width, height };
    SDL_FillRect(surface, &rect, SDL_MapRGBA(surface->format, r, g, b, a));
}

void SurfaceWrapper::blit(ISurface& other, int x, int y) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_BlitSurface(other.getNativeSurface(), nullptr, surface, &pos);
}

}
