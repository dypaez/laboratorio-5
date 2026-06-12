cmake_minimum_required(VERSION 3.10)
project(DCDSistema)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(dcd_sistema
    DataTypes.cpp
    Usuario.cpp
    Lector.cpp
    Funcionario.cpp
    Material.cpp
    Libro.cpp
    Revista.cpp
    Prestamo.cpp
    Puntaje.cpp
    ManejadorPersona.cpp
    ManejadorMaterial.cpp
    Sistema.cpp
    Fabrica.cpp
)
