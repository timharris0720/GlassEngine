cmake_minimum_required(VERSION 3.30)
project(GlassEngine VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)
if(WIN32)
set(SYSTEM_USING "win64")

elseif(UNIX)
set(SYSTEM_USING "unix_x64")
endif()

set(OutputBinDir  "${CMAKE_INSTALL_PREFIX}/${SYSTEM_USING}/bin/$<CONFIG>")
set(OutputLibDir  "${CMAKE_INSTALL_PREFIX}/${SYSTEM_USING}/lib/$<CONFIG>")
set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")

add_subdirectory(Core)

message(STATUS "OUT DIR: ${OutputBinDir}")