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

add_library(CompilerFlags INTERFACE)
target_compile_features(CompilerFlags INTERFACE cxx_std_17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(CompilerFlags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<$<AND:$<CONFIG:Release>,$<BOOL:${gcc_like_cxx}>>:$<BUILD_INTERFACE:-DNDEBUG;>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:/Wall>>"
)



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


set(OutputBinDir  "${CMAKE_INSTALL_PREFIX}/${SYSTEM_USING}/bin/$<CONFIG>")
set(OutputLibDir  "${CMAKE_INSTALL_PREFIX}/${SYSTEM_USING}/lib/$<CONFIG>")
set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")



file(GLOB HEAD_FILES  src/*.h )
file(GLOB SRC_FILES  src/*.cpp)

add_library(GlassEngineCore SHARED ${SRC_FILES} ${HEAD_FILES})
target_link_libraries(GlassEngineCore PUBLIC
  glfw
  libglew_static
  OpenGL::GL
  glm::glm
  vulkan
)

target_include_directories(GlassEngineCore PUBLIC ${glfw_SOURCE_DIR}/include)
target_include_directories(GlassEngineCore PUBLIC ${glew_SOURCE_DIR}/include)
target_include_directories(GlassEngineCore PUBLIC ${vulkan-headers_SOURCE_DIR}/include)
target_include_directories(GlassEngineCore PUBLIC "${OutputIncDir}")

set(GLFW_LOCATION_ASDASD "${glfw_BINARY_DIR}/src/${CMAKE_BUILD_TYPE}/glfw3.lib")


install(TARGETS GlassEngineCore 
ARCHIVE DESTINATION ${OutputLibDir}
LIBRARY DESTINATION ${OutputLibDir}
RUNTIME DESTINATION ${OutputBinDir})
install(TARGETS libglew_static DESTINATION ${OutputLibDir})
install(TARGETS vulkan 
        ARCHIVE DESTINATION ${OutputLibDir}
        LIBRARY DESTINATION ${OutputLibDir} 
        RUNTIME DESTINATION ${OutputBinDir})