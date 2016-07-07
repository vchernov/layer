#include "BlendedFont.h"

#include "../surface/Surface.h"

namespace layer {

std::unique_ptr<ISurface> BlendedFont::renderToSurface(const std::string& text) const {
    return std::make_unique<Surface>(TTF_RenderUTF8_Blended(font, text.c_str(), color));
}

}
