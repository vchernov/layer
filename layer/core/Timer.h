#pragma once

#include <SDL.h>

namespace layer {

class Timer {
public:
    Timer();
    virtual ~Timer();

    void start();

    /**
     * Get the seconds passed since the clock started.
     */
    float elapsedTime();

    /**
     * Get the seconds passed since the last call to this method.
     */
    float deltaTime();

private:
    Uint32 startTime;
    Uint32 lastTime;
};

}
