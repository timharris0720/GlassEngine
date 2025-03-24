@echo off
cmake --build build --config Release -j 24
cmake --install build --config Release
cmake --build buildPlugins --config Release -j 24
cmake --install buildPlugins --config Release
cmake --build "Test Project/testProj" --config Release -j 24
cmake --install "Test Project/testProj" --config Release
set /p DUMMY=Hit ENTER to continue...