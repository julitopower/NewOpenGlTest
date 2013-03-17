#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

class Game;

class GameContext {
	protected:
		Game * game;
	public:
		virtual void init() = 0;
		virtual void loop() = 0;
		void setGame(Game * game) {this->game = game;}
};
	
#endif
