#include "Context.h"

#include "InitError.h"

namespace layer {

Context::Context(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
        throw InitError(SDL_GetError());
    }
}

Context::~Context() {
    SDL_Quit();
}

}
