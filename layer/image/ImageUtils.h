#pragma once

#include <string>

#include <SDL_image.h>

namespace layer {

class ImageUtils {
public:
    static SDL_Surface* loadSurface(const std::string& fn);
};

}
