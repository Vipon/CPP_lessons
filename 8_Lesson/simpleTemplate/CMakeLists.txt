add_executable(simpleTemplateTest
  simpleTemplateTest.cpp
  simpleTemplate.h)

install(TARGETS simpleTemplateTest DESTINATION ${CMAKE_INSTALL_BINDIR})
