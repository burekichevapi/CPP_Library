cmake_minimum_required(VERSION 3.13)
project(Amer_Delic)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB SOURCE_FILES
        "src/*.cpp")

add_library(Amer_Delic SHARED ${SOURCE_FILES} include/IQueue.h src/Queue.cpp)

install(TARGETS Amer_Delic DESTINATION /usr/lib)