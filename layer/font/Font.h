#pragma once

#include <cstdint>
#include <string>

#include <SDL_ttf.h>

namespace layer {

class Font {
public:
    Font(const std::string& fileName, int pointSize);
    virtual ~Font();

    virtual SDL_Surface* render(const std::string& text) const = 0;
    void render(const std::string& text, int x, int y, SDL_Surface* destination);

    void setColor(uint8_t r, uint8_t g, uint8_t b);

protected:
    TTF_Font* font;
    SDL_Color color;
};

class SolidFont : public Font {
public:
    SolidFont(const std::string& fileName, int pointSize) :
            Font(fileName, pointSize) {
    }
    virtual ~SolidFont() = default;

    virtual SDL_Surface* render(const std::string& text) const override;
};

class BlendedFont : public Font {
public:
    BlendedFont(const std::string& fileName, int pointSize) :
            Font(fileName, pointSize) {
    }
    virtual ~BlendedFont() = default;

    virtual SDL_Surface* render(const std::string& text) const override;
};

class ShadedFont : public Font {
public:
    ShadedFont(const std::string& fileName, int pointSize) :
            Font(fileName, pointSize) {
    }
    virtual ~ShadedFont() = default;

    virtual SDL_Surface* render(const std::string& text) const override;

    void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b);

protected:
    SDL_Color backgroundColor;
};

}
