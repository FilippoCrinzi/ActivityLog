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

add_subdirectory(test)
# Create a library target for your core project files
set(SOURCE_FILES main.cpp Activity.cpp Activity.h Log.cpp Log.h Time.cpp Time.h Date.cpp Date.h MainWindow.cpp MainWindow.h)
add_library(core ${SOURCE_FILES})

# Link the core library with Qt
target_link_libraries(core Qt::Core Qt::Gui Qt::Widgets)

# Create the main executable
add_executable(ActivityLog main.cpp)
target_link_libraries(ActivityLog core)


