cmake_minimum_required(VERSION 3.0.2)
project(crostest)

set(CMAKE_C_FLAGS "-no-pie")
set(CMAKE_CXX_FLAGS "-no-pie")

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  rtcop
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES crostest
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
    ${rtcop_INCLUDE_DIRS}/rtcop
    Generated
    .
    ${catkin_INCLUDE_DIRS}
)

file(GLOB MY_L_SOURCES *.lcpp)
add_custom_command(OUTPUT Generated COMMAND "mono" "${rtcop_DIR}/../LayerCompiler.exe" "${MY_L_SOURCES}" "-r" "${PROJECT_SOURCE_DIR}" "-i" "${PROJECT_SOURCE_DIR}" "-t" "linux64" "-e" "gcc" "-o" "${PROJECT_SOURCE_DIR}/Generated")
file(GLOB MY_SOURCES *.cpp Generated/*.cpp)
add_executable(${PROJECT_NAME}_node Generated ${MY_SOURCES})
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

