#include "TextApp.h"

#include <functional>

#include "../../layer/event/SystemEventDispatcher.h"

TextApp::TextApp(const std::string& fontFileName) {
    window = layer::Window::createResizable<layer::Window2D>("Text", 800, 600);

    auto sysEventDispatcher = std::make_shared<layer::SystemEventDispatcher>();
    events.addDispatcher(sysEventDispatcher);

    sysEventDispatcher->quit.add(std::bind(&TextApp::quit, this));

    font = std::make_shared<layer::BlendedFont>(fontFileName, 32);
    font->setColor(0x00, 0xFF, 0x00);
}

TextApp::~TextApp() {
}

void TextApp::run() {
    running = true;
    while (running) {
        events.process();

        window->fill(0xFF, 0xFF, 0xFF);
        font->render("Hello world!", 0, 0, window->surface());

        window->swapBuffers();
    }
}

void TextApp::quit() {
    running = false;
}
