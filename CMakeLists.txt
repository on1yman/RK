cmake_minimum_required(VERSION 3.14)
project(AbstractFactoryExample VERSION 1.0.0 LANGUAGES CXX)

# Базовые настройки компиляции
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Основное приложение
add_executable(AbstractFactory src/AbstractFactory/Conceptual/main.cc)

# Настройка тестов
option(BUILD_TESTING "Build tests" ON)

if(BUILD_TESTING)
    enable_testing()
    
    # Загрузка GTest через FetchContent (предпочтительный способ)
    message(STATUS "Configuring tests...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(googletest)
    
    if(NOT googletest_POPULATED)
        message(FATAL_ERROR "Failed to fetch googletest!")
    endif()

    add_executable(run_tests tests/test_abstract_factory.cpp)
    target_link_libraries(run_tests PRIVATE 
        GTest::GTest 
        GTest::Main 
        Threads::Threads)
    
    add_test(NAME AbstractFactoryTests COMMAND run_tests)
endif()

# Установка основного приложения
install(TARGETS AbstractFactory
    RUNTIME DESTINATION bin
)

# Настройка CPack
set(CPACK_PACKAGE_NAME "abstractfactory-example")
string(TIMESTAMP CPACK_PACKAGE_RELEASE_DATE "%Y-%m-%d")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "RK")
set(CPACK_PACKAGE_CONTACT "Maintainer <maintainer@example.com>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Abstract Factory pattern implementation")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/your/repo")

# DEB-специфичные настройки
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Maintainer <maintainer@example.com>")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Implementation of Abstract Factory design pattern")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

# Проверка обязательных полей перед включением CPack
if(NOT CPACK_DEBIAN_PACKAGE_MAINTAINER)
    message(FATAL_ERROR "Debian package maintainer must be set!")
endif()

include(CPack)