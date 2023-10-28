# Tarea 1

## Introducción
Este README da instrucciones para configurar y correr el código de la Tarea 3. Para compilar y ejecutar el código de manera correcta, se tienen que seguir las siguientes instrucciones.

## Estructura de Directorios

Asegurarse de tener los siguientes directorios y archivos (algunos sacados del [repositorio del ramo](https://github.com/jmsaavedrar/eda_cppal)) al mismo nivel:

- `code`: Contiene todos los archivos que están en las carpetas `include/trees` y `src`, dentro del directorio `abb` del repositorio. También se encuentran los archivos `infToPost.{hpp, cpp}` y `postToTree.{hpp, cpp}`. Todos los archivos `.hpp` se encuentran en un sub-directorio llamado `hdir`, y los `.cpp` en otro llamado `source`. A la par de ambos sub-directorios se encuentra un archivo `hfiles.hpp`.
- `CMakeLists.txt`: Archivo para realizar compilazión a través de CMake.
- `build`: Directorio para guardar archivos de compilación de CMake.
- `main.cpp`: Archivo de ejecución principal.

## Instrucciones

1. Ubicarse en el directorio `build`.

2. Correr el siguiente comando de linea para generar los archivos necesarios para compilar con [CMake](#Cmake):
```bash
$ cmake .. 
```

3. Compilar el código usando `make`:
```bash
$ make
```

4. Ejecutar el código con el siguiente comando:
```bash
$ ./test
```

Se puede ver el [repositorio de la tarea](https://github.com/CodeByManu/Tarea3_EDA) como ejemplo de estructura.

## CMake
```CMake
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/c++")

# set the project name

project(calculadora
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(src)
#add_subdirectory(tests)

add_executable(test main.cpp code/source/infToPost.cpp code/source/abb.cpp code/source/abbNode.cpp code/source/postToTree.cpp)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)

# add the executable
```
