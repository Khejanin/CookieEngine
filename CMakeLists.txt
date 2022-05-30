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

#GLEW
include_directories(${DEPENDENCIES_DIR}/glew-2.2.0/build/cmake)
set(GLEW_INCLUDE_DIR "${DEPENDENCIES_DIR}/glew-2.2.0/include/GL")
set(GLEW_LIBRARIES "${DEPENDENCIES_DIR}/glew-2.2.0/lib/Release/Win32")
set(GLEW_VERBOSE true)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

# Project
# Core
file(GLOB_RECURSE CORE_SRC "src/core/*")
file(GLOB_RECURSE GRAPHICS_SRC "src/graphics/*")

add_library(${CORE} ${CORE_SRC})
add_library(${GRAPHICS} ${GRAPHICS_SRC})

add_executable(${COOKIE} main.cpp)

include_directories("${SOURCE}")

message("LINKING")
# LINK
# Project
target_link_libraries(${COOKIE} ${CORE})
target_link_libraries(${COOKIE} ${GRAPHICS})

# Third Party
target_link_libraries(${COOKIE} ${OPENGL_gl_LIBRARY})
target_link_libraries(${COOKIE} ${OPENGL_glu_LIBRARY})
target_link_libraries(${COOKIE} GLEW::GLEW)
target_link_libraries(${COOKIE} glfw)