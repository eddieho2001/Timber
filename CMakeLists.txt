cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)

set(QUILL_LIB_NAME quill)
set(SFML_LIB_NAME SFML)
# define the project with name as LightYears
project(Timber VERSION 0.0.3)
message(STATUS "project level --> Project Name           : ${PROJECT_NAME}")
message(STATUS "project level --> Project Current Version: ${CURRENT_VERSION}")
message(STATUS "project level --> external Libraries     : ${SFML_LIB_NAME}, ${QUILL_LIB_NAME}")
message(STATUS "project level --> CMAKE_PROJECT_NAME     : ${CMAKE_PROJECT_NAME}")
message(STATUS "project level --> PROJECT_SOURCE_DIR     : ${PROJECT_SOURCE_DIR}")
message(STATUS "project level --> PROJECT_BINARY_DIR     : ${PROJECT_BINARY_DIR}")

message(STATUS "task hository --> v0.0.1 ---> Fixed-frame rate method not work decribed in [SFML Game Developement By Example]")
message(STATUS "task hository --> v0.0.2 ---> split project as 1. engine library target 2. game executable target")
message(STATUS "task hository --> v0.0.3 ---> reference readme.txt")


# set all built output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#create variable for executable target name

#1. In order to use external library, we using cmake fetch content feature
include(FetchContent)
FetchContent_Declare(
	${SFML_LIB_NAME} 
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.1
	GIT_SHALLOW FALSE)
FetchContent_MakeAvailable(${SFML_LIB_NAME})

set(TIMBER_ENGINE_TARGET_NAME engine)
set(TIMBER_GAME_TARGET_NAME game)
# add sub projects
add_subdirectory(engine)
add_subdirectory(game) 
add_subdirectory(quill)





