#include "Timer.h"

namespace layer {

Timer::Timer() {
    start();
}

Timer::~Timer() {
}

void Timer::start() {
    startTime = SDL_GetTicks();
    lastTime = startTime;
}

float Timer::elapsedTime() {
    auto curTime = SDL_GetTicks();
    auto elapsedTime = curTime - startTime;
    return (float)elapsedTime * 0.001f; // millis to seconds
}

float Timer::deltaTime() {
    auto curTime = SDL_GetTicks();
    auto deltaTime = curTime - lastTime;
    lastTime = curTime;
    return (float)deltaTime * 0.001f; // millis to seconds
}

}
