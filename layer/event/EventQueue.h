#pragma once

#include <memory>
#include <vector>

#include "IEventDispatcher.h"

namespace layer {

class EventQueue {
public:
    virtual ~EventQueue() = default;

    void process();

    void addDispatcher(std::shared_ptr<IEventDispatcher> dispatcher);
    void removeDispatcher(std::shared_ptr<IEventDispatcher> dispatcher);

private:
    std::vector<std::shared_ptr<IEventDispatcher>> dispatchers;
};

}
