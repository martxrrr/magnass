cmake_minimum_required(VERSION 3.10)
project(chess_engine 
        VERSION 0.0.1
        LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 REQUIRED COMPONENTS  Graphics Window System)


file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(magnass ${SRC_FILES})
target_include_directories(magnass PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(magnass
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)