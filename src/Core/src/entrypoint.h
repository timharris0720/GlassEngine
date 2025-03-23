#pragma once
#include "core.h"

extern Core::App::Application* CreateApplication(int argc, char **argv);

int main(int argc, char** argv){
    auto app = CreateApplication(argc, argv);
    app->run();
    delete app;
}