message(STATUS "Sub Project/Target Name : ${TIMBER_ENGINE_TARGET_NAME} --> CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "            Target Name : ${TIMBER_ENGINE_TARGET_NAME} --> Step 1 : Create library target named : [${TIMBER_ENGINE_TARGET_NAME}]")
add_library(${TIMBER_ENGINE_TARGET_NAME} STATIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp	
 )

message(STATUS "            Target Name : ${TIMBER_ENGINE_TARGET_NAME} --> Step 2 : Add ${CMAKE_CURRENT_SOURCE_DIR}/include folder for include directory")
target_include_directories(${TIMBER_ENGINE_TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#2. After fetch lib we also  need to setup the linking
message(STATUS "            Target Name : ${EAGLE_ENGINE_TARGET_NAME} --> Step 3 : Add all SFML libs files for link directory")
target_link_libraries(${TIMBER_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${TIMBER_ENGINE_TARGET_NAME} PUBLIC sfml-audio)
target_link_libraries(${TIMBER_ENGINE_TARGET_NAME} PUBLIC sfml-main)
target_link_libraries(${TIMBER_ENGINE_TARGET_NAME} PUBLIC sfml-network)
target_link_libraries(${TIMBER_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${TIMBER_ENGINE_TARGET_NAME} PUBLIC sfml-window)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>)
endfunction()

message(STATUS "            Target Name : ${TIMBER_ENGINE_TARGET_NAME} --> Step 4 : Copy all SFML libs files for executable")
CopyLibToTarget(sfml-graphics ${TIMBER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${TIMBER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-main ${TIMBER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-network ${TIMBER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${TIMBER_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${TIMBER_ENGINE_TARGET_NAME})


