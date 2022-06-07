cmake_minimum_required(VERSION 3.0.0)
project(skmotion VERSION 0.1.0)

find_package(Qt6 COMPONENTS Widgets)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBVPX REQUIRED vpx>=1.10.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH "bin")
add_executable(skmotion 
    "include/expected.h"
    "include/userface.h"
    "include/recorder.h"
    "include/streamer.h"
    "src/userface.cpp"
    "src/recorder.cpp"
    "src/streamer.cpp"
    "src/main.cpp")

target_include_directories(skmotion PUBLIC "include" ${LIBVPX_INCLUDE_DIRS})
target_link_libraries(skmotion Qt::Widgets ${LIBVPX_LINK_LIBRARIES})
set_target_properties(skmotion PROPERTIES
    CXX_STANDARD 17
    # WIN32_EXECUTABLE ON
    # MACOSX_BUNDLE ON
)