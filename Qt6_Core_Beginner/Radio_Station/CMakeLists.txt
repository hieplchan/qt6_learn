cmake_minimum_required(VERSION 3.16)

project(Radio_Station LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Radio_Station
  main.cpp
  radio.h radio.cpp
  station.h station.cpp
)
target_link_libraries(Radio_Station Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Radio_Station
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
