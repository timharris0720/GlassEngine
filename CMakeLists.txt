cmake_minimum_required(VERSION 3.30)



project(GlassEngine VERSION 1.0)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)

set(INSTALL_PARALLEL ON)
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
set(OutputIncDir  "${CMAKE_INSTALL_PREFIX}/include")

add_subdirectory(src/Core)

install(CODE "file(REMOVE_RECURSE \"${CMAKE_INSTALL_PREFIX}/bin\")") 
install(CODE "file(REMOVE_RECURSE \"${CMAKE_INSTALL_PREFIX}/lib\")")
install(CODE "message(\"Deleting BIN and LIB folders as are not needed\")")