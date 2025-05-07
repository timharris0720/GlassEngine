@echo off
cmake --build build --config Release -j %NUMBER_OF_PROCESSORS%
cmake --install build --config Release
cmake --build buildPlugins --config Release -j %NUMBER_OF_PROCESSORS%
cmake --install buildPlugins --config Release
cmake --build "Test_project/testProj" --config Release -j %NUMBER_OF_PROCESSORS%
cmake --install "Test_project/testProj" --config Release
set /p DUMMY=Hit ENTER to continue...