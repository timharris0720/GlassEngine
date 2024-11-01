cmake -Bbuild -DCMAKE_INSTALL_PREFIX=GlassEngine_Build -Wno-dev
cd "Plugins"
cmake -B../buildPlugins -DCMAKE_INSTALL_PREFIX=../GlassEngine_Build -Wno-dev
cd "../Test Project"
cmake -BtestProj -DCMAKE_INSTALL_PREFIX=../GlassEngine_Build -Wno-dev
set /p DUMMY=Hit ENTER to continue...