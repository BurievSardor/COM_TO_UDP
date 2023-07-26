cmake_minimum_required(VERSION 3.14)

project(COM_TO_UDP LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core SerialPort Network)

add_executable(COM_TO_UDP
  main.cpp
  worker.cpp
  message.cpp
  worker.h
  message.h
)
target_link_libraries(COM_TO_UDP Qt5::Core Qt5::SerialPort Qt5::Network)

install(TARGETS COM_TO_UDP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
