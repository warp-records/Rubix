
cmake_minimum_required(VERSION 3.10)
# SET THESE FIRST - BEFORE project()

# Set the project name and version
project(Rubix VERSION 0.3.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

target_compile_options(Rubix PRIVATE -O2 -Wno-switch-enum -Wswitch -mavx2 -march=native -pg)
target_link_libraries(Rubix PRIVATE hwy)
target_link_options(Rubix PRIVATE -pg)

target_include_directories(Rubix PUBLIC ${highway_SOURCE_DIR})
