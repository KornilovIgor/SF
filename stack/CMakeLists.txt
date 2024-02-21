cmake_minimum_required(VERSION 3.27)

set(PROJECT_NAME stack)
project(${PROJECT_NAME})

file(GLOB CPPS "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${CPPS})
