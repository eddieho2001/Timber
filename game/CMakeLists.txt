message(STATUS "Sub Project/Target Name : ${TIMBER_GAME_TARGET_NAME} --> CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "            Target Name : ${TIMBER_GAME_TARGET_NAME} --> Step 1 : Create excutable target named : [${TIMBER_GAME_TARGET_NAME}]")
add_executable(${TIMBER_GAME_TARGET_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/include/game_framework/GameApplication.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/game_framework/GameApplication.cpp
)

message(STATUS "            Target Name : ${TIMBER_GAME_TARGET_NAME} --> Step 2 : Add  ${CMAKE_CURRENT_SOURCE_DIR}/include folder for include directory")
target_include_directories(${TIMBER_GAME_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#2. For the application, it not need to link the sfml libraries file again, it only linking the engine.lib is ok
message(STATUS "            Target Name : ${TIMBER_GAME_TARGET_NAME} --> Step 3 : Add all ${TIMBER_ENGINE_TARGET_NAME} libs for linking")
target_link_libraries(${TIMBER_GAME_TARGET_NAME} PUBLIC ${TIMBER_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	$<TARGET_FILE_DIR:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>)
endfunction()

message(STATUS "            Target Name : ${TIMBER_GAME_TARGET_NAME} --> Step 4 : Copy ${TIMBER_ENGINE_TARGET_NAME}.lib file for executable")
CopyLibDirToTarget(${TIMBER_ENGINE_TARGET_NAME} ${TIMBER_GAME_TARGET_NAME})

#Handle relative path for game assets 
set(ASSET_FOLDER_NAME "assets")
set(ASSET_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${ASSET_FOLDER_NAME}")

add_custom_command(
	TARGET ${TIMBER_GAME_TARGET_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	${ASSET_SRC_DIR}
	$<TARGET_FILE_DIR:${TIMBER_GAME_TARGET_NAME}>/${ASSET_FOLDER_NAME}
)

message(STATUS "${TIMBER_GAME_TARGET_NAME} -  Copied assets from ${ASSET_SRC_DIR} to ${TIMBER_GAME_TARGET_NAME}/${ASSET_FOLDER_NAME}")
message(STATUS "${TIMBER_GAME_TARGET_NAME} -  Modified config.h.in --> config.h for assets resources...")

configure_file(
	"config.h.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/config.h" ESCAPE_QUOTES
)




