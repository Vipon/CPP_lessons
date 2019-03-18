cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(miniPaint LANGUAGES CXX VERSION 1.0)

set(CMAKE_LINKER ld)
set(CMAKE_LD_FLAGS -O3)

set(CMAKE_CXX_COMPILER g++)
get_target_property(GRAPH_SOURCE_DIR Graph SOURCE_DIR)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++14 -O3 -I${GRAPH_SOURCE_DIR}")

add_executable(miniPaint miniPaint.cpp)
target_link_libraries(miniPaint SDL2 Graph)

install(TARGETS miniPaint DESTINATION ${CMAKE_INSTALL_BINDIR})