cmake_minimum_required(VERSION 3.14)
project(AbstractFactoryExample VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основное приложение
add_executable(AbstractFactory src/AbstractFactory/Conceptual/main.cc)

# Настройка тестов
enable_testing()

# Вариант 1: Используем системный GTest
find_package(GTest QUIET)

if(GTest_FOUND)
  message(STATUS "Found system GTest")
else()
  # Вариант 2: Загружаем через URL
  message(STATUS "Downloading GTest")
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  FetchContent_MakeAvailable(googletest)
endif()

add_executable(run_tests tests/test_abstract_factory.cpp)

if(GTest_FOUND)
  target_link_libraries(run_tests GTest::GTest GTest::Main pthread)
else()
  target_link_libraries(run_tests gtest gtest_main pthread)
endif()

add_test(NAME AbstractFactoryTests COMMAND run_tests)

# Установка и CPack (остается без изменений)
install(TARGETS AbstractFactory RUNTIME DESTINATION bin)
include(CPack)