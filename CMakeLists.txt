cmake_minimum_required(VERSION 3.20)
project(ActivityLog)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(ActivityLog main.cpp Activity.cpp Activity.h Log.cpp Log.h Time.cpp Time.h Date.cpp Date.h MainWindow.cpp MainWindow.h)
target_link_libraries(ActivityLog
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

