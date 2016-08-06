#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"
#include "../../layer/core/LoadingFailedException.h"

#include "../../layer/image/ImageContext.h"

#include "PictureApp.h"

int main(int argc, char** argv) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;
        layer::ImageContext imageContext;

        std::vector<std::string> imageFileNames;
        for (int i = 1; i < argc; i++) {
            imageFileNames.push_back(argv[i]);
        }

        PictureApp app(imageFileNames);
        app.run();
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    } catch (layer::LoadingFailedException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
