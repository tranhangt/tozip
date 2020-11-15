cmake_minimum_required(VERSION 3.17)
project(newgame)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS window system graphics)
add_executable(newgame main.cpp Animation.cpp Animation.h Entity.cpp Entity.h Virus.cpp Virus.h Arrow.cpp Arrow.h)
target_link_libraries(newgame sfml-system sfml-window sfml-graphics sfml-audio)