#include "Window2D.h"

#include "../surface/SurfaceWrapper.h"

namespace layer {

Window2D::Window2D(const std::string& title, int width, int height, uint32_t flags) :
        Window(title, width, height, flags) {
}

void Window2D::swapBuffers() {
    SDL_UpdateWindowSurface(window);
}

ISurface& Window2D::getSurface() const {
    SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
    static SurfaceWrapper wrapper(windowSurface);
    wrapper = SurfaceWrapper(windowSurface);
    return wrapper;
}

}
