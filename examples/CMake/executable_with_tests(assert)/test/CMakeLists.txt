# для теста стоит создать отдельный файл
cmake_minimum_required(VERSION 3.2)

project(my_test)

add_executable(my_test test.cpp ../src/geometry.cpp)

# для поиска заголовочников
target_include_directories(my_test PUBLIC ../src)


# Включить поддержку тестирования:
enable_testing()

# название теста и команда (здесь, имя исполняемого файла)
add_test(FirstTest my_test)