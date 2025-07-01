cmake_minimum_required(VERSION 3.10)

# Название проекта
project(hello_cmake)

set(CMAKE_C_STANDARD 23) 
add_compile_options(-Os)

# Исходники, из которых должен получиться исполняемый файл
add_executable( 
                ${PROJECT_NAME}     
                main.c   
                )
                # имя исполняемого файла задано через переменную - ${PROJECT_NAME}. Фактически это hello_cmake
                # добавить .c файлы при необходимости

# Конфигурирование сборки (из папки src):
#   cmake -B ../build . 
#   будет создана папка build
# Сборка
#   cmake
# Запуск
#   ../build/hello_cmake