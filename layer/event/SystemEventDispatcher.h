#pragma once

#include "IEventDispatcher.h"
#include "Delegate.h"

namespace layer {

class SystemEventDispatcher : public IEventDispatcher {
public:
    void dispatchEvent(const SDL_Event& event) override;

    Delegate<> quit;
};

}
