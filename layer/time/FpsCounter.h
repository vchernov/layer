#pragma once

#include <cstdint>

namespace layer {

class FpsCounter {
public:
    FpsCounter() = default;
    virtual ~FpsCounter() = default;

    bool update();

    int framesPerSec() const;

private:
    uint32_t lastFrameTime = 0;
    uint32_t elapsedTime = 0;
    int frames = 0;
    float fps = 0.0f;
};

}
