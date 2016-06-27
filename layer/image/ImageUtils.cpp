#include "ImageUtils.h"

#include <SDL_image.h>

#include "../surface/Surface.h"
#include "../core/LoadingFailedException.h"

namespace layer {

std::unique_ptr<ISurface> ImageUtils::loadImage(const std::string& fileName) {
    SDL_Surface* img = IMG_Load(fileName.c_str());
    if (img == nullptr) {
        throw LoadingFailedException("Failed to load '" + fileName + "': " + IMG_GetError());
    }
    return std::make_unique<Surface>(img);
}

}
