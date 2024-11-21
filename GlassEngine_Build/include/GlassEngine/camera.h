#pragma once
#include "core.h"
namespace Cameras{
    class Camera {
        public:
        GLASS_ENGINE_API Camera() = default;

        GLASS_ENGINE_API Vector3 GetPosition() const { return transform.position; }
		GLASS_ENGINE_API void SetPosition(const glm::vec3& position) { transform.position = position; RecalculateViewMatrix(); }
		GLASS_ENGINE_API Vector3 GetRotation() const {return transform.rotation;}
		GLASS_ENGINE_API void SetRotation(Vector3 Rotation) {transform.rotation = Rotation; RecalculateViewMatrix();}
		GLASS_ENGINE_API void SetRotation(float rotation) { transform.rotation.y = rotation; RecalculateViewMatrix(); }


        GLASS_ENGINE_API const Mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		GLASS_ENGINE_API const Mat4& GetViewMatrix() const { return m_ViewMatrix; }
		GLASS_ENGINE_API const Mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

        GLASS_ENGINE_API void RecalculateViewMatrix();

        Mat4 m_ProjectionMatrix;
		Mat4 m_ViewMatrix;
		Mat4 m_ViewProjectionMatrix;

        Core::Object::Transform transform;
        
    };

    class PerspectiveCamera : public Camera {
        public:
        PerspectiveCamera() = default;
    };

    class OrthoCamera : public Camera {
        public:
        GLASS_ENGINE_API OrthoCamera(float left, float right, float bottom, float top);
        GLASS_ENGINE_API void SetProjection(float left, float right, float bottom, float top);
    };
}