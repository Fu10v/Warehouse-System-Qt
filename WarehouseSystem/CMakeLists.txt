cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(WarehouseSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Charts)


find_package(mongocxx REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(WarehouseSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        loginwindow.h loginwindow.cpp loginwindow.ui
        itemwindow.h itemwindow.cpp itemwindow.ui

        connectiondialog.h connectiondialog.cpp connectiondialog.ui
        databasemanager.h databasemanager.cpp
        connectiondialog.h connectiondialog.cpp connectiondialog.ui
        statisticsdialog.h statisticsdialog.cpp statisticsdialog.ui
        aboutwindow.h aboutwindow.cpp aboutwindow.ui




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET WarehouseSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(WarehouseSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(WarehouseSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(WarehouseSystem PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Charts
    mongo::mongocxx_shared  # Основний драйвер
    mongo::bsoncxx_shared   # Допоміжна бібліотека (BSON)
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.WarehouseSystem)
endif()
set_target_properties(WarehouseSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(WIN32)
    add_custom_command(TARGET WarehouseSystem POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:mongo::mongocxx_shared>
        $<TARGET_FILE:mongo::bsoncxx_shared>
        $<TARGET_FILE:mongo::mongoc_shared>
        $<TARGET_FILE:mongo::bson_shared>
        $<TARGET_FILE_DIR:WarehouseSystem>
        COMMENT "Copying MongoDB DLLs to build directory..."
    )
endif()

include(GNUInstallDirs)
install(TARGETS WarehouseSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(WarehouseSystem)
endif()
