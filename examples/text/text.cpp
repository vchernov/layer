#include <iostream>

#include "../../layer/core/Context.h"
#include "../../layer/core/InitError.h"
#include "../../layer/core/LoadingFailedException.h"

#include "../../layer/font/FontContext.h"

#include "TextApp.h"

int main(int argc, char** argv) {
    std::cout << "start" << std::endl;

    try {
        layer::Context context;
        layer::FontContext fontContext;

        std::string fontFileName;
        int fontSize = 0;
        std::vector<std::string> lines;

        if (argc > 1) {
            fontFileName = argv[1];
        }
        if (argc > 2) {
            fontSize = atoi(argv[2]);
        }

        if (!fontFileName.empty() && fontSize > 0) {
            TextApp app(fontFileName, fontSize);

            for (int i = 3; i < argc; i++) {
                app.addLine(argv[i]);
            }

            app.setBlendedFont();
            app.run();
        }
    } catch (layer::InitError& e) {
        std::cerr << e.what() << std::endl;
    } catch (layer::LoadingFailedException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;
    return 0;
}
