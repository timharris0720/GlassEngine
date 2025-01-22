#pragma once
#include "core.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cameras{

    class Camera : GoCS::GameObject {
    public:
        Camera() = default;
        Camera(std::string name) : GoCS::GameObject(name){}
        virtual ~Camera() = default;

        // Pure virtual methods for projection matrix
        virtual void setProjection(float width, float height) = 0;
        virtual void updateProjectionMatrix() = 0;

        // Convenience methods for setting and getting position and rotation
        void setPosition(const glm::vec3& newPosition) { transform->Position = newPosition; }
        void setRotation(const glm::vec3& newRotation) { transform->Rotation = newRotation; }

        glm::vec3 getPosition() const { return transform->Position; }
        glm::vec3 getRotation() const { return transform->Rotation; }

        glm::mat4 getViewMatrix() const {
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

    };
    class PerspectiveCamera : public Camera {
    public:
        PerspectiveCamera(std::string name,float fov, float aspectRatio, float near, float far) : fov(fov), aspectRatio(aspectRatio), near(near), far(far), Camera(name) {
            updateProjectionMatrix();
        }

        void setProjection(float width, float height) override {
            aspectRatio = width / height;
            updateProjectionMatrix();
        }

        void updateProjectionMatrix() override {
            projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, near, far);
        }

        void setFOV(float newFov) {
            fov = newFov;
            updateProjectionMatrix();
        }

    private:
        float fov; // Field of View in degrees
        float aspectRatio;
        float near, far;
    };
    class OrthoCamera : public Camera {
    public:
        OrthoCamera(std::string name,float left, float right, float bottom, float top, float near, float far) : Camera(name),left(left), right(right), bottom(bottom), top(top), near(near), far(far) {
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
            projectionMatrix = glm::ortho(left, right, bottom, top, near, far);
        }

    private:
        float left, right, bottom, top, near, far;
    };
}