cmake_minimum_required(VERSION 3.10)
project(AbstractFactoryExample VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(AbstractFactory src/AbstractFactory/Conceptual/main.cc)


install(TARGETS AbstractFactory
    RUNTIME DESTINATION bin
)

include(CPack)

set(CPACK_PACKAGE_NAME "abstractfactory-example")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "onlyman")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Abstract Factory pattern example app for RK")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
