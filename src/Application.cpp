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
