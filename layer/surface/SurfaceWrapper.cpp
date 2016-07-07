#include "SurfaceWrapper.h"

#include "../core/IllegalArgumentException.h"

namespace layer {

SurfaceWrapper::SurfaceWrapper(SDL_Surface* surface) : surface(surface) {
    if (surface == nullptr) {
        throw IllegalArgumentException("surface cannot be null");
    }
}

SDL_Surface* SurfaceWrapper::getNativeSurface() const {
    return surface;
}

int SurfaceWrapper::getWidth() const {
    return surface->w;
}

int SurfaceWrapper::getHeight() const {
    return surface->h;
}

void SurfaceWrapper::fill(uint8_t r, uint8_t g, uint8_t b) {
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, r, g, b));
}

void SurfaceWrapper::fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_FillRect(surface, nullptr, SDL_MapRGBA(surface->format, r, g, b, a));
}

void SurfaceWrapper::fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b) {
    SDL_Rect rect = { x, y, width, height };
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, r, g, b));
}

void SurfaceWrapper::fillRect(int x, int y, int width, int height, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_Rect rect = { x, y, width, height };
    SDL_FillRect(surface, &rect, SDL_MapRGBA(surface->format, r, g, b, a));
}

void SurfaceWrapper::blit(ISurface& other, int x, int y) {
    SDL_Rect pos = { x, y };
    SDL_BlitSurface(other.getNativeSurface(), nullptr, surface, &pos);
}

}
