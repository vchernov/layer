#pragma once

#include "IEventDispatcher.h"
#include "Delegate.h"

namespace layer {

class WindowEventDispatcher : public IEventDispatcher {
public:
    virtual ~WindowEventDispatcher() = default;

    void dispatchEvent(const SDL_Event& event) override;

    Delegate<> close;
    Delegate<int, int> resized;

protected:
    virtual void onClose(const SDL_Event& event);
    virtual void onResized(const SDL_Event& event);
};

}
