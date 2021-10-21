cmake_minimum_required(VERSION 3.13.1)
# automatically add library config header to every source file
add_definitions(-include ${CMAKE_SOURCE_DIR}/dap-core-config.h)

# automatically add library utility header to every source file
add_definitions(-include ${CMAKE_SOURCE_DIR}/includes/utils/utils.h)

# setting cross-compiler
# TODO: this should be done depending on the chosen HIC
# Here, we are a bit lazy and tell that this is an ARM target
set(BAREMETAL_ARM_TOOLCHAIN_PATH "/home/giulianofranchetto/Desktop/gcc-arm-none-eabi/bin/")
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/cross_compile_arm.cmake)

project(dap-core VERSION 0.0.1 LANGUAGES C)

add_library(dap-core STATIC)

add_subdirectory(src)
add_subdirectory(includes)

set_target_properties(dap-core PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(dap-core PROPERTIES SOVERSION 1)