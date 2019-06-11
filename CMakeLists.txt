cmake_minimum_required(VERSION 3.10.2)

project(snake)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SRC_DIR ${PROJECT_DIR}/src)

set(COMPILER_FLAGS "-w")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)

set(LINKER_FLAGS "-lSDL2 -lSDL2_image -lSDL2_ttf")

set(PROJECT_SOURCES ${PROJECT_SRC_DIR}/Box.cpp
                    ${PROJECT_SRC_DIR}/Snake.cpp    
                    ${PROJECT_SRC_DIR}/Game.cpp
                    ${PROJECT_SRC_DIR}/main.cpp)
                    

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} ${LINKER_FLAGS})

add_definitions(${COMPILER_FLAGS})

