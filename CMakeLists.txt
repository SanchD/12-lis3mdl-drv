cmake_minimum_required (VERSION 3.12)

set(CMAKE_TOOLCHAIN_FILE "ClangToolchain.cmake")

project(12-LIS3MDL-DRV)

# Set names and variables
set(TARGET_NAME ${CMAKE_PROJECT_NAME}) 

# Add executable
add_executable(${TARGET_NAME})

FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app
    ${CMAKE_CURRENT_SOURCE_DIR}/drv/lis3mdl-pid
    ${CMAKE_CURRENT_SOURCE_DIR}/hal
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/i2c
)

target_sources(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/drv/lis3mdl-pid/lis3mdl_reg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/i2c/i2c_hal.c
)
