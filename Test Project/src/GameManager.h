#include "GlassEngine/GlassEngine.h"


class GameManager : public Core::Scripting::Script {
    public:
    virtual void Start() override {
        logger.InfoLog("Hello WOrlddd");
        logger.InfoLog("logger name %s", logger.getLoggerName().c_str());
        gameObject->CreateShader("Hello ", "Helslo");
    }
};



class GameManager_Componenet : public Core::Scripting::Component {
public:
    GameManager_Componenet() : Component("GameManager"){
        SetScript<GameManager>();
    }
};
