cmake_minimum_required(VERSION 3.24)    # требование к минимальной версии CMake

project(executable_with_test)           # название проекта (далее можно обращаться через переменную: ${PROJECT_NAME} )

set(CMAKE_CXX_STANDARD 23)              # Стандарт С++23

# для поиска заголовочников
# target_include_directories(${PROJECT_NAME} PUBLIC ../src)

# Указание цели сборки: исполняемый файл
# executable_with_test -- имя цели = имя исполняемого файла
# main.cpp -- список файлов исходного кода, необходимых для компиляции
add_executable(${PROJECT_NAME} src/main.cpp)

# добавить подпроект CMake
add_subdirectory(test test_build)



# Это основной файл проекта
# Сборка (из каталого проекта)
cmake -B build .
cmake --build build  

# запуск тестов (исполняемого файла с тестами)
build/test_build/main_test