@echo off
cmake -Bbuild -DCMAKE_INSTALL_PREFIX=GlassEngine_Build -Wno-dev
cd src/Plugins
cmake -B../../buildPlugins -DCMAKE_INSTALL_PREFIX=../../GlassEngine_Build -Wno-dev
cd "../../Test_project"
cmake -BtestProj -DCMAKE_INSTALL_PREFIX=../GlassEngine_Build -Wno-dev
set /p DUMMY=Hit ENTER to continue...