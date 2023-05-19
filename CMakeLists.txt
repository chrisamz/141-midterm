cmake_minimum_required(VERSION 3.0)
project(mice-a C)

include_directories(include)

add_executable(mice-a src/mice.c src/vec2d.c src/vec3d.c src/simulate.c)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(mice-a PUBLIC ${MATH_LIBRARY})
endif()