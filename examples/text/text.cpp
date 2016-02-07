#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"

#include "../../layer/font/FontContext.h"

#include "TextApp.h"

int main(int argc, char** argv) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;
        layer::FontContext fontContext;

        if (argc > 1) {
            TextApp app(argv[1]);
            app.run();
        }
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
