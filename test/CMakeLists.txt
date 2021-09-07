cmake_minimum_required(VERSION 3.16)
project(B_OOP_400_BER_4_1_arcade_adrian_lewitzki)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ncurses)

file(GLOB files "games/*/*"
        "core/*"
        "graphical/*/*")
add_executable(B_OOP_400_BER_4_1_arcade_adrian_lewitzki ${files} structure/main.cpp)