cmake_minimum_required(VERSION 3.5)
project(PngToAscii)

set(HEADERS
    RGB.h
    Image.h
    ImageToAscii.h
)

set(OpenCV_DIR D:/Nikolas/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(main main.cpp ${HEADERS})

target_link_libraries(main ${OpenCV_LIBS})
