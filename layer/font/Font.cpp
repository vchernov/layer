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

void Font::render(const std::string& text, int x, int y, ISurface& destination) {
    auto textSurface = render(text);
    destination.blit(*textSurface, x, y);
}

void Font::setColor(uint8_t r, uint8_t g, uint8_t b) {
    color = { r, g, b };
}

}
