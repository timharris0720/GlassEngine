cmake_minimum_required(VERSION 3.30)
project(testingProj VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)

add_library(CompilerFlags INTERFACE)
target_compile_features(CompilerFlags INTERFACE cxx_std_17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/")
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(CompilerFlags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<$<AND:$<CONFIG:Release>,$<BOOL:${gcc_like_cxx}>>:$<BUILD_INTERFACE:-DNDEBUG;>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:/Wall>>"
)




set(INCLUDE_DIRR "../GlassEngine_Build/include")
if(WIN32)
set(SYSTEM_USING "win64")
elseif(UNIX)
set(SYSTEM_USING "unix_x64")
endif()
set(OUTPUT_BASE_DIR "${CMAKE_INSTALL_PREFIX}/${SYSTEM_USING}")

# Set output directories for binaries and libraries per configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_BASE_DIR}/Debug/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_BASE_DIR}/Release/bin")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_BASE_DIR}/Debug/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_BASE_DIR}/Release/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_BASE_DIR}/Debug/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_BASE_DIR}/Release/lib")

set(GLEW_LIBRARY_USING $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}/glewd.lib,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>/glew.lib)
set(USING_RUNTIME $<IF:$<CONFIG:Debug>,${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG},${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}>)
set(USING_LIB $<IF:$<CONFIG:Debug>,${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG},${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}>)
include_directories(${INCLUDE_DIRR})
link_directories(${USING_RUNTIME})
link_directories(${USING_LIB})




add_executable(testingProj src/main.cpp src/CameraController.cpp src/GameManager.cpp)
target_compile_definitions(testingProj PUBLIC NOMINMAX)


target_link_libraries(testingProj GlassEngineCore)
file(GLOB TEST_ASSETS ../TestAssets/*.*)
file(GLOB TEST_ASSETS_TEXTURES_BRICK_100 ../TestAssets/Textures/Brick100/*)
file(GLOB_RECURSE TEST_ASSETS_TEXTURES_PROTOTYPE_RED    "../TestAssets/Textures/Prototype/Red/*")
file(GLOB_RECURSE TEST_ASSETS_TEXTURES_PROTOTYPE_DARK   "../TestAssets/Textures/Prototype/Dark/*")
file(GLOB_RECURSE TEST_ASSETS_TEXTURES_PROTOTYPE_GREEN  "../TestAssets/Textures/Prototype/Green/*")
file(GLOB_RECURSE TEST_ASSETS_TEXTURES_PROTOTYPE_LIGHT  "../TestAssets/Textures/Prototype/Light/*")
file(GLOB_RECURSE TEST_ASSETS_TEXTURES_PROTOTYPE_ORANGE "../TestAssets/Textures/Prototype/Orange/*")
file(GLOB_RECURSE TEST_ASSETS_TEXTURES_PROTOTYPE_PURPLE "../TestAssets/Textures/Prototype/Purple/*")
file(GLOB TEST_ASSETS_2D_SHADERS ../TestAssets/Shaders/2D/*)
file(GLOB TEST_ASSETS_3D_SHADERS ../TestAssets/Shaders/3D/*)
file(GLOB TEST_ASSETS_SHADERS ../TestAssets/Shaders/*.glsl)
file(GLOB TEST_ASSETS_MODELS ../TestAssets/Models/*)
install(TARGETS testingProj)
install(FILES     ${TEST_ASSETS}                       DESTINATION  	${USING_RUNTIME}/Assets)
install(FILES     ${TEST_ASSETS_TEXTURES_BRICK_100}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Brick100)

install(FILES     ${TEST_ASSETS_TEXTURES_PROTOTYPE_RED}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Prototype/Red/)
install(FILES     ${TEST_ASSETS_TEXTURES_PROTOTYPE_DARK}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Prototype/Dark/)
install(FILES     ${TEST_ASSETS_TEXTURES_PROTOTYPE_GREEN}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Prototype/Green/)
install(FILES     ${TEST_ASSETS_TEXTURES_PROTOTYPE_LIGHT}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Prototype/Light/)
install(FILES     ${TEST_ASSETS_TEXTURES_PROTOTYPE_ORANGE}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Prototype/Orange)
install(FILES     ${TEST_ASSETS_TEXTURES_PROTOTYPE_PURPLE}    DESTINATION  	${USING_RUNTIME}/Assets/Textures/Prototype/Purple)


install(FILES     ${TEST_ASSETS_2D_SHADERS}            DESTINATION  	${USING_RUNTIME}/Assets/Shaders/2D)
install(FILES     ${TEST_ASSETS_3D_SHADERS}            DESTINATION  	${USING_RUNTIME}/Assets/Shaders/3D)
install(FILES     ${TEST_ASSETS_SHADERS}            DESTINATION  	${USING_RUNTIME}/Assets/Shaders/)
install(FILES     ${TEST_ASSETS_MODELS}            DESTINATION  	${USING_RUNTIME}/Assets/Models)
