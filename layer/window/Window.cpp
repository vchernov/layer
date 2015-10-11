#include "Window.h"

#include "../core/InitError.h"

namespace layer {

Window::Window(const std::string& title, int width, int height, Uint32 flags) {
    window = SDL_CreateWindow(title.c_str(), 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        width, height, flags);
    if (window == nullptr) {
        throw InitError(SDL_GetError());
    }
}

Uint32 Window::getId() const {
    return SDL_GetWindowID(window);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

}
