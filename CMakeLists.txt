cmake_minimum_required(VERSION 3.20)

project(CardGame)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

add_executable(CardGame ${SOURCES})

target_include_directories(CardGame PRIVATE include)