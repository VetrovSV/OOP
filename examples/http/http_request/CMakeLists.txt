cmake_minimum_required(VERSION 4.1)
project(http_request)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

# Поиск OpenSSL в системе
find_package(OpenSSL REQUIRED)

add_executable(http_request
        http_request.cpp)

# Линковка OpenSSL
target_link_libraries(http_request
        PRIVATE                 # линковка только для этого проекта
        # названия других библиотек
        OpenSSL::SSL
        OpenSSL::Crypto
)

# включение OpenSSL через флаг компилятора
target_compile_definitions(http_request
        PRIVATE
        CPPHTTPLIB_OPENSSL_SUPPORT
)