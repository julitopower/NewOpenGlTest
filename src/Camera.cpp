#include "Camera.hpp"
#include <iostream>

Camera::Camera(GLfloat x, GLfloat y, GLfloat z, GLfloat alpha):
    x(x), y(y) , z(z), alpha(alpha), linearVelocity(1), angularVelocity(1)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustumf(-2,2,-1.5,1.5,1,1000);
}

void Camera::moveForward()
{
    z += linearVelocity;
}

void Camera::moveBackward()
{
    z -= linearVelocity;
}

void Camera::moveLeft()
{
    x -= linearVelocity;
}

void Camera::moveRight()
{
    x += linearVelocity;
}

void Camera::turnLeft()
{
    alpha -= angularVelocity;
}

void Camera::turnRight()
{
    alpha += angularVelocity;
}

void Camera::updateViewport()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-alpha, 0,1,0);
    glTranslatef(-x,-y,z);

}
