#include "DemoApp.h"

#include <functional>

#include "../../layer/event/KeyboardEventDispatcher.h"

DemoApp::DemoApp() {
    window = layer::Window::createResizable<layer::AcceleratedWindow2D>("Layer Demo", 800, 600);
    window->getRenderer().setDrawColor(0xFF, 0xFF, 0xFF);

    auto keyEventDispatcher = std::make_shared<layer::KeyboardEventDispatcher>();
    keyEventDispatcher->keyUp[SDL_SCANCODE_ESCAPE].add(std::bind(&DemoApp::stop, this));
    events.addDispatcher(keyEventDispatcher);
}

void DemoApp::update() {
    window->getRenderer().clear();
    window->swapBuffers();
}
