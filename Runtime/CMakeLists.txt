cmake_minimum_required(VERSION 3.30)
project(GlassEngineRuntime VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
include(FetchContent)
find_package(OpenGL REQUIRED)
if(WIN32)
set(SYSTEM_USING "win64")

elseif(UNIX)
set(SYSTEM_USING "unix_x64")
endif()
set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")


file(GLOB HEAD_FILES  src/*.h )
file(GLOB SRC_FILES  src/*.cpp)

add_library(GlassEngineRuntime SHARED ${SRC_FILES} ${HEAD_FILES})

target_include_directories(GlassEngineRuntime PUBLIC "${OutputIncDir}")




install(TARGETS GlassEngineRuntime)