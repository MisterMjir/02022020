#include "effect.h"
#include "color.h"
#include "renderer.h"
#include <cmath>
#include <SDL2/SDL.h>
#include "game.h"

Effect::Effect(int x, int y, int size, Color* c, Renderer* ren)
{
  ticks = 0;
  destRect = {x, y, size, size};
  color = c;
  renderer = ren;
  this->size = size;
}

Effect::~Effect()
{

}

void Effect::update()
{
  ticks++;
  destRect.y++;
}

void Effect::draw()
{
  SDL_Rect dRect = {(int) (destRect.x + std::sin(ticks / 2) * 1), destRect.y, size, size};
  renderer->setDrawColor(color, 128);
  renderer->fillRect(&dRect);
}

bool Effect::offScreen()
{
  return destRect.y > Game::windowSize.h;
}
