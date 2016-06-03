#pragma once

#include "SurfaceWrapper.h"

namespace layer {

class Surface : public SurfaceWrapper {
public:
    explicit Surface(SDL_Surface* surface);
    ~Surface() override;
};

}
