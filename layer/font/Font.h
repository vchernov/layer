#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include <SDL_ttf.h>

namespace layer {

class ISurface;

class Font {
public:
    Font(const std::string& fileName, int pointSize);
    virtual ~Font();

    void render(const std::string& text, int x, int y, ISurface& destination);
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    virtual std::unique_ptr<ISurface> render(const std::string& text) const = 0;

protected:
    TTF_Font* font;
    SDL_Color color;
};

}
