cmake_minimum_required(VERSION 3.26)
project(curves)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(curves SHARED
        src/circle.cpp
        src/ellipse.cpp
        src/helix.cpp)

install(TARGETS curves
        LIBRARY DESTINATION lib
)

# add main executable which will use library
add_executable(main.cpp)
target_link_libraries(main curves)
