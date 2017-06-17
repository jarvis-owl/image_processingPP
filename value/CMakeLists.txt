cmake_minimum_required(VERSION 2.8)
project( value2 )
find_package( OpenCV REQUIRED )
add_executable( value2 value2.cpp )
target_link_libraries( value2 ${OpenCV_LIBS} )

#set(INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist/${CMAKE_BUILD_TYPE/bin/}")
#add_subdirectory{src} #requires another cmakelists.txt:

#add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/main.c")
#install(TARGES ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
