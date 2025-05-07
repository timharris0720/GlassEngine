cmake_minimum_required(VERSION 3.30)
project(GlassGFX.openGL VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
include(FetchContent)
find_package(OpenGL REQUIRED)

set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")
set(OutputIncDirGE  "${OutputIncDir}/GlassEngine")





FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        latest
)
set(GLFW_LIBRARY_TYPE STATIC)
set(GLFW_BUILD_DOCS  OFF)
set(GLFW_BUILD_TESTS  OFF)
set(GLFW_BUILD_EXAMPLES   OFF)
FetchContent_MakeAvailable(glfw)


set(ONLY_LIBS ON)
set(glew-cmake_BUILD_SHARED FALSE)
FetchContent_Declare(
  glew
  GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
  GIT_TAG        origin/master
  SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/glew-src"
  BINARY_DIR "${CMAKE_BINARY_DIR}/_deps/glew-build"
)
FetchContent_MakeAvailable(glew)




file(GLOB HEAD_FILES  src/*.h )
file(GLOB SRC_FILES  src/*.cpp)

add_library(GlassGFX.openGL SHARED ${SRC_FILES} ${HEAD_FILES})
target_compile_definitions(GlassGFX.openGL PUBLIC NOMINMAX)
target_compile_definitions(GlassGFX.openGL PUBLIC GLASS_PLUGIN_EXPORTS)
target_include_directories(GlassGFX.openGL PUBLIC ${glfw_SOURCE_DIR}/include)
target_include_directories(GlassGFX.openGL PUBLIC ${glew_SOURCE_DIR}/include)
target_include_directories(GlassGFX.openGL PUBLIC "${OutputIncDir}")
target_include_directories(GlassGFX.openGL PUBLIC "${OutputIncDirGE}")
target_link_libraries(GlassGFX.openGL PUBLIC
glfw
libglew_static
OpenGL::GL  
)
target_link_libraries(GlassGFX.openGL PRIVATE CppUtils)




install(TARGETS  GlassGFX.openGL RUNTIME DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG},${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}> LIBRARY DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>  ARCHIVE DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG},${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}>)
install(TARGETS libglew_static DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>)
