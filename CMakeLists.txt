cmake_minimum_required(VERSION 3.10)
# SET THESE FIRST - BEFORE project()
set(CMAKE_CXX_FLAGS "-DHWY_COMPILE_ONLY_AVX2 -mavx2 -mfma" CACHE STRING "" FORCE)

# Set the project name and version
project(Rubix VERSION 0.3.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-switch-enum -Wswitch -mavx2")
add_compile_definitions(HWY_COMPILE_ONLY_AVX2)
add_compile_options(-mavx2 -mfma -mf16c -DHWY_COMPILE_ONLY_AVX2)

include(FetchContent)
FetchContent_Declare(
    highway
    GIT_REPOSITORY https://github.com/google/highway.git
    GIT_TAG 1.3.0
)
FetchContent_MakeAvailable(highway)
# -fsanitize=address,undefined -g
# Add the executable
add_executable(Rubix main.cpp cube.cpp alg.cpp mini_cube.cpp)
target_link_libraries(Rubix PRIVATE hwy)
target_include_directories(Rubix PUBLIC ${highway_SOURCE_DIR})
