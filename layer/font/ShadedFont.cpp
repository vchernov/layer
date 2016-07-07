#include "ShadedFont.h"

#include "../surface/Surface.h"

namespace layer {

std::unique_ptr<ISurface> ShadedFont::renderToSurface(const std::string& text) const {
    return std::make_unique<Surface>(TTF_RenderUTF8_Shaded(font, text.c_str(), color, backgroundColor));
}

void ShadedFont::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b) {
    backgroundColor = { r, g, b };
}

}
