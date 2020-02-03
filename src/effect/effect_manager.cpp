#include "effect_manager.h"
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "game.h"
#include "colors.h"

#include <iostream>

static int sizes[] = {4, 9, 16, 25, 36, 49, 64};
static int numSizes = 7;
static std::string colors[] = {"pink", "red", "orange", "yellow", "green", "teal", "blue", "purple"};
static int numColors = 8;

EffectManager::EffectManager(Renderer* ren)
{
  renderer = ren;
  std::srand(std::time(nullptr));
}

EffectManager::~EffectManager()
{
  for (auto particle : particles)
    delete particle;
  particles.clear();
}

void EffectManager::update()
{
  ticks++;
  if (ticks % 4 == 0)
    particles.push_back(new Effect(1 + std::rand() % Game::windowSize.w, 0, sizes[std::rand() % numSizes], Colors::getColor(colors[std::rand() % numColors]), renderer));

  if (Game::mouse.clicked)
    particles.push_back(new Effect((Game::mouse.x - 50) + std::rand() % 100, (Game::mouse.y - 50) + std::rand() % 100, sizes[std::rand() % numSizes], Colors::getColor(colors[std::rand() % numColors]), renderer));

  for (int i = particles.size() - 1; i >= 0; i--)
  {
    particles[i]->update();
    if (particles[i]->offScreen())
    {
      delete particles[i];
      particles.erase(particles.begin() + i);
    }
  }
}

void EffectManager::draw()
{
  for (auto particle : particles)
    particle->draw();
}
