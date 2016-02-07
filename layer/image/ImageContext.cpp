#include "ImageContext.h"

#include "../core/InitError.h"

namespace layer {

ImageContext::ImageContext(Uint32 flags) {
    if ((IMG_Init(flags) & flags) != flags) {
        throw InitError(IMG_GetError());
    }
}

ImageContext::~ImageContext() {
    IMG_Quit();
}

}
