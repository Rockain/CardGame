cmake_minimum_required(VERSION 3.20)

project(CardGame)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

list(REMOVE_ITEM SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

add_executable(CardGame
    src/main.cpp
    ${SOURCES}
)

add_executable(CardGameTests
    tests/main.cpp
    ${SOURCES}
)

target_include_directories(CardGame PRIVATE include)
target_include_directories(CardGameTests PRIVATE include)