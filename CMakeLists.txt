cmake_minimum_required(VERSION 2.8)
project(videoConverter)

find_package(OpenCV REQUIRED)
#if(NOT WIN32)
#add_definitions("-std=c++0x -03")
#endif(NOT WIN32)

add_executable(${PROJECT_NAME} starter_video.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
