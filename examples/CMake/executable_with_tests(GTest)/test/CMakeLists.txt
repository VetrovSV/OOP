cmake_minimum_required(VERSION 3.24)    # требование к минимальной версии CMake

project(main_test)                      # название проекта (далее можно обращаться через переменную: ${PROJECT_NAME} )


# Подключает модуль FetchContent для CMake
# FetchContent используется для загрузки внешних зависимостей, входит в состав CMake 3.11+
include(FetchContent)
# Объявление зависимости
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Загрузка зависимости
FetchContent_MakeAvailable(googletest)


# добавление ещё одной цели -- исполняемый файл ${PROJECT_NAME} для теста из файла main_test.cpp
add_executable(${PROJECT_NAME} main_test.cpp)
# для компиляции файла с тестами нужна дополнительная библиотека GoogleTest,
# добавим её как составную часть цели main_test
target_link_libraries( ${PROJECT_NAME}  GTest::gtest_main)

# сделать тест частью проекта
enable_testing()
# Подключает модуль GoogleTest для CMake
include(GoogleTest)
# Запустить файл main_test чтобы получить имена тестов (но не выполнить тесты)
gtest_discover_tests(${PROJECT_NAME})
