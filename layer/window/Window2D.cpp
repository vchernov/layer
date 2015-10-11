#include "Window2D.h"

namespace layer {

Window2D::Window2D(const std::string& title, int width, int height, Uint32 flags)
    : Window(title, width, height, flags) {
    renderer = SDL_CreateRenderer(window, -1, 0);
}

Window2D::~Window2D() {
    SDL_DestroyRenderer(renderer);
}

void Window2D::swapBuffers() {
    SDL_RenderPresent(renderer);
}

void Window2D::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Window2D::clear() {
    SDL_RenderClear(renderer);
}

}
