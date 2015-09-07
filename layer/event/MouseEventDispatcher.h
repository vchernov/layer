#pragma once

#include "IEventDispatcher.h"
#include "Delegate.h"

namespace layer {

class MouseEventDispatcher : public IEventDispatcher {
public:
    virtual ~MouseEventDispatcher() = default;

    void dispatchEvent(const SDL_Event& event) override;

    Delegate<int, int> mouseMoved;
    Delegate<Uint8, int, int> mouseButtonDown;
    Delegate<Uint8, int, int> mouseButtonUp;

protected:
    virtual void onMouseMoved(const SDL_Event& event);
    virtual void onMouseButtonDown(const SDL_Event& event);
    virtual void onMouseButtonUp(const SDL_Event& event);
};

}
