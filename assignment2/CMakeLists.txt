cmake_minimum_required(VERSION 3.6)
project(Pandemic_v2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Player.cpp Player.h RoleCard.cpp RoleCard.h ReferenceCard.cpp ReferenceCard.h Pawn.cpp Pawn.h City.cpp City.h PlayerCard.h CityCard.cpp CityCard.h Subject.h Observer.h PlayerView.cpp PlayerView.h)
add_executable(Pandemic_v2 ${SOURCE_FILES} main.cpp Player.cpp Player.h RoleCard.cpp RoleCard.h ReferenceCard.cpp ReferenceCard.h Pawn.cpp Pawn.h City.cpp City.h PlayerCard.h CityCard.cpp CityCard.h PlayerView.cpp PlayerView.h)


set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.63.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(SOURCE_FILES main.cpp Player.cpp Player.h)
    target_link_libraries(SOURCE_FILES ${Boost_LIBRARIES})
endif()