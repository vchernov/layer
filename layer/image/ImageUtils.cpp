#include "ImageUtils.h"

namespace layer {

SDL_Surface* ImageUtils::loadSurface(const std::string& fn) {
    return IMG_Load(fn.c_str());
}

}
