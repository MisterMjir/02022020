#ifndef RENDERER
#define RENDERER

#include <SDL2/SDL.h>
#include "color.h"

class Renderer
{
public:
  Renderer(SDL_Window* window);
  ~Renderer();
  void present();
  void clear();
  void setDrawColor(Color*, uint8_t);
  void fillRect(SDL_Rect* destRect);
  void copy(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect);
  SDL_Renderer* getRenderer();
private:
  SDL_Renderer* renderer;
};

#endif
