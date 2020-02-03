#include "colors.h"
#include "color.h"

std::vector<Color*> Colors::colors;

void Colors::init()
{
  colors.reserve(9);
  colors.push_back(new Color {"white", 0xff, 0xff, 0xff});
  colors.push_back(new Color {"pink", 0xe5, 0x5d, 0xac});
  colors.push_back(new Color {"red", 0xff, 0x4d, 0x4d});
  colors.push_back(new Color {"orange", 0xf0, 0x6c, 0x00});
  colors.push_back(new Color {"yellow", 0xff, 0xc4, 0x38});
  colors.push_back(new Color {"green", 0x23, 0x85, 0x31});
  colors.push_back(new Color {"teal", 0x30, 0xc5, 0xad});
  colors.push_back(new Color {"blue", 0x33, 0xa5, 0xff});
  colors.push_back(new Color {"purple", 0x6c, 0x34, 0x9d});
}

void Colors::close()
{
  for (auto color : colors)
    delete color;
  colors.clear();
}

Color* Colors::getColor(std::string query)
{
  for (auto color: colors)
  {
    if (!color->name.compare(query))
      return color;
  }
  return colors[0];
}
