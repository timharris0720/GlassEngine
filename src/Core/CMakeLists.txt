cmake_minimum_required(VERSION 3.30)
project(GlassEngineCore VERSION 1.0.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
include(FetchContent)
set(GLM_ENABLE_CXX_17 ON)
FetchContent_Declare(
  glm
  GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e
)
FetchContent_MakeAvailable(glm)
set(PROJECT_NAME "GlassEngineCore")
set(CORE_VERSION_MAJOR 1)
set(CORE_VERSION_MINOR 0)
set(CORE_VERSION_PATCH 0)
set(RELEASE_CHANNEL "a")
# Generate the Config.h file

if(WIN32)
set(SYSTEM_USING "win64")

elseif(UNIX)
set(SYSTEM_USING "unix_x64")
endif()

# FetchContent_Declare(
# vulkan-headers
# GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers.git
# GIT_TAG sdk-1.3.261.1  # Use the latest tag or specific version
# )

# Fetch Vulkan-Loader (for the Vulkan runtime library)
# FetchContent_Declare(
#   vulkan-loader
#   GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Loader.git
#   GIT_TAG sdk-1.3.261.1
# )
# FetchContent_MakeAvailable(vulkan-headers vulkan-loader)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
)


FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_Declare(
    assimp
    GIT_REPOSITORY https://github.com/assimp/assimp.git
    GIT_TAG v5.2.5  # Replace with latest version
)

FetchContent_MakeAvailable(argparse)
FetchContent_MakeAvailable(json)



set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Assimp as a static library" FORCE)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "Disable Assimp tools" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "Disable Assimp install" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Disable Assimp tests" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
set(ASSIMP_WARNINGS_AS_ERRORS OFF)
set(ASSIMP_INSTALL_PDB OFF)
set(ASSIMP_BUILD_ASSIMP_VIEW OFF)
#set(BUILD_SHARED_LIBS OFF)
set(ASSIMP_INJECT_DEBUG_POSTFIX OFF)
set(ASSIMP_USE_EXTERNAL_GLFW ON CACHE BOOL "" FORCE)

# Tell assimp not to fetch its own copy of glm
set(SYSTEM_GLMC_INCLUDE_DIR "${glm_SOURCE_DIR}" CACHE PATH "")
set(ASSIMP_INCLUDE_DIR_GLMC "${glm_SOURCE_DIR}" CACHE PATH "")


FetchContent_MakeAvailable(assimp)
set(CMAKE_DEBUG_POSTFIX "") 
set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")
set(OutputIncDirGE  "${OutputIncDir}/GlassEngine")
configure_file(src/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/core_version.h)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in")
    message(STATUS "Found version.h.in")
else()
    message(FATAL_ERROR "version.h.in not found at expected path!")
endif()


file(GLOB HEAD_FILES  src/*.h )
file(GLOB SRC_FILES  src/*.cpp)

add_library(GlassEngineCore SHARED ${SRC_FILES} ${HEAD_FILES})

FetchContent_Declare(
    CppUtils
    GIT_REPOSITORY https://github.com/timharris0720/Cpp_Utils.git
    GIT_TAG main
)
FetchContent_MakeAvailable(CppUtils)

target_compile_definitions(GlassEngineCore PUBLIC GLASS_ENGINE_EXPORTS_CORE)
target_compile_definitions(GlassEngineCore PUBLIC NOMINMAX)
target_include_directories(GlassEngineCore PUBLIC "${OutputIncDir}")
target_include_directories(GlassEngineCore PUBLIC ${glm_SOURCE_DIR})
target_link_libraries(GlassEngineCore PRIVATE nlohmann_json::nlohmann_json argparse assimp)
target_link_libraries(GlassEngineCore PRIVATE CppUtils)

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
file(GLOB GLM_INCLUDES_simd  ${glm_SOURCE_DIR}/glm/simd/*.h)


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



# set(GLFW_LOCATION_ASDASD "${glfw_BINARY_DIR}/src/${CMAKE_BUILD_TYPE}/glfw3.lib")

# file(GLOB VULKAN_INCLUDES  ${vulkan-headers_SOURCE_DIR}/include/vulkan/*.h)
# file(GLOB VULKAN_INCLUDES_hpp  ${vulkan-headers_SOURCE_DIR}/include/vulkan/*.hpp)
# file(GLOB VULKAN_INCLUDES_cppm  ${vulkan-headers_SOURCE_DIR}/include/vulkan/*.cppm)
# file(GLOB VULKAN_INCLUDES_video  ${vulkan-headers_SOURCE_DIR}/include/vk_video/*.h)


install(TARGETS  GlassEngineCore RUNTIME DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG},${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}> LIBRARY DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>  ARCHIVE DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG},${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}>)
#install(TARGETS GlassEngineCore)
install(FILES     ${HEAD_FILES}  DESTINATION  	${OutputIncDirGE}/)
install(FILES     "GlassEngine.h" DESTINATION  	${OutputIncDirGE}/)


# (TARGETS vulkan)
# install(FILES     ${VULKAN_INCLUDES}    DESTINATION  	${OutputIncDir}/vulkan/)
# install(FILES     ${VULKAN_INCLUDES_hpp}    DESTINATION  	${OutputIncDir}/vulkan/)
# install(FILES     ${VULKAN_INCLUDES_cppm}    DESTINATION  	${OutputIncDir}/vulkan/)
# install(FILES     ${VULKAN_INCLUDES_video}    DESTINATION  	${OutputIncDir}/vk_video/)
#install(FILES     ${GLFW_LOCATION_ASDASD}    DESTINATION  	$<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}>)

