#include "Window.h"

#include "../core/InitError.h"

namespace layer {

Window::Window(const std::string& title, int width, int height, uint32_t flags) {
    window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
            flags);
    if (window == nullptr) {
        throw InitError(SDL_GetError());
    }
}

uint32_t Window::getWindowId() const {
    return SDL_GetWindowID(window);
}

void Window::setSize(int width, int height) {
    SDL_SetWindowSize(window, width, height);
}

void Window::getSize(int& width, int& height) const {
    SDL_GetWindowSize(window, &width, &height);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

}
