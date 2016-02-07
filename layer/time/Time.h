#pragma once

#include <cstdint>

namespace layer {

class Time {
public:
    /**
     * Get the number of milliseconds since the application startup.
     */
    static uint32_t ticks();

    /**
     * The real time in seconds since the application started.
     */
    static float realtimeSinceStartup();

    /**
     * Wait a specified number of milliseconds before returning.
     */
    static void sleep(uint32_t ms);
};

}
