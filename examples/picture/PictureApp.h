#pragma once

#include <vector>

#include "../../layer/core/App.h"
#include "../../layer/window/AcceleratedWindow2D.h"
#include "../../layer/core/Texture.h"

class PictureApp : public layer::App {
public:
    PictureApp(const std::vector<std::string>& imageFileNames);

protected:
    void update() override;

private:
    std::unique_ptr<layer::AcceleratedWindow2D> window;
    std::vector<std::shared_ptr<layer::Texture>> images;
    int seed;
};
