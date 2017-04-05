cmake_minimum_required (VERSION 3.5)
if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif(UNIX)
project(avgclient)
set (CMAKE_CXX_STANDARD 11)
include_directories("${CMAKE_SOURCE_DIR}" /root/workspace/casablanca/Release/include ${CMAKE_SOURCE_DIR}/include)
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

add_executable(avgclient
  main.cpp
  src/avgclient.cpp
  )

set(Casablanca_LIBRARIES "-lboost_system -lcrypto -lssl -lcpprest")
	target_link_libraries(avgclient ${Casablanca_LIBRARIES})
