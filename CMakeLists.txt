cmake_minimum_required(VERSION 3.16)

project(FindNDISource VERSION 0.1.0 LANGUAGES C)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

find_package(NDI REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${NDI_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${NDI_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${NDI_LIBS})
