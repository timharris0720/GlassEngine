#pragma once
#include "core.h"
namespace Cameras{

    class Camera : GoCS::GameObject{
        public:
        glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

        Camera() = default;
        Camera(std::string name) : GoCS::GameObject(name) {
            
        }
        GLASS_ENGINE_API Vector3 GetPosition() const { return transform->Position; }
		GLASS_ENGINE_API void SetPosition(const glm::vec3& position) { transform->Position = position; RecalculateViewMatrix(); }
		GLASS_ENGINE_API Vector3 GetRotation() const {return transform->Rotation;}
		GLASS_ENGINE_API void SetRotation(Vector3 Rotation) {transform->Rotation = Rotation; RecalculateViewMatrix();}
		GLASS_ENGINE_API void SetRotation(float rotation) { transform->Rotation.y = rotation; RecalculateViewMatrix(); }

        GLASS_ENGINE_API const Mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		GLASS_ENGINE_API const Mat4& GetViewMatrix() const { return m_ViewMatrix; }
		GLASS_ENGINE_API const Mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

        GLASS_ENGINE_API void RecalculateViewMatrix();

    };

    class PerspectiveCamera : public Camera {
        public:
        float FOV;
        float aspectRatio;
        PerspectiveCamera() = default;
        PerspectiveCamera(std::string name): Camera(name) {}
    };

    class OrthoCamera : public Camera {
        public:
        GLASS_ENGINE_API OrthoCamera(float left, float right, float bottom, float top);
        GLASS_ENGINE_API void SetProjection(float left, float right, float bottom, float top);
    };
}