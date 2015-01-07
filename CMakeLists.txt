cmake_minimum_required( VERSION 2.8 )
set( CMAKE_BUILD_TYPE Release )

# Project info
project( sml )
set( PROJECT_VERSION_MAJOR 1)
set( PROJECT_VERSION_MINOR 0)
set( PROJECT_VERSION_PATCH 0)
set( PROJECT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

# Project files
file( GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp" )
include_directories( "${PROJECT_SOURCE_DIR}/src" )

# Compiler flags
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

# Include library OpenGL.
find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIR} )
set( LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARIES} )

# Configure header file
configure_file(
    "${PROJECT_SOURCE_DIR}/src/shader_loader.hpp.in"
    "${PROJECT_BINARY_DIR}/src/shader_loader.hpp" )

# Build shared library.
set( LIBRARY_NAME ${PROJECT_NAME} )
add_library( ${LIBRARY_NAME} SHARED ${SOURCE_FILES} )
set_target_properties(
    ${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION_STRING}
    SOVERSION ${PROJECT_VERSION_MAJOR} )

# Link libraries.
target_link_libraries( ${LIBRARY_NAME} ${LIBRARIES} )

# Instalation.
install( DIRECTORY src/ DESTINATION include/msl FILES_MATCHING PATTERN "*.hpp" )
install( TARGETS ${LIBRARY_NAME} DESTINATION lib )
