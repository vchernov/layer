#include "Font.h"

#include "../surface/Surface.h"

namespace layer {

Font::Font(const std::string& fileName, int pointSize) {
    font = TTF_OpenFont(fileName.c_str(), pointSize);
}

Font::~Font() {
    TTF_CloseFont(font);
}

void Font::render(const std::string& text, int x, int y, ISurface& destination) {
    auto textSurface = render(text);
    destination.blit(*textSurface, x, y);
}

void Font::setColor(uint8_t r, uint8_t g, uint8_t b) {
    color = {r, g, b, 0xFF};
}

std::unique_ptr<ISurface> SolidFont::render(const std::string& text) const {
    return std::make_unique<Surface>(TTF_RenderUTF8_Solid(font, text.c_str(), color));
}

std::unique_ptr<ISurface> BlendedFont::render(const std::string& text) const {
    return std::make_unique<Surface>(TTF_RenderUTF8_Blended(font, text.c_str(), color));
}

std::unique_ptr<ISurface> ShadedFont::render(const std::string& text) const {
    return std::make_unique<Surface>(TTF_RenderUTF8_Shaded(font, text.c_str(), color, backgroundColor));
}

void ShadedFont::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b) {
    backgroundColor = {r, g, b, 0xFF};
}

}
