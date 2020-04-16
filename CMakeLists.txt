cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME SpaceInvaders3D)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)
link_libraries(stdc++fs)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/libs/SFML-2.5.1/lib/cmake/SFML")
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")
file(GLOB_RECURSE REQUIRED_DLLS_FOR_SFML "libs/SFML-2.5.1/bin/*.dll" "libs/required_dll/*.dll")
file(COPY ${REQUIRED_DLLS_FOR_SFML} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} libs/assimp-5.0.1/include)
include_directories("libs")
include_directories("libs/glad/include/")
include_directories("src/")
include_directories("libs/GLM/")

# Project directories
include_directories("src/Display/")
include_directories("src/GUI/")
include_directories("src/Managers/")
include_directories("src/Models/Functionality/")
include_directories("src/Models/OBJ/Entities/")
include_directories("src/Player/")
include_directories("src/Shaders/")
include_directories("src/States/Functionality/")
include_directories("src/States/GameStates/")
include_directories("src/Utilities/")



# Required assimp stuff
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT ON)
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(libs/assimp-5.0.1)

target_compile_options(assimp PRIVATE -w)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp libs/glad/src/glad.c)
target_link_libraries(${PROJECT_NAME} assimp sfml-audio sfml-graphics sfml-window sfml-system ${OPENGL_LIBRARIES})
