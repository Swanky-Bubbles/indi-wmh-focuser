cmake_minimum_required(VERSION 3.5)
project(indi_wmh_focuser)

find_package(INDI REQUIRED)
find_package(WiringPi REQUIRED)

add_executable(indi_wmh_focuser
    wmh_focuser.cpp
    byj48motor.cpp
)

target_link_libraries(indi_wmh_focuser indi wiringPi)
set(CMAKE_CXX_STANDARD 17)
