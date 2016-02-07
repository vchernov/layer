#include "Clock.h"

#include <SDL.h>

namespace layer {

Clock::Clock() {
    start();
}

Clock::~Clock() {
}

void Clock::start() {
    startTime = Time::realtimeSinceStartup();
    lastTime = startTime;
}

float Clock::elapsedTime() {
    return Time::realtimeSinceStartup() - startTime;
}

float Clock::deltaTime() {
    auto curTime = Time::realtimeSinceStartup();
    auto deltaTime = curTime - lastTime;
    lastTime = curTime;
    return deltaTime;
}

}
