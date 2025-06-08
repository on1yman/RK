cmake_minimum_required(VERSION 3.10)
project(AbstractFactoryExample VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основное приложение
add_executable(AbstractFactory src/AbstractFactory/Conceptual/main.cc)

# Настройка тестов
enable_testing()

# Вариант 1: Если GTest установлен в системе
find_package(GTest REQUIRED)

# Вариант 2: Если GTest не установлен - скачиваем автоматически
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(run_tests tests/test_abstract_factory.cpp)

# Подключение GTest с проверкой, какой вариант используется
if(GTest_FOUND)
    target_link_libraries(run_tests GTest::GTest GTest::Main pthread)
else()
    target_link_libraries(run_tests gtest gtest_main pthread)
endif()

add_test(NAME AbstractFactoryTests COMMAND run_tests)

# Установка основного приложения
install(TARGETS AbstractFactory
    RUNTIME DESTINATION bin
)

# Настройка CPack
include(CPack)
set(CPACK_PACKAGE_NAME "abstractfactory-example")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "onlyman")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Abstract Factory pattern example app for RK")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")