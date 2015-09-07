#pragma once

#include <functional>
#include <list>

namespace layer {

template<typename... Args>
class Delegate {
public:
    using Function = std::function<void(Args...)>;
    using FunctionContainer = std::list<Function>;
    using FunctionId = typename FunctionContainer::iterator;

    FunctionId add(Function callback) {
        callbacks.push_back(callback);
        return --callbacks.end();
    }

    void remove(FunctionId id) {
        callbacks.erase(id);
    }

    void invoke(Args... args) {
        for (auto callback : callbacks) {
            callback(args...);
        }
    }

private:
    FunctionContainer callbacks;
};

}
