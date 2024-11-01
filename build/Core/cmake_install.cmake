# Install script for directory: D:/Docs/Code/Engines/Glass Engine 1/Core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-loader-build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib/GlassEngineCore.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib/GlassEngineCore.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/GlassEngineCore.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/GlassEngineCore.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/GlassEngineCore.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/build/Core/MinSizeRel/GlassEngineCore.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/GlassEngineCore.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/build/Core/RelWithDebInfo/GlassEngineCore.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/bin/GlassEngineCore.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/bin/GlassEngineCore.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/GlassEngineCore.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/GlassEngineCore.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/GlassEngineCore.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/build/Core/MinSizeRel/GlassEngineCore.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/GlassEngineCore.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/build/Core/RelWithDebInfo/GlassEngineCore.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/GlassEngine/core.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/GlassEngine/plugin.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/GlassEngine/pluginLoader.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/GlassEngine" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/Core/src/core.h"
    "D:/Docs/Code/Engines/Glass Engine 1/Core/src/plugin.h"
    "D:/Docs/Code/Engines/Glass Engine 1/Core/src/pluginLoader.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib/vulkan-1.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/vulkan-1.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-loader-build/loader/MinSizeRel/vulkan-1.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-loader-build/loader/RelWithDebInfo/vulkan-1.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/bin/vulkan-1.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/vulkan-1.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-loader-build/loader/MinSizeRel/vulkan-1.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-loader-build/loader/RelWithDebInfo/vulkan-1.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vk_icd.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vk_layer.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vk_platform.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_android.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_beta.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_core.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_directfb.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_fuchsia.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_ggp.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_ios.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_macos.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_metal.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_screen.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_vi.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_wayland.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_win32.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_xcb.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_xlib.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_xlib_xrandr.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vk_icd.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vk_layer.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vk_platform.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_android.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_beta.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_core.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_directfb.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_fuchsia.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_ggp.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_ios.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_macos.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_metal.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_screen.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_vi.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_wayland.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_win32.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_xcb.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_xlib.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_xlib_xrandr.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_enums.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_extension_inspection.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_format_traits.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_funcs.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_handles.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_hash.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_raii.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_static_assertions.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_structs.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_to_string.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan_video.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_enums.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_extension_inspection.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_format_traits.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_funcs.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_handles.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_hash.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_raii.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_static_assertions.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_structs.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_to_string.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan_video.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan/vulkan.cppm")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vulkan" TYPE FILE FILES "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vulkan/vulkan.cppm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codec_h264std.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codec_h264std_decode.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codec_h264std_encode.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codec_h265std.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codec_h265std_decode.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codec_h265std_encode.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video/vulkan_video_codecs_common.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/vk_video" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codec_h264std.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codec_h264std_decode.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codec_h264std_encode.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codec_h265std.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codec_h265std_decode.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codec_h265std_encode.h"
    "D:/Docs/Code/Engines/Glass Engine 1/build/_deps/vulkan-headers-src/include/vk_video/vulkan_video_codecs_common.h"
    )
endif()

