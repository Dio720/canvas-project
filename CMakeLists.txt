cmake_minimum_required(VERSION 3.5)
project (Canvas VERSION 1.0.0 LANGUAGES CXX )

#=== CREATING COMPILING DATABASE ===#
# Currently CMake (since 2.8.5) supports generation of compilation databases
# for Unix Makefile builds (Ninja builds in the works) with the option
# CMAKE_EXPORT_COMPILE_COMMANDS.
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#=== SETTING VARIABLES ===#
# Appending to existing flags the correct way (two methods)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g3")
# string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")


#=== ADDING SUBDIRECTORIES ===#
# The add_subdirectory() command allows a project to bring another directory into the build. That
# directory must have its own CMakeLists.txt file which will be processed at the point where
# add_subdirectory() is called and a corresponding directory will be created for it in the project’s
set( EXT_LIB "lodepng" )
add_subdirectory(ext_lib) # This will ask this lib to be build

set ( APP_NAME "canvas")
# Specifies include directories to use when compiling a given target.
add_executable( ${APP_NAME} src/canvas.cpp src/driver_canvas.cpp )
target_include_directories( ${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src )
target_include_directories( ${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/ext_lib )
target_include_directories( ${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/ext_lib )
target_compile_features( ${APP_NAME}  PUBLIC cxx_std_17 )
target_link_libraries( ${APP_NAME} PRIVATE ${EXT_LIB})

# * CMAKE_SOURCE_DIR
# The top-most directory of the source tree (i.e. where the top-most CMakeLists.txt file resides).
# This variable never changes its value.

# * CMAKE_BINARY_DIR
# The top-most directory of the build tree. This variable never changes its value.
