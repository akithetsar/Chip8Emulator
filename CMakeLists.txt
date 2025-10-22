cmake_minimum_required(VERSION 3.16)
project(Chip8Emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL3_PATH "${CMAKE_SOURCE_DIR}/libs/x86_64-w64-mingw32")

include_directories(${SDL3_PATH}/include)
link_directories(${SDL3_PATH}/lib)

add_executable(Chip8Emulator
        src/main.cpp
        src/Platform.cpp
        src/Chip8.cpp  # Add if you have this
)

target_link_libraries(Chip8Emulator SDL3)

add_custom_command(TARGET Chip8Emulator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3_PATH}/bin/SDL3.dll"
        $<TARGET_FILE_DIR:Chip8Emulator>
)