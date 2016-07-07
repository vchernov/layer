#include "Font.h"

#include "../surface/Surface.h"
#include "../core/LoadingFailedException.h"

namespace layer {

Font::Font(const std::string& fileName, int pointSize) {
    font = TTF_OpenFont(fileName.c_str(), pointSize);
    if (font == nullptr) {
        throw LoadingFailedException("Failed to load '" + fileName + "': " + TTF_GetError());
    }
}

Font::~Font() {
    TTF_CloseFont(font);
}

void Font::setColor(uint8_t r, uint8_t g, uint8_t b) {
    color = { r, g, b };
}

void Font::render(const std::string& text, ISurface& destination, int x, int y) {
    auto textSurface = renderToSurface(text);
    destination.blit(*textSurface, x, y);
}

void Font::render(const std::string& text, ISurface& destination, int x, int y, int& textWidth, int& textHeight) {
    auto textSurface = renderToSurface(text);
    destination.blit(*textSurface, x, y);
    textWidth = textSurface->getWidth();
    textHeight = textSurface->getHeight();
}

void Font::getTextSize(const std::string& text, int& textWidth, int& textHeight) {
    TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);
}

}
