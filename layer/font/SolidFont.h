#pragma once

#include "Font.h"

namespace layer {

class SolidFont : public Font {
public:
    SolidFont(const std::string& fileName, int pointSize) : Font(fileName, pointSize) {}
    ~SolidFont() override = default;

    std::unique_ptr<ISurface> renderToSurface(const std::string& text) const override;
};

}
