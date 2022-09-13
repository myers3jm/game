cmake_minimum_required(VERSION 3.10)
# Project name
project(game VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

set(SOURCES main.cpp
    Game.cpp)
add_executable(game ${SOURCES})

target_include_directories(game PUBLIC ${PROJECT_BINARY_DIR})
set_target_properties(game PROPERTIES LINKER_LANGUAGE CXX)

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2 Found: " ${SDL2_VERSION})
    target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
endif()