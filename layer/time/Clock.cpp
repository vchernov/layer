#include "Clock.h"

#include "Time.h"

namespace layer {

Clock::Clock() {
    start();
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
