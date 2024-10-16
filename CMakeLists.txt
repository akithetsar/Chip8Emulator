cmake_minimum_required(VERSION 3.24)
project(Chip8Emulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chip8Emulator src/main.cpp
        h/Chip8.h
        h/Instruction.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Project 3/SFML/include/SFML)
include_directories(C:/SFML/include)

target_link_libraries(Chip8Emulator sfml-system sfml-window sfml-graphics sfml-audio)