#include "Surface.h"

namespace layer {

Surface::Surface(SDL_Surface* surface) : SurfaceWrapper(surface) {
}

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

}
