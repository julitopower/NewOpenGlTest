#ifndef GAME_HPP
#define GAME_HPP
#include "GameContext.hpp"
#include "WindowProvider.hpp"

class Game {
	private:
		WindowProvider * window;
		GameContext * context;
		bool running;		
	public:
		Game();
		Game(WindowProvider *  window, GameContext  * context);
		~Game();
		void setWindowProvider(WindowProvider * window);
		void setGameContext(GameContext * context);
		void init();
		void stop();
};

#endif
