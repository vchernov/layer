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

class SolidFont : public Font {
public:
    SolidFont(const std::string& fileName, int pointSize) :
            Font(fileName, pointSize) {
    }
    ~SolidFont() override = default;

    std::unique_ptr<ISurface> render(const std::string& text) const override;
};

class BlendedFont : public Font {
public:
    BlendedFont(const std::string& fileName, int pointSize) :
            Font(fileName, pointSize) {
    }
    ~BlendedFont() override = default;

    std::unique_ptr<ISurface> render(const std::string& text) const override;
};

class ShadedFont : public Font {
public:
    ShadedFont(const std::string& fileName, int pointSize) :
            Font(fileName, pointSize) {
    }
    ~ShadedFont() override = default;

    std::unique_ptr<ISurface> render(const std::string& text) const override;

    void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b);

protected:
    SDL_Color backgroundColor;
};

}
