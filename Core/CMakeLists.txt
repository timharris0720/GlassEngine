cmake_minimum_required(VERSION 3.30)
project(GlassEngineCore VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
include(FetchContent)
set(GLM_ENABLE_CXX_17 ON)
FetchContent_Declare(
  glm
  GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e
)
FetchContent_MakeAvailable(glm)


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


set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")
set(OutputIncDirGE  "${OutputIncDir}/GlassEngine")


file(GLOB HEAD_FILES  src/*.h )
file(GLOB SRC_FILES  src/*.cpp)

add_library(GlassEngineCore SHARED ${SRC_FILES} ${HEAD_FILES})

target_compile_definitions(GlassEngineCore PUBLIC GLASS_ENGINE_EXPORTS_CORE)
target_include_directories(GlassEngineCore PUBLIC "${OutputIncDir}")



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

