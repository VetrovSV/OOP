cmake_minimum_required(VERSION 3.24)

# название проекта my_project
project(hello_world)

# настроки компилятора
set(CMAKE_CXX_STANDARD 20)                  # версия стандарта языка
set(CMAKE_CXX_STANDARD_REQUIRED True)     # включает проверку: задана ли явно версия стандарта языка
add_compile_options(-O2)                    # другие опции компиляции: второй уровень оптимизации кода


# папка для сохранения исполняемого файла: bin
# стоит указать, чтобы отделить от служебных файлов генерируемых CMake
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# add_executable -- цель -- создание исполняемого файла
add_executable(                         
  ${PROJECT_NAME}
  src/main.cpp 
  src/hello_unit.cpp 
  )




# сборку вызывать из каталога simple_executable\src:
# но указать каталог сборки в каталоге simple_executable
# чтобы отделить исходный код от файлов сборки

# cmake -B ../hello_world_build .
# cmake --build ../hello_world_build

# исполняемый файл появится в папке simple_executable\hello_world_build\bin

# -B      - указать путь к каталогу сборки
# .       - имя текущей папки (где находится CMakeLists.txt)

# --build - собрать в указанный каталог 