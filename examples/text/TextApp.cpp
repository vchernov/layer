#include "TextApp.h"

TextApp::TextApp(const std::string& fontFileName) {
    window = layer::Window::createResizable<layer::Window2D>("Text", 320, 240);

    font = std::make_shared<layer::BlendedFont>(fontFileName, 32);
    font->setColor(0x00, 0xFF, 0x00);
}

void TextApp::update() {
    window->fill(0xFF, 0xFF, 0xFF);
    font->render("Hello world!", 0, 0, window->surface());

    window->swapBuffers();
}
