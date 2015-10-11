#pragma once

#include <unordered_map>

#include "Delegate.h"

namespace layer {

template<typename T, typename... Args>
class DelegateMap {
public:
    Delegate<Args...>& operator[](T key) {
        return delegates[key];
    }

    void invoke(T key, Args... args) {
        auto it = delegates.find(key);
        if (it != delegates.end()) {
            it->second.invoke(args...);
        }
    }

private:
    std::unordered_map<T, Delegate<Args...>> delegates;
};

}
