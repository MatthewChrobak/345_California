# CMake version requirements
cmake_minimum_required(VERSION 3.6)

# Set the project and exe names
project (Pandemic)
set(EXECUTABLE_NAME "Pandemic")

# Include all files.
file(GLOB SOURCE_FILES
	"src/*.h"
	"src/*.cpp"
)

# Figure out what OS we're using.
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")

endif()


# Creating the executable based on the source files.
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})



# Figure out what compiler we're using
if (CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
	set(SFML_ROOT "libraries/SFML-2.4.2-osx-clang/")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	# It's Visual Studio. What version?
	if (MSVC_VERSION MATCHES "1800")
		set(SFML_ROOT "libraries/SFML-2.4.2-windows-vc12-64-bit/SFML-2.4.2/")
	elseif (MSVC_VERSION MATCHES "1900")
		set(SFML_ROOT "libraries/SFML-2.4.2-windows-vc14-64-bit/SFML-2.4.2/")
	elseif (MSVC_VERSION MATCHES "1910")
		set(SFML_ROOT "libraries/SFML-2.4.2-windows-vc14-64-bit/SFML-2.4.2/")
	else()
		message("Unknown version of MSVC")
	endif()
else()
	message ("Unknown compiler - SFML's Root was not set.")
endif()


# Link SFML
if (SFML_ROOT)
	set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/${SFML_ROOT}/cmake/Modules/")
	find_package(SFML REQUIRED system window graphics audio)
	if (SFML_FOUND)
		include_directories(${SFML_INCLUDE_DIR})
		target_link_libraries(Pandemic ${SFML_LIBRARIES})
	endif()
endif()


#Boost implementation starts here
set(CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package(Boost 1.63.0 COMPONENTS graph log log_setup thread date_time filesystem system REQUIRED)
link_libraries(${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_LIBRARIES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} -lpthread)
target_link_libraries(${PROJECT_NAME}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )

