#pragma once

#include <memory>

#include "../event/EventQueue.h"
#include "../event/SystemEventDispatcher.h"

namespace layer {

class App {
public:
    App();
    virtual ~App() = default;

    void run();

    /**
     * Run with limited frame rate.
     */
    void run(uint32_t fps);

    void stop();

protected:
    virtual void update();

    EventQueue events;
    std::shared_ptr<SystemEventDispatcher> sysEventDispatcher;

private:
    bool running = false;
};

}
