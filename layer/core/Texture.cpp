#include "Texture.h"

#include "../surface/ISurface.h"
#include "Renderer.h"

namespace layer {

Texture::Texture(const ISurface& surface, const Renderer& renderer) {
    texture = SDL_CreateTextureFromSurface(renderer.getNativeRenderer(), surface.getNativeSurface());
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

SDL_Texture* Texture::getNativeTexture() const {
    return texture;
}

}
