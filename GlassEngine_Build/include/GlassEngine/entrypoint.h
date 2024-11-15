#pragma once
#include "core.h"

extern Core::App::Application* CreateApplication();

int main(int argc, char** argv){
    auto app = CreateApplication();
    app->run();
    delete app;
}