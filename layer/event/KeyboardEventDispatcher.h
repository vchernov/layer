#pragma once

#include "IEventDispatcher.h"
#include "DelegateMap.h"

namespace layer {

class KeyboardEventDispatcher : public IEventDispatcher {
public:
    virtual ~KeyboardEventDispatcher() = default;

    void dispatchEvent(const SDL_Event& event) override;

    DelegateMap<SDL_Keycode> keyDown;
    DelegateMap<SDL_Keycode> keyUp;

protected:
    virtual void onKeyDown(const SDL_Event& event);
    virtual void onKeyUp(const SDL_Event& event);
};

}
