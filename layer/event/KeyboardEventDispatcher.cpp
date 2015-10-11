#include "KeyboardEventDispatcher.h"

namespace layer {

void KeyboardEventDispatcher::dispatchEvent(const SDL_Event& event) {
    switch (event.type) {
    case SDL_KEYDOWN:
        onKeyDown(event);
        break;
    case SDL_KEYUP:
        onKeyUp(event);
        break;
    }
}

void KeyboardEventDispatcher::onKeyDown(const SDL_Event& event) {
    keyDown.invoke(event.key.keysym.scancode);
}

void KeyboardEventDispatcher::onKeyUp(const SDL_Event& event) {
    keyUp.invoke(event.key.keysym.scancode);
}

}
