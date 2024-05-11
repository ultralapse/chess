cmake_minimum_required(VERSION 3.10)
project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Werror -pedantic -g -O3)
endif()

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "lib/*.cpp")
file(GLOB_RECURSE HEADERS "*.hpp")
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

add_executable(${PROJECT_NAME} main.cpp Game.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})


add_executable(test ${TEST_SOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(test ${Boost_LIBRARIES})