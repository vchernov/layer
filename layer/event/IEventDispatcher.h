#pragma once

#include <SDL.h>

namespace layer {

class IEventDispatcher {
public:
    virtual ~IEventDispatcher() = default;

    virtual void dispatchEvent(const SDL_Event& event) = 0;
};

}
