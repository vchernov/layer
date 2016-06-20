#include "TextApp.h"

#include "../../layer/font/BlendedFont.h"

TextApp::TextApp(const std::string& fontFileName) {
    window = layer::Window::createResizable<layer::Window2D>("Text", 320, 240);

    font = std::make_unique<layer::BlendedFont>(fontFileName, 32);
    font->setColor(0x00, 0x00, 0xFF);
}

void TextApp::update() {
    window->getSurface().fill(0xFF, 0xFF, 0xFF);
    font->render("Hello world!", 0, 0, window->getSurface());

    window->swapBuffers();
}
