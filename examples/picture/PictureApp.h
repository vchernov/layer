#pragma once

#include "../../layer/core/App.h"

class PictureApp : public layer::App {
public:
    PictureApp(const std::string& pictureFileName);

protected:
    void update() override;
};
