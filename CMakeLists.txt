cmake_minimum_required(VERSION 3.9)

project(libA3Gtk VERSION 0.0.1)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS} include/)

add_library(A3Gtk SHARED src/splashwindow.cpp src/resources.c)

add_executable(teststyle test/teststyle/main.cpp test/teststyle/examplewindow.cpp)

execute_process(COMMAND glib-compile-resources --sourcedir ${CMAKE_CURRENT_SOURCE_DIR}/resources/fonts --sourcedir ${CMAKE_CURRENT_SOURCE_DIR}/resources/images --target=${CMAKE_CURRENT_SOURCE_DIR}/src/resources.c --generate-source ${CMAKE_CURRENT_SOURCE_DIR}/resources/images.gresource.xml)
add_executable(splashscreen test/splashscreen/main.cpp test/splashscreen/splashscreen.cpp)

target_link_libraries(teststyle ${GTKMM_LIBRARIES})
target_link_libraries(splashscreen ${GTKMM_LIBRARIES} A3Gtk)
