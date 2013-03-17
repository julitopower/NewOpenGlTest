#ifndef GAME_CONTEXT_DEMO_HPP
#define GAME_CONTEXT_DEMO_HPP
#include <GLES/gl.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <math.h>
#include <Game.hpp>
#include "Camera.hpp"

class GameContextDemo : public GameContext {
	private:
        // Coorintates and texture corrdinates for the
        // Simple plae
		GLfloat * texCoords;
		GLuint texture;
		GLfloat angle;

		// Need to define a Camera object here
		Camera * camera;
		signed short * mVertices;
	public:
		/*
		 * This method initializes OpengGL (state machine), and
		 * Should probably be the place to load textures, vertices
		 * and so on
		 */
		void init();

		/*
		 * This method is invocked once per game loop. This is where we should
		 * update the state of the world and repaint thinds. This methods
		 * do not need to attempt to swap the buffers
		 */
		void loop();

		~GameContextDemo();
};

#endif
