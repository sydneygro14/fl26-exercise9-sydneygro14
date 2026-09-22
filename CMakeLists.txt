cmake_minimum_required(VERSION 3.5)
project(Exercise9 CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find Qt6 Widgets module automatically
find_package(Qt6Widgets REQUIRED)

# Add your executable and sources
add_executable(exercise9 main.cpp complex_widget.hpp complex_widget.cpp)

set(TARGET exercise9 PROPERTY CXX_STANDARD 17)

# Link Qt6 Widgets
target_link_libraries(exercise9 Qt6::Widgets)
