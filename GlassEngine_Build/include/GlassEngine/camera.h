#pragma once
#include "core.h"
namespace Cameras{
    class Camera {
        public:
        Camera() = default;
    };

    class PerspectiveCamera : public Camera {
        public:
        PerspectiveCamera() = default;
    };

    class OrthoCamera : public Camera {
        public:
        OrthoCamera() = default;

        private:
        Mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
    };
}