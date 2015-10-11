#include "FontContext.h"

#include "../core/InitError.h"

namespace layer {

FontContext::FontContext() {
    if (TTF_Init() != 0) {
        throw InitError(TTF_GetError());
    }
}

FontContext::~FontContext() {
    TTF_Quit();
}

}
