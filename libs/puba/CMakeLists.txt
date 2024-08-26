cmake_minimum_required(VERSION 3.28)
project(puba VERSION 1.0.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library
add_library(puba STATIC puba.cpp)

# Specify include directories
target_include_directories(puba PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Installation rules
install(TARGETS puba
        EXPORT pubaTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES puba.h DESTINATION include)

install(EXPORT pubaTargets
        FILE pubaConfig.cmake
        DESTINATION lib/cmake/puba)

