cmake_minimum_required(VERSION 3.13)
project(Amer_Delic)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
include_directories(include)

file(GLOB SOURCE_FILES
        "src/*.cpp"
        main.cpp)

set(TEST_FILES
        Tests/LinkedList_Tests.cpp Tests/DoublyLinkedList_Tests.cpp Tests/ArrayStack_Tests.cpp Tests/Stack_Tests.cpp)

add_executable(Amer_Delic ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(Amer_Delic gtest gtest_main)

#install(TARGETS Amer_Delic DESTINATION /usr/lib)