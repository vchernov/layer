#include "SystemEventDispatcher.h"

namespace layer {

void SystemEventDispatcher::dispatchEvent(const SDL_Event& event) {
    switch (event.type) {
    case SDL_QUIT:
        quit.invoke();
        break;
    }
}

}
