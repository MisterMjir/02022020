#ifndef EFFECT
#define EFFECT

#include <SDL2/SDL.h>
#include "color.h"
#include "renderer.h"

class Effect
{
public:
  Effect(int x, int y, int size, Color*, Renderer*);
  ~Effect();
  void update();
  void draw();
  bool offScreen();
private:
  int size;
  Color* color;
  SDL_Rect destRect;
  Renderer* renderer;
  int ticks;
};

#endif
