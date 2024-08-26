cmake_minimum_required(VERSION 3.28)
project(pubb VERSION 1.0.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(priva REQUIRED)

# Add the library
add_library(pubb STATIC pubb.cpp)

# Specify include directories
target_include_directories(pubb PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(pubb PUBLIC priva)

# Installation rules
install(TARGETS pubb
        EXPORT pubbTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES pubb.h DESTINATION include)

install(EXPORT pubbTargets
        FILE pubbTargets.cmake
        DESTINATION lib/cmake/pubb)

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/pubbConfig.cmake"
        INSTALL_DESTINATION "lib/cmake/pubbConfig"
        NO_SET_AND_CHECK_MACRO
        NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/pubbConfigVersion.cmake"
        VERSION "${pubb_VERSION_MAJOR}.${pubb_VERSION_MINOR}"
        COMPATIBILITY AnyNewerVersion
)


install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/pubbConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/pubbConfigVersion.cmake
        DESTINATION lib/cmake/pubb
)