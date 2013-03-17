#include <iostream>
#include <TextureLoader.hpp>
#include "bcm_host.h"
#include <GLES/gl.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <math.h>
#include <curses.h>
#include "bcm_host.h"
#include <WindowProvider.hpp>
#include <Game.hpp>
#include "GameContextDemo.hpp"

#ifndef TEST
int main()
{
  	bcm_host_init();
 	initscr();
 	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	Game game;
	game.setWindowProvider(new EGLWindowProvider());
	game.setGameContext(new GameContextDemo());

	std::cout << "Finish setting up Game loop, starting ..." << std::endl;
	game.init();
	endwin();
	bcm_host_deinit();
}
#endif
