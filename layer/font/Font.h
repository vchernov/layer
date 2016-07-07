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

    void setColor(uint8_t r, uint8_t g, uint8_t b);

    /**
     * Renders the text to destination surface at provided location.
     */
    void render(const std::string& text, ISurface& destination, int x, int y);

    /**
     * Renders the text to destination surface at provided location and outputs the text surface size.
     */
    void render(const std::string& text, ISurface& destination, int x, int y, int& textWidth, int& textHeight);

    void getTextSize(const std::string& text, int& textWidth, int& textHeight);

    virtual std::unique_ptr<ISurface> renderToSurface(const std::string& text) const = 0;

protected:
    TTF_Font* font;
    SDL_Color color;
};

}
