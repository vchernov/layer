#include "Font.h"

namespace layer {

Font::Font(const std::string& fileName, int pointSize) {
    font = TTF_OpenFont(fileName.c_str(), pointSize);
}

Font::~Font() {
    TTF_CloseFont(font);
}

void Font::render(const std::string& text, int x, int y, SDL_Surface* destination) {
    SDL_Surface* textSurface = render(text);
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_BlitSurface(textSurface, nullptr, destination, &pos);
    SDL_FreeSurface(textSurface);
}

void Font::setColor(uint8_t r, uint8_t g, uint8_t b) {
    color = {r, g, b, 0xFF};
}

SDL_Surface* SolidFont::render(const std::string& text) const {
    return TTF_RenderUTF8_Solid(font, text.c_str(), color);
}

SDL_Surface* BlendedFont::render(const std::string& text) const {
    return TTF_RenderUTF8_Blended(font, text.c_str(), color);
}

SDL_Surface* ShadedFont::render(const std::string& text) const {
    return TTF_RenderUTF8_Shaded(font, text.c_str(), color, backgroundColor);
}

void ShadedFont::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b) {
    backgroundColor = {r, g, b, 0xFF};
}

}
