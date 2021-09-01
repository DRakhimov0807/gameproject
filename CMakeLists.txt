cmake_minimum_required(VERSION 3.0.0)
project(proj VERSION 0.1.0)


include(cmake/StandardProjectSettings.cmake)
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_17)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)

add_subdirectory(src)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics window system)


enable_testing()
add_subdirectory(doctest)
include(doctest/doctest.cmake)
