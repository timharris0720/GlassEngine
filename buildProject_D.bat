cmake --build build --config Debug -j 20
cmake --install build --config Debug
cmake --build buildPlugins --config Debug -j 20
cmake --install buildPlugins --config Debug
cmake --build "Test Project/testProj" --config Debug -j 20
cmake --install "Test Project/testProj" --config Debug

set /p DUMMY=Hit ENTER to continue...