cmake_minimum_required (VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE "ClangToolchain.cmake")

project(12-LIS3MDL-DRV)

# Set names and variables
set(TARGET_NAME ${CMAKE_PROJECT_NAME}) 

# Add executable
add_executable(${TARGET_NAME})

add_subdirectory(app)
add_subdirectory(drv)
add_subdirectory(hal)
