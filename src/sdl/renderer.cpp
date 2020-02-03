#include "renderer.h"
#include <SDL2/SDL.h>
#include "color.h"

Renderer::Renderer(SDL_Window* window)
{
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(renderer);
}

void Renderer::present()
{
  SDL_RenderPresent(renderer);
}

void Renderer::clear()
{
  SDL_RenderClear(renderer);
}

void Renderer::setDrawColor(Color* color, uint8_t a)
{
  SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, a);
}

void Renderer::fillRect(SDL_Rect* destRect)
{
  SDL_RenderFillRect(renderer, destRect);
}

void Renderer::copy(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect)
{
  SDL_RenderCopy(renderer, texture, srcRect, destRect);
}


SDL_Renderer* Renderer::getRenderer()
{
  return renderer;
}
