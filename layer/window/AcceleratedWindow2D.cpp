#include "AcceleratedWindow2D.h"

namespace layer {

AcceleratedWindow2D::AcceleratedWindow2D(const std::string& title,
        int width, int height, uint32_t flags) :
        Window(title, width, height, flags) {
    renderer = SDL_CreateRenderer(window, -1, 0);
}

AcceleratedWindow2D::~AcceleratedWindow2D() {
    SDL_DestroyRenderer(renderer);
}

void AcceleratedWindow2D::swapBuffers() {
    SDL_RenderPresent(renderer);
}

void AcceleratedWindow2D::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void AcceleratedWindow2D::clear() {
    SDL_RenderClear(renderer);
}

}
