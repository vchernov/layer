#pragma once

#include <SDL.h>

namespace layer {

class ISurface;
class Renderer;

class Texture {
public:
    Texture(const ISurface& surface, const Renderer& renderer);
    virtual ~Texture();

    SDL_Texture* getNativeTexture() const;

private:
    SDL_Texture* texture;
};

}
