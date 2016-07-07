#pragma once

#include "Font.h"

namespace layer {

class ShadedFont : public Font {
public:
    ShadedFont(const std::string& fileName, int pointSize) : Font(fileName, pointSize) {}
    ~ShadedFont() override = default;

    std::unique_ptr<ISurface> renderToSurface(const std::string& text) const override;

    void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b);

protected:
    SDL_Color backgroundColor;
};

}
