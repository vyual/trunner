cmake_minimum_required(VERSION 3.21)
project(trunner)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON) # add this line to generate moc files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(trunner
        ui/envedit.ui
        ui/mainwindow.ui
        src/main.cpp
        src/envedit.cpp
        src/envedit.h
        src/mainwindow.cpp
        src/mainwindow.h
        )

target_link_libraries(trunner PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
