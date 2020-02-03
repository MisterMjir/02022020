#include "constants.h"
#include "game.h"
#include "colors.h"
#include <SDL2/SDL.h>

int main(int argc, char* args[])
{
  Colors::init();

  const int frameDelay = 1000 / TARGET_FPS;

  Uint32 frameStart;
  int frameTime;

  Game::init("02022020", SDL_WINDOWPOS_CENTER, SDL_WINDOWPOS_CENTER, WINDOW_W, WINDOW_H, false);

  while (Game::isRunning())
  {
    frameStart = SDL_GetTicks();

    Game::input();
    Game::update();
    Game::draw();

    frameTime = SDL_GetTicks() - frameStart;

    while (frameDelay > frameTime)
    {
      Game::input();
      frameTime = SDL_GetTicks() - frameStart;
    }
  }

  Game::close();
  Colors::close();

  return 0;
}
