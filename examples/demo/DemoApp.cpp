#include "DemoApp.h"

#include <functional>

#include "../../layer/window/Window2D.h"
#include "../../layer/event/SystemEventDispatcher.h"
#include "../../layer/event/WindowEventDispatcher.h"
#include "../../layer/event/KeyboardEventDispatcher.h"

DemoApp::DemoApp() {
    window = layer::Window::createResizable<layer::Window2D>("Layer Demo", 800, 600);

    auto sysEventDispatcher = std::make_shared<layer::SystemEventDispatcher>();
    events.addDispatcher(sysEventDispatcher);

    auto keyEventDispatcher = std::make_shared<layer::KeyboardEventDispatcher>();
    events.addDispatcher(keyEventDispatcher);

    sysEventDispatcher->quit.add(std::bind(&DemoApp::quit, this));
    keyEventDispatcher->keyUp[SDL_SCANCODE_ESCAPE].add(std::bind(&DemoApp::quit, this));
}

DemoApp::~DemoApp() {
}

void DemoApp::run() {
    running = true;
    while (running) {
        events.process();
        window->swapBuffers();
    }
}

void DemoApp::quit() {
    running = false;
}
