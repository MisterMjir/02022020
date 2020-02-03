#include "game.h"
#include "window.h"
#include "renderer.h"
#include "colors.h"
#include "texture.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <cmath>

bool Game::running = true;
Window* Game::window;
Renderer* Game::renderer;
Texture* Game::texture;
Dimensions Game::windowSize = {WINDOW_W, WINDOW_H};
Mouse Game::mouse = {0, 0, false};
EffectManager* Game::effectM;

void Game::init(const char* title, int x, int y, int w, int h, bool fullScreen)
{
  window = new Window(title, x, y, w, h, fullScreen);
  renderer = new Renderer(window->getWindow());
  texture = new Texture("res/images/img.png", renderer);
  effectM = new EffectManager(renderer);
}

void Game::close()
{
  delete window;
  delete renderer;
  delete texture;
  delete effectM;
}

void Game::input()
{
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type)
  {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_MOUSEBUTTONDOWN:
      switch (e.button.button)
      {
        case SDL_BUTTON_LEFT:
          mouse.clicked = true;
          break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      switch (e.button.button)
      {
        case SDL_BUTTON_LEFT:
          mouse.clicked = false;
          break;
      }
  }
  SDL_GetMouseState(&mouse.x, &mouse.y);
  SDL_GetWindowSize(window->getWindow(), &windowSize.w, &windowSize.h);
}

void Game::update()
{
  effectM->update();
}

void Game::draw()
{
  renderer->setDrawColor(Colors::getColor("white"), 255);
  renderer->clear();

  effectM->draw();

  int textW = 62 * 2;
  int textH = 18 * 2;
  SDL_Rect textLoc = {(int) ((windowSize.w / 2) - (textW / 2)), (int) ((windowSize.h / 2) - (textH / 2)), textW, textH};
  renderer->copy(texture->getTexture(), NULL, &textLoc);

  renderer->present();
}
