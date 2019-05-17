add_executable(recursiveTemplateTest
  recursiveTemplateTest.cpp
  recursiveTemplate.h)

install(TARGETS recursiveTemplateTest DESTINATION ${CMAKE_INSTALL_BINDIR})
