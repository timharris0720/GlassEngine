cmake --build build --config Debug -j 20
cmake --install build --config Debug
cmake --build buildPlugins --config Debug -j 20
cmake --install buildPlugins --config Debug