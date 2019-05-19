cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
set(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)

add_subdirectory(simpleTemplate)
add_subdirectory(nonTypeTemplate)
add_subdirectory(recursiveTemplate)
add_subdirectory(stack)
add_subdirectory(explicitStack)
