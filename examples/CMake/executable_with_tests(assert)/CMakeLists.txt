cmake_minimum_required(VERSION 3.24)


project(example)

# настроки компилятора
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-O2)

# папка для сохранения исполняемого файла: bin
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)


# add_executable -- цель -- создание исполняемого файла
add_executable(                         
  ${PROJECT_NAME}
  src/main.cpp
  src/geometry.cpp
  )
