#pragma once
#include <string>
#include <variant>
#include <vector>

#include <glm/glm.hpp>


using ShaderData = std::variant<bool,int, float, glm::vec2, glm::vec3, glm::vec4, glm::mat2,glm::mat3,glm::mat4>;

struct ShaderCommand{
    
    std::string commandName;
    ShaderData commandData;
};
class Shader {
    private:
    std::vector<ShaderCommand> ShaderCommands;
    public:

    unsigned int ShaderID;
    std::string VertShader;
    std::string FragShader;
    
    virtual void Compile(std::string fragmentShaderPath, std::string vertexShaderPath) {};
    template<typename T>
    void AddShaderCommand(T value, const std::string& variableName){
        ShaderCommand cmd;
        cmd.commandName = variableName;
        cmd.commandData = value;
        ShaderCommands.push_back(cmd);  
    }
    void RunShaderCommands(){
        if(ShaderCommands.size() > 0 )
            for(auto cmd : ShaderCommands){
                std::string name = cmd.commandName;
                ShaderData data = cmd.commandData;

                std::visit([&](auto&& value) {
                    using T = std::decay_t<decltype(value)>;
        
                    if constexpr (std::is_same_v<T, int>) {
                        setInt(name, value);
                    } else if constexpr (std::is_same_v<T, float>) {
                        setFloat(name, value);
                    }else if constexpr (std::is_same_v<T, bool>) {
                        setBool(name, value);
                    } else if constexpr (std::is_same_v<T, glm::vec2>) {
                        setVec2(name, value);
                    } else if constexpr (std::is_same_v<T, glm::vec3>) {
                        setVec3(name, value);
                    } else if constexpr (std::is_same_v<T, glm::vec4>) {
                        setVec4(name, value);
                    }else if constexpr (std::is_same_v<T, glm::mat2>) {
                        setMat2(name, value);
                    }else if constexpr (std::is_same_v<T, glm::mat3>) {
                        setMat3(name, value);
                    } else if constexpr (std::is_same_v<T, glm::mat4>) {
                        setMat4(name, value);
                    }
                }, cmd.commandData);
            }
    }
    virtual ~Shader() {};

    virtual void Bind() {};
    virtual void Unbind() {};
    virtual void setBool(const std::string& name, bool value) {};
    virtual void setInt(const std::string& name, int value) {};
    virtual void setFloat(const std::string& name, float value) {};
    virtual void setVec2(const std::string& name, const glm::vec2& value) {};
    virtual void setVec2(const std::string& name, float x, float y) {};
    virtual void setVec3(const std::string& name, const glm::vec3& value) {};
    virtual void setVec3(const std::string& name, float x, float y, float z) {};
    virtual void setVec4(const std::string& name, const glm::vec4& value) {};
    virtual void setVec4(const std::string& name, float x, float y, float z, float w) {};
    virtual void setMat2(const std::string& name, const glm::mat2& mat) {};
    virtual void setMat3(const std::string& name, const glm::mat3& mat) {};
    virtual void setMat4(const std::string& name, const glm::mat4& mat) {};
    Shader() = default;
};


