#ifndef COLORS
#define COLORS

#include <vector>
#include <string>
#include "color.h"

class Colors
{
public:
  static void init();
  static void close();
  static Color* getColor(std::string);
private:
  Colors();
  ~Colors();
  static std::vector<Color*> colors;
};

#endif
