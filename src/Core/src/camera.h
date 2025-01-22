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

#include "GoCS.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cameras{

    class Camera {
    public:
        Camera() = default;
        virtual ~Camera() = default;

        // Pure virtual methods for projection matrix
        GLASS_ENGINE_API virtual void setProjection(float width, float height){};
        GLASS_ENGINE_API virtual void updateProjectionMatrix(){};

        // Convenience methods for setting and getting position and rotation
        GLASS_ENGINE_API void setPosition(const glm::vec3& newPosition) { transform.Position = newPosition; }
        GLASS_ENGINE_API void setRotation(const glm::vec3& newRotation) { transform.Rotation = newRotation; }

        GLASS_ENGINE_API glm::vec3 getPosition() const { return transform.Position; }
        GLASS_ENGINE_API glm::vec3 getRotation() const { return transform.Rotation; }

        GLASS_ENGINE_API glm::mat4 getViewMatrix() const {
            glm::vec3 position = getPosition();
            glm::vec3 rotation = getRotation();

            // Calculate forward, right, and up vectors from the rotation
            glm::vec3 forward = glm::normalize(glm::vec3(
                cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x)),
                sin(glm::radians(rotation.x)),
                sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x))
            ));
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
            glm::vec3 right = glm::normalize(glm::cross(up, forward));
            up = glm::normalize(glm::cross(forward, right));

            return glm::lookAt(position, position + forward, up);
        }

    protected:
        glm::mat4 projectionMatrix{1.0f};
        Components::Transform transform;
    };
    class PerspectiveCamera : public Camera {
    public:
        float fov; // Field of View in degrees
        float aspectRatio;
        float nearPlane;
        float farPlane;
        PerspectiveCamera() = default;
        PerspectiveCamera(float fov, float aspectRatio, float nearPlane, float farPlane) : fov(fov), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane) {
            updateProjectionMatrix();
        }

        void setProjection(float width, float height) override {
            aspectRatio = width / height;
            updateProjectionMatrix();
        }

        void updateProjectionMatrix() override {
            projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
        }

        void setFOV(float newFov) {
            fov = newFov;
            updateProjectionMatrix();
        }
        
    };
    class OrthoCamera : public Camera {
    public:
        OrthoCamera() = default;
        OrthoCamera(float left, float right, float bottom, float top, float nearPlane, float farPlane) : left(left), right(right), bottom(bottom), top(top), nearPlane(nearPlane), farPlane(farPlane) {
            updateProjectionMatrix();
        }

        void setProjection(float width, float height) override {
            left = -width / 2.0f;
            right = width / 2.0f;
            bottom = -height / 2.0f;
            top = height / 2.0f;
            updateProjectionMatrix();
        }

        void updateProjectionMatrix() override {
            projectionMatrix = glm::ortho(left, right, bottom, top, nearPlane, farPlane);
        }
        float left;
        float right;
        float bottom;   
        float top;
        float nearPlane;
        float farPlane;
    };
}