cmake_minimum_required(VERSION 3.0.0)
project(task1 VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(task1 
    src/main.cpp 
    src/glad.h 
    src/glad.c
)

target_link_libraries(task1 
    glfw 
    OpenGL::GL
)