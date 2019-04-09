add_executable(nonTypeTemplateTest
  nonTypeTemplateTest.cpp
  nonTypeTemplate.h)

install(TARGETS nonTypeTemplateTest DESTINATION ${CMAKE_INSTALL_BINDIR})
