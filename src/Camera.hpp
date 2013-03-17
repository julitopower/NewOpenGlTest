#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GLES/gl.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

class Camera {
    private:
        // position coordinates
        GLfloat x, y, z;

        // Angle in the XY plane. 0 degress means looking in the Z direcction
        GLfloat alpha;

        // Velocity while moving
        GLfloat linearVelocity;

        // velocity for view angle change
        GLfloat angularVelocity;

    public:
        Camera(GLfloat x, GLfloat y, GLfloat z, GLfloat alpha);
        void moveForward();
        void moveBackward();
        void moveLeft();
        void moveRight();
        void turnLeft();
        void turnRight();
        void updateViewport();

};



#endif // CAMERA_HPP
