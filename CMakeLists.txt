cmake_minimum_required(VERSION 3.15)

# Nombre del proyecto y estándar de C++
project(ReaderJsonProject VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Carpeta de código fuente
set(SOURCES
    main.cpp
)

# Ejecutable
add_executable(ReaderJsonExecutable ${SOURCES})

# Incluimos la carpeta actual para los headers
target_include_directories(ReaderJsonExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
