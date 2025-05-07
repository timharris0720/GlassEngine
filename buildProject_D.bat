@echo off
cmake --build build --config Debug -j %NUMBER_OF_PROCESSORS%
cmake --install build --config Debug
cmake --build buildPlugins --config Debug -j %NUMBER_OF_PROCESSORS%
cmake --install buildPlugins --config Debug
cmake --build  "Test_project/testProj" --config Debug -j %NUMBER_OF_PROCESSORS%
cmake --install  "Test_project/testProj" --config Debug

set /p DUMMY=Hit ENTER to continue