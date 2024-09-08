cmake_minimum_required(VERSION 3.24)

# название проекта hello_world_lib
project(hello_world_lib
        DESCRIPTION "Пример сборки библиотеки с CMake")


set(CMAKE_CXX_STANDARD 20)                  # версия стандарта языка
set(CMAKE_CXX_STANDARD_REQUIRED True)       # включает проверку: задана ли явно версия стандарта языка
add_compile_options(-O2)                    # другие опции компиляции: второй уровень оптимизации кода


# папка для сохранения файла библиотеки: lib
# стоит указать, чтобы отделить от служебных файлов генерируемых CMake
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)

# add_library -- цель -- создание библиотеки
add_library(                         
  ${PROJECT_NAME} STATIC
  src/hello_unit.cpp 
  )

# STATIC -- создание статической библиотеки; такая библиотека включается в исполняемый файлы
# SAHRED -- создание общей библиотеки; такую библиотеку придётся распространять вместе с исполняемым файлом



# сборку вызывать из каталога library_example
# но указать каталог сборки в каталоге HW_lib_build, чтобы отделить исходный код от файлов сборки

# cmake -B ../HW_lib_build .
# cmake --build ../HW_lib_build

# файл библиотеки (.so в Linux или .lib в Windows) появится в папке library_example\HW_lib_build\lib

# -B      - указать путь к каталогу сборки
# .       - имя текущей папки (где находится CMakeLists.txt)

# --build - собрать в указанный каталог 