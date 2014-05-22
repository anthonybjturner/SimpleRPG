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
#include "ImageLoader.h"
#include "Entity.h"

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
	ImageLoader* images;
	vector<Entity*> entities_list;

	bool handleEvents();
	void drawBackground();
	void loadImages();
	void drawEntities();
};

#endif /* GAME_H_ */
