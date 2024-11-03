#include <iostream>
#include <string>
#include <any>
class IApplication {
    public:
    virtual void createApplication(std::string name, int width,int height) {};

};

class IGraphicsBackend {
    public:
    
};

class ICallback {

};