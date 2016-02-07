#pragma once

#include "Time.h"

namespace layer {

class Clock {
public:
    Clock();
    virtual ~Clock();

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
    float startTime;
    float lastTime;
};

}
