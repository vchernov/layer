#pragma once

#include "IEventDispatcher.h"
#include "Delegate.h"

namespace layer {

class SystemEventDispatcher : public IEventDispatcher {
public:
    virtual ~SystemEventDispatcher() = default;

    void dispatchEvent(const SDL_Event& event) override;

    Delegate<> quit;
};

}
