#pragma once

#include <stdexcept>

namespace layer {

class LoadingFailedException : public std::runtime_error {
public:
    using runtime_error::runtime_error;
};

}
