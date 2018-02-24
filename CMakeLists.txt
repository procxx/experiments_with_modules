cmake_minimum_required(VERSION 3.9)

project(modules_test)

function(target_enable_modules TARGET)
    if(CMAKE_BUILD_TYPE MATCHES "^Debug$" OR NOT DEFINED CMAKE_BUILD_TYPE)
        set(_MODULES_PATH $ENV{IFCPATH}/Debug)
    else()
        set(_MODULES_PATH $ENV{IFCPATH}/Release)
    endif()
    find_library(_MODULES_LIB NAME std PATHS ${_MODULES_PATH} NO_DEFAULT_PATH)

    add_library(Modules::std UNKNOWN IMPORTED)
    if(EXISTS "${_MODULES_LIB}")
        set_target_properties(Modules::std PROPERTIES
                    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
                    IMPORTED_LOCATION "${_MODULES_LIB}")
    endif()

    target_compile_options(${TARGET} PRIVATE /experimental:module "/module:search ${_MODULES_PATH}")
endfunction()


set(MODULES actor.ixx manager.ixx)
set(SOURCES main.cpp manager.cpp)
list(APPEND SOURCES ${MODULES})

add_executable(${PROJECT_NAME} ${SOURCES})
set_source_files_properties(${MODULES} PROPERTIES LANGUAGE CXX)
target_enable_modules(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} Modules::std)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
