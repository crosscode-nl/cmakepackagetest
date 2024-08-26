cmake_minimum_required(VERSION 3.28)
project(experiment)

set(CMAKE_CXX_STANDARD 17)

find_package(puba REQUIRED)
find_package(pubb REQUIRED)

add_executable(experiment main.cpp)

target_link_libraries(experiment puba pubb)

install(TARGETS experiment
        RUNTIME DESTINATION bin)
