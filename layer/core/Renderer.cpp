#include "Renderer.h"

#include "Texture.h"

namespace layer {

Renderer::Renderer(SDL_Window* window, uint32_t flags, int driverIndex) {
    renderer = SDL_CreateRenderer(window, driverIndex, flags);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::getNativeRenderer() const {
    return renderer;
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Renderer::clear() {
    SDL_RenderClear(renderer);
}

void Renderer::render(const Texture& texture) {
    SDL_RenderCopy(renderer, texture.getNativeTexture(), nullptr, nullptr);
}

void Renderer::render(const Texture& texture, int x, int y) {
    int width, height;
    texture.getSize(width, height);
    render(texture, x, y, width, height);
}

void Renderer::render(const Texture& texture, int x, int y, int width, int height) {
    SDL_Rect dst = { x, y, width, height };
    SDL_RenderCopy(renderer, texture.getNativeTexture(), nullptr, &dst);
}

}
