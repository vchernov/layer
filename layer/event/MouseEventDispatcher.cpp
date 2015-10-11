#include "MouseEventDispatcher.h"

namespace layer {

void MouseEventDispatcher::dispatchEvent(const SDL_Event& event) {
    switch (event.type) {
    case SDL_MOUSEMOTION:
        onMouseMoved(event);
        break;
    case SDL_MOUSEBUTTONDOWN:
        onMouseButtonDown(event);
        break;
    case SDL_MOUSEBUTTONUP:
        onMouseButtonUp(event);
        break;
    }
}

void MouseEventDispatcher::onMouseMoved(const SDL_Event& event) {
    mouseMoved.invoke(event.motion.x, event.motion.y);
}

void MouseEventDispatcher::onMouseButtonDown(const SDL_Event& event) {
    mouseButtonDown.invoke(event.button.button, event.button.x, event.button.y);
}

void MouseEventDispatcher::onMouseButtonUp(const SDL_Event& event) {
    mouseButtonUp.invoke(event.button.button, event.button.x, event.button.y);
}

}
