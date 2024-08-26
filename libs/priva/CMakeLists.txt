cmake_minimum_required(VERSION 3.28)
project(priva VERSION 1.0.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library
add_library(priva STATIC priva.cpp)

# Specify include directories
target_include_directories(priva PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Installation rules
install(TARGETS priva
        EXPORT privaTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES priva.h DESTINATION include)

install(EXPORT privaTargets
        FILE privaConfig.cmake
        DESTINATION lib/cmake/priva)

