add_executable(stackTest
  stackTest.cpp
  stack.h)

install(TARGETS stackTest DESTINATION ${CMAKE_INSTALL_BINDIR})
