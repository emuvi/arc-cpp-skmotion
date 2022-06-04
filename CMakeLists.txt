cmake_minimum_required(VERSION 3.0.0)
project(skmotion VERSION 0.1.0)

find_package(Qt6 COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH "bin")
add_executable(skmotion 
    "include/userface.h"
    "src/userface.cpp"
    "src/main.cpp")

target_include_directories(skmotion PUBLIC "include")
target_link_libraries(skmotion Qt::Widgets)
set_target_properties(skmotion PROPERTIES
    CXX_STANDARD 17
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)