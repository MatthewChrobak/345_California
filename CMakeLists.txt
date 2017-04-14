cmake_minimum_required(VERSION 3.7)
project(Pandemic_finalBuild)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ArrayGraph.cpp ArrayGraph.h ArrayGraphNode.cpp ArrayGraphNode.h Board.cpp Board.h Buttons.cpp Buttons.h CheckBoxes.cpp CheckBoxes.h City.cpp City.h GuiManager.cpp GuiManager.h GraphicsManager.cpp GraphicsManager.h GraphicsSystem.h CityCard.cpp CityCard.h CityGraph.cpp CityGraph.h FileSystem.cpp FileSystem.h FileStream.cpp FileStream.h CommonContext.cpp CommonContext.h EpidemicCard.cpp EpidemicCard.h PlayerCard.h Paths.h Pawn.cpp Pawn.h Game.cpp Game.h UICheckbox.h UIButton.cpp UIButton.h UICheckbox.cpp UIDefinitions.h UIElement.cpp UIElement.h UIFrame.cpp UIFrame.h InfectionColors.h SurfaceContext.cpp SurfaceContext.h TextContext.cpp TextContext.h UITextbox.cpp UITextbox.h UIMessageBox.cpp UIMessageBox.h SfmlFontManager.cpp SfmlFontManager.h SfmlGraphicsSystem.cpp SfmlGraphicsSystem.h SfmlSurfaceManager.cpp SfmlSurfaceManager.h TextBoxes.cpp TextBoxes.h MapEditingActions.h Player.cpp Player.h PlayerActions.h RoleCard.cpp RoleCard.h RandomNumberGenerator.cpp RandomNumberGenerator.h EventCard.cpp EventCard.h Frames.cpp Frames.h InfectionCard.cpp InfectionCard.h GameRenderer.cpp GameRenderer.h PlayerCard.cpp PlayerAction.cpp PlayerAction.h PlayerRoleCard.cpp PlayerRoleCard.h)
add_executable(Pandemic_finalBuild ${SOURCE_FILES})

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package(Boost 1.63.0 COMPONENTS graph log log_setup thread date_time filesystem system REQUIRED)
link_libraries(${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_LIBRARIES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} -lpthread)
target_link_libraries(${PROJECT_NAME}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_LOG_SETUP_LIBRARY}
        ${Boost_LOG_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        )

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
