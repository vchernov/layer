#pragma once

#include <SDL.h>

namespace layer {

class Context {
public:
    explicit Context(Uint32 flags = SDL_INIT_EVERYTHING);
    virtual ~Context();
};

}
