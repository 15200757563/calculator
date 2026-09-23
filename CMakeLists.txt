cmake_minimum_required(VERSION 3.5)

project(calculator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCES
    main.cpp
    mainwindow.cpp
    formlib/standards/standards.cpp
    core/operation/arithmetic.cpp
)

set(HEADERS
    mainwindow.h
    formlib/standards/standards.h
    core/operation/arithmetic.h
)

set(UI_FILES
    mainwindow.ui
    formlib/standards/standards.ui
)

set(RESOURCES
    res.qrc
)

add_executable(calculator
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
)

target_include_directories(calculator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/core/operation
    ${CMAKE_CURRENT_SOURCE_DIR}/formlib/standards
)

source_group("UI" FILES ${UI_FILES})
source_group("Source" FILES ${SOURCES})
source_group("Header" FILES ${HEADERS})
target_link_libraries(calculator PRIVATE Qt5::Widgets)
