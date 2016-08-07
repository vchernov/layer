#include "FpsCounter.h"

#include "Time.h"

namespace layer {

bool FpsCounter::update() {
    frames++;
    uint32_t curTime = Time::ticks();
    uint32_t dt = curTime - prevTime;
    elapsed += dt;
    prevTime = curTime;

    bool changed = false;
    if (elapsed >= 1000) {
        int prevFps = framesPerSec();
        float sec = elapsed * 0.001f;
        fps = frames / sec;
        changed = framesPerSec() != prevFps;

        frames = 0;
        elapsed = 0;
    }
    return changed;
}

int FpsCounter::framesPerSec() const {
    return static_cast<int>(fps + 0.5f);
}

}
