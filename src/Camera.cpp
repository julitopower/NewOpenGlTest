/*
 * Simple Raspberry Pi OpenGl-ES window tests application 
 * Copyright (C) 2013-2014, Julio Delgado <julio.delgadomangas@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
