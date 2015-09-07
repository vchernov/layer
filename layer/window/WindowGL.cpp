#include "WindowGL.h"

namespace layer {

void WindowGL::setContextVersion(int major, int minor) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}

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
