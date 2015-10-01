#include "WindowGL.h"

namespace layer {

WindowGL::WindowGL(const std::string& title, int width, int height, Uint32 flags)
    : Window(title, width, height, SDL_WINDOW_OPENGL | flags) {
    context = SDL_GL_CreateContext(window);
}

WindowGL::~WindowGL() {
    SDL_GL_DeleteContext(context);
}

void WindowGL::swapBuffers() {
    SDL_GL_SwapWindow(window);
}

void WindowGL::makeCurrent() {
    SDL_GL_MakeCurrent(window, context);
}

}
