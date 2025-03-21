#pragma once
#ifdef _WIN32
#ifdef GLASS_ENGINE_EXPORTS_CORE
#define GLASS_ENGINE_API __declspec(dllexport)
#else
#define GLASS_ENGINE_API __declspec(dllimport)
#endif
#else
#define GLASS_ENGINE_API
#endif
#include <iostream>
#include <nlohmann/json.hpp>
#include "GoCS.h"
namespace SceneNS {
    class SceneLoader {
        private:
        std::vector<GoCS::GameObject> sceneGameObjects;
        public:
        SceneLoader() = default;
        GLASS_ENGINE_API SceneLoader(std::string scenepath);
        GLASS_ENGINE_API void ParseSceneFile();
        GLASS_ENGINE_API std::vector<GoCS::GameObject> GetGameObjects();

    };
}
