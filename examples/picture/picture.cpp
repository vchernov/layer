#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"

#include "../../layer/image/ImageContext.h"

#include "PictureApp.h"

int main(int argc, char** argv) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;
        layer::ImageContext imageContext;

        if (argc > 1) {
            PictureApp app(argv[0]);
            app.run();
        }
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
