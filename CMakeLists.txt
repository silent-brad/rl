# CMake Build File
cmake_minimum_required(VERSION 3.5)
project(rl)
set(CMAKE_CXX_STANDARD 23)

# Find raylib package
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link raylib
target_link_libraries(${PROJECT_NAME} ${RAYLIB_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${RAYLIB_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${RAYLIB_CFLAGS_OTHER})
