cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME autocomplete)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}./../bin)

file(GLOB CPPS "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${CPPS})