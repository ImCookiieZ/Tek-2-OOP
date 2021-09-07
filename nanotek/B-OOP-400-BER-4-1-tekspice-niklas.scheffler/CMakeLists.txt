cmake_minimum_required(VERSION 3.16)
project(B_OOP_400_BER_4_1_tekspice_niklas_scheffler)

set(CMAKE_CXX_STANDARD 14)
FILE(GLOB lib_dir "src/*.cpp" "include/*.hpp" "include/Chipsets/*.hpp" "src/Chipsets/*.cpp")
add_executable(B_OOP_400_BER_4_1_tekspice_niklas_scheffler ${lib_dir})