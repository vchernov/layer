#include "WindowEventDirectDispatcher.h"

WindowEventDirectDispatcher::WindowEventDirectDispatcher(std::weak_ptr<layer::Window> window)
    : window(window) {
}

bool WindowEventDirectDispatcher::isForCurrentWindow(const SDL_Event& event) {
    auto current = window.lock();
    return current && event.window.windowID == current->getId();
}

void WindowEventDirectDispatcher::onClose(const SDL_Event& event) {
    if (isForCurrentWindow(event)) {
        WindowEventDispatcher::onClose(event);
    }
}
