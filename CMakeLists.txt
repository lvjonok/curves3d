# let's start by specifying the minimal CMake version
cmake_minimum_required(VERSION 3.26)
# we create a project named "curves"
project(curves)

option(CURVES_TESTS "Build tests" ON)

# setting the C++ standard
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

set(CURVES_INC
  include/curves/curves.h
  include/curves/point.h
  include/curves/vector3.h
)

set(CURVES_SRC
  src/circle.cpp
  src/ellipse.cpp
  src/helix.cpp
)

# build library
add_library(curves ${CURVES_INC} ${CURVES_SRC})
target_include_directories(curves PUBLIC include)

# build main executable with task
add_executable(curves_task main.cpp)
target_link_libraries(curves_task curves)

if (CURVES_TESTS)
  # See: https://cliutils.gitlab.io/modern-cmake/chapters/testing/googletest.html
  enable_testing()

  add_subdirectory("${PROJECT_SOURCE_DIR}/tests/googletest/")
  set_target_properties(gtest gtest_main PROPERTIES FOLDER GTest)

  set(CurvesTests_SRC
    tests/test_circle.cpp
    tests/test_ellipse.cpp
    tests/test_helix.cpp
  )
  add_executable(CurvesTests ${CurvesTests_SRC})
  target_link_libraries(CurvesTests gtest gtest_main curves)
endif ()