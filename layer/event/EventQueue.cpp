#include "EventQueue.h"

#include <algorithm>

namespace layer {

void EventQueue::process() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        for (const auto& dispatcher : dispatchers) {
            dispatcher->dispatchEvent(event);
        }
    }
}

void EventQueue::addDispatcher(std::shared_ptr<IEventDispatcher> dispatcher) {
    dispatchers.push_back(dispatcher);
}

void EventQueue::removeDispatcher(std::shared_ptr<IEventDispatcher> dispatcher) {
    dispatchers.erase(std::remove(dispatchers.begin(), dispatchers.end(), dispatcher), dispatchers.end());
}

}
