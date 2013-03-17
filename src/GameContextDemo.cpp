#include "GameContext.hpp"
#include <GLES/gl.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <math.h>
#include <curses.h>
#include "TextureLoader.hpp"
#include "GameContextDemo.hpp"
#include "Camera.hpp"
#include <iostream>

void GameContextDemo::init() {
    angle = 0;
    camera = new Camera(0,0,-200,0);
   	// reset model position
	TextureLoader loader;
	loader.loadFile("images/man.jpg");
	unsigned char * rawData = loader.getData();
    	glEnable(GL_TEXTURE_2D);
    	glEnable(GL_BLEND);
    	glBlendFunc(GL_ONE, GL_SRC_COLOR);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, rawData);

	texCoords = new GLfloat[8];
	texCoords[0] = 0.0;
	texCoords[1] = 1.0;
	texCoords[2] = 1.0;
	texCoords[3] = 1.0;
	texCoords[4] = 0.0;
	texCoords[5] = 0.0;
	texCoords[6] = 1.0;
	texCoords[7] = 0.0;

	mVertices = new signed short[12];
	mVertices[0] = -80;
	mVertices[1] = -80;
	mVertices[2] = 0;
    	mVertices[3] = 80;
	mVertices[4] = -80;
	mVertices[5] = 0;
	mVertices[6] = -80;
	mVertices[7] = 80;
	mVertices[8] = 0;
	mVertices[9] = 80;
	mVertices[10] = 80;
	mVertices[11] = 0;

    	glEnableClientState(GL_VERTEX_ARRAY);
    	glVertexPointer(3, GL_SHORT, 0, mVertices);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glPointSize(4);
}

void GameContextDemo::loop(){
	camera->updateViewport();
	int k = getch();
	if (k != ERR) {
        if (k == 105) {
            camera->moveForward();
        } else if (k == 107) {
            camera -> moveBackward();
        }
        if (k == 106) {
            camera->moveLeft();
        } else if (k == 108) {
            camera->moveRight();
        }
        if (k == 117) {
            camera->turnLeft();
        } else if (k == 111) {
            camera->turnRight();
        }
		if (k == 113) {
			this->game->stop();
		}
	}
	flushinp();
    glEnable(GL_MODELVIEW);
	glClearColor(0,0,0,0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_2D, texture);
	glRotatef(angle+=0.6,0,1,0);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);



}

GameContextDemo::~GameContextDemo() {
    delete camera;
}

