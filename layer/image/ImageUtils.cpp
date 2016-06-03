#include "ImageUtils.h"

#include <SDL_image.h>

#include "../surface/Surface.h"

namespace layer {

std::unique_ptr<ISurface> ImageUtils::loadSurface(const std::string& fn) {
    return std::make_unique<Surface>(IMG_Load(fn.c_str()));
}

}
