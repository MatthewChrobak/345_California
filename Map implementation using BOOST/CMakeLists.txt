cmake_minimum_required(VERSION 3.6)
project(Board_boost)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vertex.cpp Vertex.h Edge.cpp Edge.h Board.cpp Board.h)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package(Boost 1.63.0 COMPONENTS graph log log_setup thread date_time filesystem system REQUIRED)
link_libraries(${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_LIBRARIES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} -lpthread)
target_link_libraries(${PROJECT_NAME}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )
