cmake_minimum_required(VERSION 3.5)
project(PngToAscii)

set(OpenCV_DIR D:/Nikolas/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS})
