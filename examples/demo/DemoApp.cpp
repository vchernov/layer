#include "DemoApp.h"

#include <functional>

#include "../../layer/window/Window2D.h"
#include "../../layer/event/KeyboardEventDispatcher.h"

DemoApp::DemoApp() {
    window = layer::Window::createResizable<layer::Window2D>("Layer Demo", 800, 600);

    auto keyEventDispatcher = std::make_shared<layer::KeyboardEventDispatcher>();
    keyEventDispatcher->keyUp[SDL_SCANCODE_ESCAPE].add(std::bind(&DemoApp::stop, this));
    events.addDispatcher(keyEventDispatcher);
}

void DemoApp::update() {
    window->swapBuffers();
}
