cmake_minimum_required (VERSION 3.5)
if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif(UNIX)
project(avgservertest)
set (CMAKE_CXX_STANDARD 11)
include_directories("${CMAKE_SOURCE_DIR}" ../include /root/workspace/casablanca/Release/include /root/workspace/CloudifyAVG/proj_PA2/ut/lib/gtest)
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

add_executable(avgservertest
  ./avgserver_test.cc
   /root/workspace/CloudifyAVG/proj_PA2/ut/lib/gtest/gmain.cc 
    /root/workspace/CloudifyAVG/proj_PA2/ut/lib/gtest/gmock-gtest-all.C
  )

set(Casablanca_LIBRARIES "-lboost_system -lcrypto -lssl -lcpprest")
	target_link_libraries(avgservertest ${Casablanca_LIBRARIES})
