cmake_minimum_required( VERSION 2.8 )
project( sml )
set( CMAKE_BUILD_TYPE Release )

# Project files
file( GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp" )
include_directories( "${PROJECT_SOURCE_DIR}/src" )

# Include library OpenGL.
find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIR} )
set( LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARIES} )

# Build shared library.
add_library( ${PROJECT_NAME} SHARED ${SOURCE_FILES} )

# Link libraries.
target_link_libraries( ${PROJECT_NAME} ${LIBRARIES} )
