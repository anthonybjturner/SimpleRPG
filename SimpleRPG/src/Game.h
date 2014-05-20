/*
 * Game.h
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace sf;

class Game {
public:
	Game();
	virtual ~Game();
	void start();
	void update();
	void render();
	void sleep(int);

	const char* GAME_TITLE = "Simple RPG";
	///sf::RenderWindow window;
	bool finished;

private:
	Player* player;
	VideoMode vm;
	RenderWindow* window;

	void handleEvents();
	void renderingThread(sf::RenderWindow*);

};

#endif /* GAME_H_ */
