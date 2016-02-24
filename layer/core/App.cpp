#include "App.h"

namespace layer {

App::App() {
    sysEventDispatcher = std::make_shared<SystemEventDispatcher>();
    sysEventDispatcher->quit.add(std::bind(&App::stop, this));
    events.addDispatcher(sysEventDispatcher);
}

App::~App() {
}

void App::run() {
    running = true;
    while (running) {
        events.process();
        update();
    }
}

void App::stop() {
    running = false;
}

void App::update() {
}

}
