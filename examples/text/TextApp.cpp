#include "TextApp.h"

#include "../../layer/font/SolidFont.h"
#include "../../layer/font/BlendedFont.h"
#include "../../layer/font/ShadedFont.h"

#include "../../layer/event/KeyboardEventDispatcher.h"

#include <sstream>

TextApp::TextApp(const std::string& fontFileName, int fontSize) : fontFileName(fontFileName), fontSize(fontSize) {
    window = layer::Window::createResizable<layer::Window2D>(windowTitle, 0, 0);

    auto keyEventDispatcher = std::make_shared<layer::KeyboardEventDispatcher>();
    keyEventDispatcher->keyUp[SDL_SCANCODE_1].add(std::bind(&TextApp::setSolidFont, this));
    keyEventDispatcher->keyUp[SDL_SCANCODE_2].add(std::bind(&TextApp::setBlendedFont, this));
    keyEventDispatcher->keyUp[SDL_SCANCODE_3].add(std::bind(&TextApp::setShadedFont, this));
    events.addDispatcher(keyEventDispatcher);
}

void TextApp::addLine(const std::string& text) {
    lines.push_back(text);
}

void TextApp::setSolidFont() {
    font = std::make_unique<layer::SolidFont>(fontFileName, fontSize);
    font->setColor(0x00, 0x00, 0xFF);

    updateWindowSize();
}

void TextApp::setBlendedFont() {
    font = std::make_unique<layer::BlendedFont>(fontFileName, fontSize);
    font->setColor(0x00, 0x00, 0xFF);

    updateWindowSize();
}

void TextApp::setShadedFont() {
    auto shadedFont = std::make_unique<layer::ShadedFont>(fontFileName, fontSize);
    shadedFont->setColor(0xFF, 0xFF, 0xFF);
    shadedFont->setBackgroundColor(0x00, 0x00, 0x00);
    font = std::move(shadedFont);

    updateWindowSize();
}

void TextApp::updateWindowSize() {
    int windowWidth = 0;
    int windowHeight = 0;
    for (const auto& text : lines) {
        int width, height;
        font->getTextSize(text, width, height);
        if (width > windowWidth) {
            windowWidth = width;
        }
        windowHeight += height;
    }
    window->setSize(windowWidth, windowHeight);
}

void TextApp::update() {
    window->getSurface().fill(0xFF, 0xFF, 0xFF);

    if (font) {
        int x = 0;
        int y = 0;
        for (const auto& text : lines) {
            int width, height;
            font->render(text, window->getSurface(), x, y, width, height);
            y += height;
        }
    }

    window->swapBuffers();

    if (fpsCounter.update()) {
        std::stringstream title;
        title << windowTitle << " (FPS: " << fpsCounter.framesPerSec() << ")";
        window->setTitle(title.str());
    }
}
