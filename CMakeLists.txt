cmake_minimum_required(VERSION 3.16)

project(manager-go)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(manager-go ${CMAKE_SOURCE_DIR}/src/main.c)

target_link_libraries(manager-go flecs raylib pthread dl m)
