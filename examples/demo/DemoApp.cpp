#include "DemoApp.h"

#include <functional>

#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>

#include "../../layer/window/WindowGL.h"
#include "../../layer/event/SystemEventDispatcher.h"
#include "../../layer/event/WindowEventDispatcher.h"
#include "../../layer/event/KeyboardEventDispatcher.h"

DemoApp::DemoApp() {
    layer::WindowGL::setContextVersion(3, 3);
    window = layer::Window::create<layer::WindowGL>("Layer Demo", 800, 600);

    auto sysEventDispatcher = std::make_shared<layer::SystemEventDispatcher>();
    events.addDispatcher(sysEventDispatcher);

    auto wndEventDispatcher = std::make_shared<layer::WindowEventDispatcher>();
    events.addDispatcher(wndEventDispatcher);

    auto keyEventDispatcher = std::make_shared<layer::KeyboardEventDispatcher>();
    events.addDispatcher(keyEventDispatcher);

    sysEventDispatcher->quit.add(std::bind(&DemoApp::quit, this));
    keyEventDispatcher->keyUp[SDL_SCANCODE_ESCAPE].add(std::bind(&DemoApp::quit, this));

    glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
}

DemoApp::~DemoApp() {
}

void DemoApp::run() {
    running = true;
    while (running) {
        events.process();
        glClear(GL_COLOR_BUFFER_BIT);
        window->swapBuffers();
    }
}

void DemoApp::quit() {
    running = false;
}
