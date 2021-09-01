cmake_minimum_required(VERSION 3.0.0)

enable_testing()

add_executable(proj main.cpp ball.cpp player.cpp menu.cpp)
add_executable(proj_test tests.cpp ball.cpp player.cpp)

target_link_libraries(proj_test PUBLIC doctest::doctest default)
target_link_libraries(proj PUBLIC doctest::doctest default)
include(../doctest/doctest.cmake)
doctest_discover_tests(proj_test)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics window system)
target_link_libraries(proj PUBLIC sfml-system sfml-graphics sfml-window sfml-audio)
target_link_libraries(proj_test PUBLIC sfml-system sfml-graphics sfml-window sfml-audio)