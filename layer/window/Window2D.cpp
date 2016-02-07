#include "Window2D.h"

namespace layer {

Window2D::Window2D(const std::string& title, int width, int height, uint32_t flags) :
        Window(title, width, height, flags) {
}

Window2D::~Window2D() {
}

void Window2D::swapBuffers() {
    SDL_UpdateWindowSurface(window);
}

SDL_Surface* Window2D::surface() const {
    return SDL_GetWindowSurface(window);
}

void Window2D::fill(uint8_t r, uint8_t g, uint8_t b) {
    SDL_Surface* screen = surface();
    SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, r, g, b));
}

}
