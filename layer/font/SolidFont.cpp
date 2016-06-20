#include "SolidFont.h"

#include "../surface/Surface.h"

namespace layer {

std::unique_ptr<ISurface> SolidFont::render(const std::string& text) const {
    return std::make_unique<Surface>(TTF_RenderUTF8_Solid(font, text.c_str(), color));
}

}
