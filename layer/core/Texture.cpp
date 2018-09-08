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

void Texture::getSize(int& width, int& height) const {
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

Uint32 Texture::getPixelFormat() const {
    Uint32 format;
    SDL_QueryTexture(texture, &format, nullptr, nullptr, nullptr);
    return format;
}

int Texture::getAccess() const {
    int access;
    SDL_QueryTexture(texture, nullptr, &access, nullptr, nullptr);
    return access;
}

}
