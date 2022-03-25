cmake_minimum_required(VERSION 3.16)

project(manager-go)

#set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB systems ${CMAKE_SOURCE_DIR}/src/systems/*)
add_executable(manager-go ${CMAKE_SOURCE_DIR}/src/main.c ${CMAKE_SOURCE_DIR}/src/scenes.c ${systems})

target_link_libraries(manager-go flecs raylib pthread dl m)
