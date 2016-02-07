#include "Time.h"

#include <SDL.h>

namespace layer {

uint32_t Time::ticks() {
    return SDL_GetTicks();
}

float Time::realtimeSinceStartup() {
    return ticks() * 0.001f; // millis to seconds
}

void Time::sleep(uint32_t ms) {
    SDL_Delay(ms);
}

}
