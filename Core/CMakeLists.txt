cmake_minimum_required(VERSION 3.30)
project(GlassEngineCore VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
include(FetchContent)
find_package(OpenGL REQUIRED)
if(WIN32)
set(SYSTEM_USING "win64")

elseif(UNIX)
set(SYSTEM_USING "unix_x64")
endif()

FetchContent_Declare(
  vulkan-headers
  GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers.git
  GIT_TAG sdk-1.3.261.1  # Use the latest tag or specific version
)

# Fetch Vulkan-Loader (for the Vulkan runtime library)
FetchContent_Declare(
  vulkan-loader
  GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Loader.git
  GIT_TAG sdk-1.3.261.1
)
FetchContent_MakeAvailable(vulkan-headers vulkan-loader)


set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")
set(OutputIncDirGE  "${OutputIncDir}/GlassEngine")


file(GLOB HEAD_FILES  src/*.h )
file(GLOB SRC_FILES  src/*.cpp)

add_library(GlassEngineCore SHARED ${SRC_FILES} ${HEAD_FILES})

target_compile_definitions(GlassEngineCore PUBLIC GLASS_ENGINE_EXPORTS_CORE)
target_include_directories(GlassEngineCore PUBLIC "${OutputIncDir}")

set(GLFW_LOCATION_ASDASD "${glfw_BINARY_DIR}/src/${CMAKE_BUILD_TYPE}/glfw3.lib")

file(GLOB VULKAN_INCLUDES  ${vulkan-headers_SOURCE_DIR}/include/vulkan/*.h)
file(GLOB VULKAN_INCLUDES_hpp  ${vulkan-headers_SOURCE_DIR}/include/vulkan/*.hpp)
file(GLOB VULKAN_INCLUDES_cppm  ${vulkan-headers_SOURCE_DIR}/include/vulkan/*.cppm)
file(GLOB VULKAN_INCLUDES_video  ${vulkan-headers_SOURCE_DIR}/include/vk_video/*.h)


#install(TARGETS GlassEngineCore RUNTIME DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG},${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}> LIBRARY DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}> ARCHIVE DESTINATION $<IF:$<CONFIG:Debug>,${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG},${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}>)
install(TARGETS GlassEngineCore)
install(FILES     ${HEAD_FILES}  DESTINATION  	${OutputIncDirGE}/)


install(TARGETS vulkan)
install(FILES     ${VULKAN_INCLUDES}    DESTINATION  	${OutputIncDir}/vulkan/)
install(FILES     ${VULKAN_INCLUDES_hpp}    DESTINATION  	${OutputIncDir}/vulkan/)
install(FILES     ${VULKAN_INCLUDES_cppm}    DESTINATION  	${OutputIncDir}/vulkan/)
install(FILES     ${VULKAN_INCLUDES_video}    DESTINATION  	${OutputIncDir}/vk_video/)
#install(FILES     ${GLFW_LOCATION_ASDASD}    DESTINATION  	$<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}>)

