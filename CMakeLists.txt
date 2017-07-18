cmake_minimum_required(VERSION 3.7)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cpp/CPU_C.cpp cpp/CPU_C.h cpp/CPU.cpp)
add_executable(cpp ${SOURCE_FILES})
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include/)
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include/linux/)