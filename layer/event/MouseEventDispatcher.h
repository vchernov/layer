#pragma once

#include "IEventDispatcher.h"
#include "Delegate.h"

namespace layer {

class MouseEventDispatcher : public IEventDispatcher {
public:
    void dispatchEvent(const SDL_Event& event) override;

    Delegate<int, int> mouseMoved;
    Delegate<uint8_t, int, int> mouseButtonDown;
    Delegate<uint8_t, int, int> mouseButtonUp;

protected:
    virtual void onMouseMoved(const SDL_Event& event);
    virtual void onMouseButtonDown(const SDL_Event& event);
    virtual void onMouseButtonUp(const SDL_Event& event);
};

}
