#include "window.h"
#include <SDL2/SDL.h>

Window::Window(const char* title, int x, int y, int w, int h, bool fullScreen)
{
  int flags = 0;

  if (fullScreen)
    flags =  SDL_WINDOW_FULLSCREEN;

  window = SDL_CreateWindow(title, x, y, w, h, flags);
  SDL_SetWindowResizable(window, SDL_TRUE);
}

Window::~Window()
{
  SDL_DestroyWindow(window);
}

SDL_Window* Window::getWindow()
{
  return window;
}
