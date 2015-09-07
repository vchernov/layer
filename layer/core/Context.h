#pragma once

#include <SDL.h>

namespace layer {

class Context {
public:
    Context(Uint32 flags = SDL_INIT_EVERYTHING);
    virtual ~Context();
};

}
