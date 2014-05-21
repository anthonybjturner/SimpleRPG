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
#include "Player.h"

using namespace sf;

class Game {
public:
	Game();
	virtual ~Game();
	void start();
	void update();
	void render();
	void sleep(int);
private:
	Player* player;
	RenderWindow* window;
	bool handleEvents();
	void drawBackground();
};

#endif /* GAME_H_ */
