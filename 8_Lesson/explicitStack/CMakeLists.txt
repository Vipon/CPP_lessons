add_executable(explicitStackTest
  explicitStackTest.cpp
  stack.h)

install(TARGETS explicitStackTest DESTINATION ${CMAKE_INSTALL_BINDIR})
