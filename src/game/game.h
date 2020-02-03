#ifndef GAME
#define GAME

#include "window.h"
#include "renderer.h"
#include "texture.h"
#include "effect_manager.h"

struct Dimensions
{
  int w;
  int h;
};

struct Mouse
{
  int x;
  int y;
  bool clicked;
};

class Game
{
public:
  static void init(const char* title, int x, int y, int w, int h, bool fullScreen);
  static void close();

  static void input();
  static void update();
  static void draw();

  static bool isRunning() {return running;}

  static Dimensions windowSize;
  static Mouse mouse;
private:
  Game();
  ~Game();

  static bool running;
  static Window* window;
  static Renderer* renderer;
  static Texture* texture;
  static EffectManager* effectM;
};

#endif
