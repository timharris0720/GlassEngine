# Install script for directory: D:/Docs/Code/Engines/GlassEngine/Test Project

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/testingProj.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/testingProj.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Docs/Code/Engines/GlassEngine/Test Project/testProj/MinSizeRel/testingProj.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/Docs/Code/Engines/GlassEngine/Test Project/testProj/RelWithDebInfo/testingProj.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Textures/Brick100" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Textures/Brick100" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_AmbientOcclusion.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Color.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Displacement.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalDX.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_NormalGL.jpg"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Textures/Brick100/Bricks100_1K-JPG_Roughness.jpg"
      )
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Shaders/2D/defaultShaderFrag.glsl;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Shaders/2D/defaultShaderVert.glsl")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Shaders/2D" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderFrag.glsl"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderVert.glsl"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D/defaultShaderFrag.glsl;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D/defaultShaderVert.glsl")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderFrag.glsl"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderVert.glsl"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D/defaultShaderFrag.glsl;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D/defaultShaderVert.glsl")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderFrag.glsl"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderVert.glsl"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D/defaultShaderFrag.glsl;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D/defaultShaderVert.glsl")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Shaders/2D" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderFrag.glsl"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Shaders/2D/defaultShaderVert.glsl"
      )
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Models/spot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Models/stanford-bunny.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Models/suzanne.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Models/teapot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Models/woody.obj")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Debug/bin/Assets/Models" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/spot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/stanford-bunny.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/suzanne.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/teapot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/woody.obj"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/spot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/stanford-bunny.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/suzanne.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/teapot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/woody.obj")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/spot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/stanford-bunny.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/suzanne.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/teapot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/woody.obj"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/spot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/stanford-bunny.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/suzanne.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/teapot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/woody.obj")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/spot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/stanford-bunny.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/suzanne.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/teapot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/woody.obj"
      )
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/spot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/stanford-bunny.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/suzanne.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/teapot.obj;D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models/woody.obj")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "D:/Docs/Code/Engines/GlassEngine/GlassEngine_Build/win64/Release/bin/Assets/Models" TYPE FILE FILES
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/spot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/stanford-bunny.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/suzanne.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/teapot.obj"
      "D:/Docs/Code/Engines/GlassEngine/Test Project/../TestAssets/Models/woody.obj"
      )
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "D:/Docs/Code/Engines/GlassEngine/Test Project/testProj/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
