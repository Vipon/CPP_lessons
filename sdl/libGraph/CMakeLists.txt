cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(libGraph LANGUAGES CXX VERSION 1.0)

set(CMAKE_LINKER ld)
set(LD_FLAGS -O3)

set(CMAKE_CXX_COMPILER g++)
set(CXX_FLAGS -Wall -Wextra -Werror -std=c++14 -O3)

set(LIB_GRAPH_HEADERS
  event.h
  render.h
  window.h
  point2D.h
  mediaApp.h
  graphException.h)

set(LIB_GRAPH_SOURCES
  event.cpp
  render.cpp
  window.cpp
  point2D.cpp
  mediaApp.cpp)

add_library(Graph
  STATIC ${LIB_GRAPH_HEADERS} ${LIB_GRAPH_SOURCES})

target_link_libraries(Graph SDL2)

install(FILES ${LIB_GRAPH_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Graph)
install(TARGETS Graph DESTINATION ${CMAKE_INSTALL_LIBDIR})
