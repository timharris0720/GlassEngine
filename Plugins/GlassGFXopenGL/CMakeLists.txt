cmake_minimum_required(VERSION 3.30)
project(GlassGFX.openGL VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
include(FetchContent)
find_package(OpenGL REQUIRED)

set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")
set(OutputIncDirGE  "${OutputIncDir}/GlassEngine")



FetchContent_Declare(
  glm
  GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        latest
)
FetchContent_MakeAvailable(glfw)
set(GLFW_LIBRARY_TYPE SHARED)
set(GLFW_BUILD_DOCS  OFF)
set(GLFW_BUILD_TESTS  OFF)
set(GLFW_BUILD_EXAMPLES   OFF)
set(GLFW_BUILD_WIN32    OFF)
set(GLM_ENABLE_CXX_17 ON)

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
target_compile_definitions(GlassGFX.openGL PUBLIC OPENGL_PLUGIN)
target_include_directories(GlassGFX.openGL PUBLIC ${glfw_SOURCE_DIR}/include)
target_include_directories(GlassGFX.openGL PUBLIC ${glew_SOURCE_DIR}/include)
target_include_directories(GlassGFX.openGL PUBLIC "${OutputIncDir}")
target_include_directories(GlassGFX.openGL PUBLIC "${OutputIncDirGE}")
target_link_libraries(GlassGFX.openGL PUBLIC
glfw
libglew_static
OpenGL::GL
glm::glm
  
)


file(GLOB GLM_INCLUDES_glm  ${glm_SOURCE_DIR}/glm/*.hpp)
# DETAIL DIR
file(GLOB GLM_INCLUDES_detail  ${glm_SOURCE_DIR}/glm/detail/*.hpp)
file(GLOB GLM_INCLUDES_detail_inl  ${glm_SOURCE_DIR}/glm/detail/*.inl)
# EXT DIR
file(GLOB GLM_INCLUDES_ext  ${glm_SOURCE_DIR}/glm/ext/*.hpp)
file(GLOB GLM_INCLUDES_ext_inl  ${glm_SOURCE_DIR}/glm/ext/*.inl)
# GTC DIR
file(GLOB GLM_INCLUDES_gtc  ${glm_SOURCE_DIR}/glm/gtc/*.hpp)
file(GLOB GLM_INCLUDES_gtc_inl  ${glm_SOURCE_DIR}/glm/gtc/*.inl)
#GTX DIR
file(GLOB GLM_INCLUDES_gtx  ${glm_SOURCE_DIR}/glm/gtx/*.hpp)
file(GLOB GLM_INCLUDES_gtx_inl  ${glm_SOURCE_DIR}/glm/gtx/*.inl)
# SIMD DIR
file(GLOB GLM_INCLUDES_simd  ${glm_SOURCE_DIR}/glm/simd/*.h)


install(TARGETS  GlassGFX.openGL RUNTIME DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG},${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}> LIBRARY DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>  ARCHIVE DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG},${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}>)
install(TARGETS libglew_static DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>)
install(FILES     ${GLM_INCLUDES_glm}    DESTINATION  	${OutputIncDir}/glm)
install(FILES     ${GLM_INCLUDES_detail}    DESTINATION  	${OutputIncDir}/glm/detail)
install(FILES     ${GLM_INCLUDES_ext}    DESTINATION  	${OutputIncDir}/glm/ext)
install(FILES     ${GLM_INCLUDES_gtc}    DESTINATION  	${OutputIncDir}/glm/gtc)
install(FILES     ${GLM_INCLUDES_gtx}    DESTINATION  	${OutputIncDir}/glm/gtx)
install(FILES     ${GLM_INCLUDES_simd}    DESTINATION  	${OutputIncDir}/glm/simd)
install(FILES     ${GLM_INCLUDES_detail_inl}    DESTINATION  	${OutputIncDir}/glm/detail)
install(FILES     ${GLM_INCLUDES_ext_inl}    DESTINATION  	${OutputIncDir}/glm/ext)
install(FILES     ${GLM_INCLUDES_gtc_inl}    DESTINATION  	${OutputIncDir}/glm/gtc)
install(FILES     ${GLM_INCLUDES_gtx_inl}    DESTINATION  	${OutputIncDir}/glm/gtx)