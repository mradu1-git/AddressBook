cmake_minimum_required(VERSION 4.2)
project(addressbook)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(addressbook main.cpp
        mainwindow.cpp
        mainwindow.h
        addresswidget.cpp
        addresswidget.h
        adddialog.cpp
        adddialog.h
        newaddresstab.cpp
        newaddresstab.h)
target_link_libraries(addressbook
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

