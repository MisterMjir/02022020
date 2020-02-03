#include "texture.h"
#include <SDL2/SDL_image.h>

Texture::Texture(const char* filePath, Renderer* ren)
{
  SDL_Surface* tempSurface = IMG_Load(filePath);
  texture = SDL_CreateTextureFromSurface(ren->getRenderer(), tempSurface);
  SDL_FreeSurface(tempSurface);
}

Texture::~Texture()
{
  SDL_DestroyTexture(texture);
}

SDL_Texture* Texture::getTexture()
{
  return texture;
}
