cmake_minimum_required(VERSION 2.4.7)
PROJECT(indi_gonzobox CXX C)
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")
set(BIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin")

find_package(INDI REQUIRED)

include_directories( ${CMAKE_CURRENT_BINARY_DIR})
include_directories( ${CMAKE_CURRENT_SOURCE_DIR})
include_directories( ${INDI_INCLUDE_DIR})

########### Indi Rain Sensor Driver ###############

set(RainSensor_SRCS
        ${CMAKE_SOURCE_DIR}/indi_rainsensor.cpp
   )

add_executable(indi_rainsensor ${RainSensor_SRCS})
target_link_libraries(indi_rainsensor indidriver ${CURL_LIBRARIES})
install(TARGETS indi_rainsensor RUNTIME DESTINATION bin )
