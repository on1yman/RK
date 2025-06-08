cmake_minimum_required(VERSION 3.10)
project(AbstractFactoryExample VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основное приложение
add_executable(AbstractFactory src/AbstractFactory/Conceptual/main.cc)

# Настройка тестов
enable_testing()

# Поиск Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests/test_abstract_factory.cpp)
target_link_libraries(run_tests GTest::GTest GTest::Main pthread)

add_test(NAME AbstractFactoryTests COMMAND run_tests)

# Установка основного приложения
install(TARGETS AbstractFactory
    RUNTIME DESTINATION bin
)

# Настройка CPack
set(CPACK_PACKAGE_NAME "abstractfactory-example")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "RK")
set(CPACK_PACKAGE_CONTACT "onlyman")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Abstract Factory pattern example")

# DEB-специфичные настройки
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "onlyman")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Abstract Factory pattern example app for RK")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/your/repo")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")  # Зависимости, если нужны
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)  # Автоматически определять зависимости библиотек
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)  # Автоимя файла

include(CPack)