#pragma once

#include <SDL_image.h>

namespace layer {

class ImageContext {
public:
    ImageContext(Uint32 flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    virtual ~ImageContext();
};

}
