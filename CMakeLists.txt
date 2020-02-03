cmake_minimum_required(VERSION 3.10)

project(app)

add_executable(app
  src/main.cpp

  src/colors/colors.cpp

  src/effect/effect_manager.cpp
  src/effect/effect.cpp

  src/game/game.cpp

  src/sdl/renderer.cpp
  src/sdl/texture.cpp
  src/sdl/window.cpp
)

target_include_directories(app PUBLIC
  src
  src/colors
  src/effect
  src/game
  src/sdl
)

target_link_libraries(app SDL2 SDL2_image)
set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)
