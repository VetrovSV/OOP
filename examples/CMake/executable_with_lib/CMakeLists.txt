cmake_minimum_required(VERSION 3.24)

# пример программы, использующей скомпилированную библиотеку из другой папки
# библиотека скомпилированна в Ubuntu

# название проекта my_project
project(hello_world_with_lib)

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
  )



# Дополнительные папки и файлы можно указаывать после того, как задана цель (add_executable или add_library)

# папка для поиска файлов исходного кода (cpp и h), 
target_include_directories(${PROJECT_NAME} PUBLIC include)
# Второй аргумент задёт видимость включаемых файлов для проектов, использующих данный (если они есть)

# папки для компоновщика (линкера)
target_link_directories(${PROJECT_NAME} PUBLIC lib)
target_link_libraries(${PROJECT_NAME} PUBLIC my_lib.a)



# сборку вызывать из каталога executable_with_lib:

# cmake -B my_build .
# cmake --build .my_build

# исполняемый файл появится в папке simple_executable\hello_world_build\bin

# -B      - указать путь к каталогу сборки
# .       - имя текущей папки (где находится CMakeLists.txt)

# --build - собрать в указанный каталог 


# команды типа target_include_xxx нужны для компилятора
# команды типа target_link_xxx нужны для компоновщика (линкера)