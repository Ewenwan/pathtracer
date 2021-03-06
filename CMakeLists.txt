cmake_minimum_required (VERSION 2.6)

project(pathtracer)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

if(CMAKE_COMPILER_IS_GNUCXX)
  message(STATUS "GCC detected, adding compile flags")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

file(GLOB SOURCES
  src/*.h
  src/*.cpp
)

add_executable(pathtracer ${SOURCES})

add_subdirectory(3rdparty/lua)
add_subdirectory(3rdparty/tinyobjloader)

find_package(Threads)

target_link_libraries(pathtracer liblua ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(pathtracer PUBLIC
  3rdparty/lua
  3rdparty/lua/src
  3rdparty/stb
  3rdparty/tinyobjloader)
