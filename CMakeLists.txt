# DEFINITIONS
set(COOKIE cookie)
set(CORE core)
set(GRAPHICS graphics)
set(SOURCE "src")
set(PACKAGES "")
set(DEPENDENCIES_DIR "dependencies")

# SETUP
cmake_minimum_required(VERSION 3.22)
project(${COOKIE})

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/output/libs")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/output/binaries")

message("INCLUDING DIRS")
# INCLUDES
# Third Party
# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

#GLFW : http://www.glfw.org/docs/latest/build_guide.html
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${DEPENDENCIES_DIR}/glfw-3.3.7")
include_directories("${DEPENDENCIES_DIR}/glfw-3.3.7/include")

#GLAD
set(GLAD_SRC "${DEPENDENCIES_DIR}/glad/src/glad.c")
include_directories(${DEPENDENCIES_DIR}/glad/include)

# Project
# Core
file(GLOB_RECURSE CORE_SRC "src/core/*")
file(GLOB_RECURSE GRAPHICS_SRC "src/graphics/*")

add_library(${CORE} ${CORE_SRC})
add_library(${GRAPHICS} ${GRAPHICS_SRC} src/graphics/Window.cpp src/graphics/Window.hpp)

add_executable(${COOKIE} main.cpp ${GLAD_SRC})

include_directories("${SOURCE}")

message("LINKING")
# LINK
# Project
target_link_libraries(${COOKIE} ${CORE})
target_link_libraries(${COOKIE} ${GRAPHICS})

# Third Party
target_link_libraries(${COOKIE} ${OPENGL_gl_LIBRARY})
target_link_libraries(${COOKIE} ${OPENGL_glu_LIBRARY})
target_link_libraries(${COOKIE} glfw)