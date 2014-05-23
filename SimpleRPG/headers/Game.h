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
	void update(int);
	void render();
	void sleep(int);
private:
	Player player;
	RenderWindow* window;
	vector<Entity*> entities_list;
	int fps_count;
	int lastTime;
	bool handleEvents();
	void drawBackground();
	void loadImages();
	void drawEntities();
	bool fpsUpdate();
	bool handleKeyPresses(sf::Event&);
	void handleMousePresses(sf::Event&);
};

#endif /* GAME_H_ */
