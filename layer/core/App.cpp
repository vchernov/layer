#include "App.h"

#include "../time/Time.h"

namespace layer {

App::App() {
    sysEventDispatcher = std::make_shared<SystemEventDispatcher>();
    sysEventDispatcher->quit.add(std::bind(&App::stop, this));
    events.addDispatcher(sysEventDispatcher);
}

void App::setFrameRateLimit(uint32_t fps) {
    minFrameTime = 1000 / fps;
}

void App::run() {
    running = true;
    while (running) {
        uint32_t frameStartTime = Time::ticks();

        events.process();
        update();

        uint32_t frameTime = Time::ticks() - frameStartTime;
        if (frameTime < minFrameTime) {
            Time::sleep(minFrameTime - frameTime);
        }
    }
}

void App::stop() {
    running = false;
}

void App::update() {
}

}
