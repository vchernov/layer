#pragma once

#include "Font.h"

namespace layer {

class BlendedFont : public Font {
public:
    BlendedFont(const std::string& fileName, int pointSize) : Font(fileName, pointSize) {}
    ~BlendedFont() override = default;

    std::unique_ptr<ISurface> renderToSurface(const std::string& text) const override;
};

}
