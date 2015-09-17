#include "SelectiveWindowEventDispatcher.h"

SelectiveWindowEventDispatcher::SelectiveWindowEventDispatcher(std::weak_ptr<layer::Window> window)
    : window(window) {
}

bool SelectiveWindowEventDispatcher::isForCurrentWindow(const SDL_Event& event) {
    auto current = window.lock();
    return current && event.window.windowID == current->getId();
}

void SelectiveWindowEventDispatcher::onClose(const SDL_Event& event) {
    if (isForCurrentWindow(event)) {
        WindowEventDispatcher::onClose(event);
    }
}
