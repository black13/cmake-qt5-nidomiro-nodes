#cmake -S . -B .\build -G "Visual Studio 17 2022" -A Win32 -D CMAKE_PREFIX_PATH=c:\Qt\5.15.2\_32DLL\lib\cmake
cmake_minimum_required(VERSION 3.22)
project(nido VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS
        Core
        Widgets

        Svg
        Quick
        QuickControls2
        Charts
        Multimedia
        LinguistTools

        Xml
    REQUIRED QUIET
)

if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

set (SOURCES
abstract_node_port_view.cpp
color_utils.cpp
connection.cpp
main.cpp
mainwindow.cpp
math_util.cpp
node_connection_view.cpp
node_grid_scene.cpp
node_grid_view.cpp
node_port_address.cpp
node_port_connector_view.cpp
node_port_info.cpp
node_port_io_type.cpp
node_port_view_factory.cpp
node_view.cpp
qstring_node_port_view.cpp
stringtestnodeimpl.cpp
test_node_grid_impl.cpp
)

set ( MOC_HEADERS
abstract_node_port_view.h
color_utils.h
connection.h
i_connection_state_listener.h
i_node_grid_impl.h
i_node_grid_state_listener.h
i_node_impl.h
i_node_state_listener.h
mainwindow.h
math_util.h
node_connection_view.h
node_grid_scene.h
node_grid_view.h
node_port_address.h
node_port_connector_view.h
node_port_info.h
node_port_io_type.h
node_port_view_factory.h
node_view.h
qstring_node_port_view.h
qtnodesshared_global.h
qtnodes_global.h
stringtestnodeimpl.h
test_node_grid_impl.h
)

set ( UIS
mainwindow.ui
nodewidget.ui
)

set ( RESOURCES

)

QT5_WRAP_UI( UI_HEADERS ${UIS} )

add_executable( nido ${SOURCES} ${MOC_SRCS} ${RES_SOURCES} ${UI_HEADERS} )

target_include_directories(nido PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(nido
    PRIVATE
        Qt5::Widgets

        Qt5::Quick
        Qt5::QuickControls2
        Qt5::Svg
        Qt5::Xml
        Qt5::Gui
)
