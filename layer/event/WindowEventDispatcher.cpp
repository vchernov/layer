#include "WindowEventDispatcher.h"

namespace layer {

void WindowEventDispatcher::dispatchEvent(const SDL_Event& event) {
    if (event.type == SDL_WINDOWEVENT) {
        switch (event.window.event) {
            case SDL_WINDOWEVENT_CLOSE:
                onClose(event);
                break;
            case SDL_WINDOWEVENT_RESIZED:
                onResized(event);
                break;
        }
    }
}

void WindowEventDispatcher::onClose(const SDL_Event&) {
    close.invoke();
}

void WindowEventDispatcher::onResized(const SDL_Event& event) {
    resized.invoke(event.window.data1, event.window.data2);
}

}
