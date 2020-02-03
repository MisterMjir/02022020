#ifndef EFFECT_MANAGER
#define EFFECT_MANAGER

#include "renderer.h"
#include "effect.h"
#include <vector>

class EffectManager
{
public:
  EffectManager(Renderer*);
  ~EffectManager();
  void update();
  void draw();
private:
  std::vector<Effect*> particles;
  Renderer* renderer;
  int ticks;
};

#endif
