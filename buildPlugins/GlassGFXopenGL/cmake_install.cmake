# Install script for directory: D:/Docs/Code/Engines/Glass Engine 1/Plugins/GlassGFXopenGL

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
  include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glfw-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/plugins/GlassGFX.openGL.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/plugins" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib/GlassGFX.openGL.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/GlassGFX.openGL.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/GlassGFX.openGL.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/GlassGFX.openGL.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/MinSizeRel/GlassGFX.openGL.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/GlassGFX.openGL.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/RelWithDebInfo/GlassGFX.openGL.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/plugins/GlassGFX.openGL.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/plugins" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/bin/GlassGFX.openGL.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/GlassGFX.openGL.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/GlassGFX.openGL.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/GlassGFX.openGL.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/MinSizeRel/GlassGFX.openGL.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins/GlassGFX.openGL.dll")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/bin/plugins" TYPE SHARED_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/RelWithDebInfo/GlassGFX.openGL.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/CMakeFiles/GlassGFX.openGL.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/CMakeFiles/GlassGFX.openGL.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/CMakeFiles/GlassGFX.openGL.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/GlassGFXopenGL/CMakeFiles/GlassGFX.openGL.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib/glewd.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib" TYPE STATIC_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Debug/lib/glewd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/glew.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib" TYPE STATIC_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/glew.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/glew.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib" TYPE STATIC_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/lib/MinSizeRel/glew.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib/glew.lib")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/win64/Release/lib" TYPE STATIC_LIBRARY FILES "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/lib/RelWithDebInfo/glew.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/CMakeFiles/libglew_static.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/CMakeFiles/libglew_static.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/CMakeFiles/libglew_static.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glew-build/CMakeFiles/libglew_static.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/exponential.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/fwd.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/geometric.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/glm.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/integer.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat2x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat2x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat2x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat3x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat3x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat3x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat4x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat4x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/mat4x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/matrix.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/packing.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/trigonometric.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/vec2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/vec3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/vec4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/vector_relational.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/exponential.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/fwd.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/geometric.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/glm.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/integer.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat2x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat2x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat2x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat3x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat3x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat3x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat4x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat4x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/mat4x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/matrix.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/packing.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/trigonometric.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/vec2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/vec3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/vec4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/vector_relational.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/_features.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/_fixes.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/_noise.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/_swizzle.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/_swizzle_func.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/_vectorize.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/compute_common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/compute_vector_relational.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/qualifier.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/setup.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_float.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_half.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat2x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat2x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat2x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat3x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat3x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat3x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_quat.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec1.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec4.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/_features.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/_fixes.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/_noise.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/_swizzle.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/_swizzle_func.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/_vectorize.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/compute_common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/compute_vector_relational.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/qualifier.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/setup.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_float.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_half.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat2x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat2x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat2x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat3x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat3x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat3x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_quat.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec1.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec4.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_clip_space.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double2x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double2x2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double2x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double2x3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double2x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double2x4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double3x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double3x2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double3x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double3x3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double3x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double3x4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double4x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double4x2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double4x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double4x3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double4x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_double4x4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float2x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float2x2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float2x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float2x3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float2x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float2x4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float3x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float3x2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float3x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float3x3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float3x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float3x4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float4x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float4x2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float4x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float4x3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float4x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_float4x4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int2x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int2x2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int2x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int2x3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int2x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int2x4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int3x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int3x2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int3x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int3x3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int3x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int3x4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int4x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int4x2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int4x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int4x3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int4x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_int4x4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_projection.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_relational.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_transform.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint2x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint2x2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint2x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint2x3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint2x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint2x4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint3x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint3x2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint3x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint3x3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint3x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint3x4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint4x2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint4x2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint4x3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint4x3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint4x4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_uint4x4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_double.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_double_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_exponential.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_float.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_float_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_geometric.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_relational.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_transform.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_trigonometric.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_constants.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_int_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_integer.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_packing.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_relational.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_uint_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_ulp.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool1.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool1_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_bool4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double1.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double1_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_double4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float1.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float1_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float2_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float3_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_float4_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int1.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int1_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_int4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_integer.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_packing.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_relational.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint1.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint1_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint2_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint3.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint3_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint4.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_uint4_sized.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_ulp.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_clip_space.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double2x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double2x2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double2x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double2x3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double2x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double2x4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double3x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double3x2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double3x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double3x3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double3x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double3x4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double4x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double4x2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double4x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double4x3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double4x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_double4x4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float2x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float2x2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float2x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float2x3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float2x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float2x4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float3x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float3x2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float3x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float3x3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float3x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float3x4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float4x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float4x2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float4x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float4x3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float4x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_float4x4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int2x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int2x2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int2x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int2x3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int2x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int2x4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int3x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int3x2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int3x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int3x3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int3x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int3x4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int4x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int4x2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int4x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int4x3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int4x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_int4x4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_projection.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_relational.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_transform.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint2x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint2x2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint2x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint2x3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint2x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint2x4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint3x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint3x2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint3x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint3x3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint3x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint3x4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint4x2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint4x2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint4x3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint4x3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint4x4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_uint4x4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_double.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_double_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_exponential.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_float.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_float_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_geometric.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_relational.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_transform.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_trigonometric.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_constants.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_int_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_integer.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_packing.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_relational.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_uint_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_ulp.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool1.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool1_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_bool4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double1.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double1_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_double4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float1.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float1_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float2_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float3_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_float4_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int1.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int1_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_int4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_integer.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_packing.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_relational.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint1.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint1_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint2_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint3.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint3_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint4.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_uint4_sized.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_ulp.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/bitfield.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/color_space.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/constants.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/epsilon.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/integer.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_access.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_integer.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_inverse.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_transform.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/noise.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/packing.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/quaternion.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/random.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/reciprocal.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/round.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/type_aligned.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/type_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/type_ptr.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/ulp.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/vec1.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/bitfield.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/color_space.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/constants.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/epsilon.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/integer.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_access.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_integer.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_inverse.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_transform.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/noise.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/packing.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/quaternion.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/random.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/reciprocal.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/round.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/type_aligned.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/type_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/type_ptr.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/ulp.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/vec1.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/associated_min_max.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/bit.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/closest_point.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/color_encoding.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/color_space.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/color_space_YCoCg.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/common.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/compatibility.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/component_wise.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/dual_quaternion.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/easing.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/euler_angles.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/extend.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/extended_min_max.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/exterior_product.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/fast_exponential.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/fast_square_root.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/fast_trigonometry.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/functions.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/gradient_paint.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/handed_coordinate_space.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/hash.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/integer.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/intersect.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/io.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/log_base.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_cross_product.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_decompose.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_factorisation.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_interpolation.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_major_storage.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_operation.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_query.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_transform_2d.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/mixed_product.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/norm.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/normal.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/normalize_dot.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/number_precision.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/optimum_pow.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/orthonormalize.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/perpendicular.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/polar_coordinates.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/projection.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/quaternion.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/range.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/raw_data.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/rotate_normalized_axis.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/rotate_vector.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/scalar_multiplication.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/scalar_relational.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/spline.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/std_based_type.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/string_cast.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/texture.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/transform.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/transform2.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/type_aligned.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/type_trait.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/vec_swizzle.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/vector_angle.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/vector_query.hpp;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/wrap.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/associated_min_max.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/bit.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/closest_point.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/color_encoding.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/color_space.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/color_space_YCoCg.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/common.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/compatibility.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/component_wise.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/dual_quaternion.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/easing.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/euler_angles.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/extend.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/extended_min_max.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/exterior_product.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/fast_exponential.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/fast_square_root.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/fast_trigonometry.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/functions.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/gradient_paint.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/handed_coordinate_space.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/hash.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/integer.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/intersect.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/io.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/log_base.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_cross_product.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_decompose.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_factorisation.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_interpolation.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_major_storage.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_operation.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_query.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_transform_2d.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/mixed_product.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/norm.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/normal.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/normalize_dot.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/number_precision.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/optimum_pow.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/orthonormalize.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/perpendicular.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/polar_coordinates.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/projection.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/quaternion.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/range.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/raw_data.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/rotate_normalized_axis.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/rotate_vector.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/scalar_multiplication.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/scalar_relational.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/spline.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/std_based_type.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/string_cast.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/texture.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/transform.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/transform2.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/type_aligned.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/type_trait.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/vec_swizzle.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/vector_angle.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/vector_query.hpp"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/wrap.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/common.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/exponential.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/geometric.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/integer.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/matrix.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/neon.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/packing.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/platform.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/trigonometric.h;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd/vector_relational.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/simd" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/common.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/exponential.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/geometric.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/integer.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/matrix.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/neon.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/packing.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/platform.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/trigonometric.h"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/simd/vector_relational.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_common.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_common_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_exponential.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_exponential_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_geometric.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_geometric_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_integer.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_integer_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_matrix.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_matrix_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_packing.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_packing_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_trigonometric.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_trigonometric_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_vector_relational.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/func_vector_relational_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_half.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat2x2.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat2x3.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat2x4.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat3x2.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat3x3.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat3x4.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x2.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x3.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x4.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_mat4x4_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_quat.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_quat_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec1.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec2.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec3.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec4.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail/type_vec4_simd.inl")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/detail" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_common.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_common_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_exponential.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_exponential_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_geometric.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_geometric_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_integer.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_integer_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_matrix.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_matrix_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_packing.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_packing_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_trigonometric.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_trigonometric_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_vector_relational.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/func_vector_relational_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_half.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat2x2.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat2x3.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat2x4.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat3x2.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat3x3.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat3x4.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x2.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x3.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x4.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_mat4x4_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_quat.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_quat_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec1.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec2.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec3.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec4.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/detail/type_vec4_simd.inl"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_clip_space.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_common.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_projection.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_relational.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/matrix_transform.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_common.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_common_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_exponential.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_geometric.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_relational.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_transform.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/quaternion_trigonometric.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_common.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_constants.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_integer.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_packing.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_relational.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/scalar_ulp.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_common.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_integer.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_packing.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_relational.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext/vector_ulp.inl")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/ext" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_clip_space.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_common.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_projection.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_relational.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/matrix_transform.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_common.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_common_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_exponential.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_geometric.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_relational.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_transform.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/quaternion_trigonometric.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_common.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_constants.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_integer.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_packing.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_relational.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/scalar_ulp.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_common.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_integer.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_packing.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_relational.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/ext/vector_ulp.inl"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/bitfield.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/color_space.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/constants.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/epsilon.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/integer.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_access.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_inverse.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/matrix_transform.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/noise.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/packing.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/quaternion.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/quaternion_simd.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/random.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/reciprocal.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/round.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/type_precision.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/type_ptr.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc/ulp.inl")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtc" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/bitfield.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/color_space.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/constants.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/epsilon.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/integer.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_access.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_inverse.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/matrix_transform.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/noise.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/packing.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/quaternion.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/quaternion_simd.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/random.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/reciprocal.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/round.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/type_precision.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/type_ptr.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtc/ulp.inl"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/associated_min_max.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/bit.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/closest_point.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/color_encoding.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/color_space.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/color_space_YCoCg.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/common.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/compatibility.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/component_wise.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/dual_quaternion.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/easing.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/euler_angles.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/extend.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/extended_min_max.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/exterior_product.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/fast_exponential.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/fast_square_root.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/fast_trigonometry.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/float_notmalize.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/functions.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/gradient_paint.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/handed_coordinate_space.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/hash.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/integer.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/intersect.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/io.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/log_base.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_cross_product.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_decompose.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_factorisation.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_interpolation.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_major_storage.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_operation.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_query.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/matrix_transform_2d.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/mixed_product.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/norm.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/normal.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/normalize_dot.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/number_precision.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/optimum_pow.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/orthonormalize.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/perpendicular.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/polar_coordinates.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/projection.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/quaternion.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/raw_data.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/rotate_normalized_axis.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/rotate_vector.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/scalar_relational.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/spline.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/std_based_type.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/string_cast.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/texture.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/transform.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/transform2.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/type_aligned.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/type_trait.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/vector_angle.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/vector_query.inl;D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx/wrap.inl")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "D:/Docs/Code/Engines/Glass Engine 1/GlassEngine_Build/include/glm/gtx" TYPE FILE FILES
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/associated_min_max.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/bit.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/closest_point.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/color_encoding.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/color_space.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/color_space_YCoCg.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/common.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/compatibility.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/component_wise.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/dual_quaternion.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/easing.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/euler_angles.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/extend.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/extended_min_max.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/exterior_product.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/fast_exponential.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/fast_square_root.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/fast_trigonometry.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/float_notmalize.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/functions.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/gradient_paint.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/handed_coordinate_space.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/hash.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/integer.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/intersect.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/io.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/log_base.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_cross_product.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_decompose.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_factorisation.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_interpolation.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_major_storage.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_operation.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_query.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/matrix_transform_2d.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/mixed_product.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/norm.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/normal.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/normalize_dot.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/number_precision.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/optimum_pow.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/orthonormalize.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/perpendicular.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/polar_coordinates.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/projection.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/quaternion.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/raw_data.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/rotate_normalized_axis.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/rotate_vector.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/scalar_relational.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/spline.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/std_based_type.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/string_cast.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/texture.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/transform.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/transform2.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/type_aligned.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/type_trait.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/vector_angle.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/vector_query.inl"
    "D:/Docs/Code/Engines/Glass Engine 1/buildPlugins/_deps/glm-src/glm/gtx/wrap.inl"
    )
endif()

