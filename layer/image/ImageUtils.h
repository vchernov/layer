#pragma once

#include <memory>
#include <string>

namespace layer {

class ISurface;

class ImageUtils {
public:
    static std::unique_ptr<ISurface> loadImage(const std::string& fileName);
};

}
