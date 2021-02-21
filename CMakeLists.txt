cmake_minimum_required(VERSION 2.8)

project(relive_editor)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/submodules/alive_reversing/Source/Tools/alive_api)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodules/alive_reversing)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/reliveeditorapplication.h
    src/reliveeditorapplication.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/levelfile.h
    src/levelfile.cpp
    src/selectpathdialog.h
    src/selectpathdialog.cpp
    src/aliveapierror.h
    src/aliveapierror.cpp
    src/resources/resources.c
)

target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
target_link_libraries(${PROJECT_NAME} alive_api)
