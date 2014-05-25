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
#include "Level.h"
#include "TileMap.h"
#include "Camera.h"

using namespace sf;

class Game {
public:
	Game();
	virtual ~Game();
	void start();
	void update(int);
	void render();
	void sleep(int);
	void updateEntities(int);

private:
	Player player;
	RenderWindow* window;
	vector<Entity*> entities_list;
	Level* currentLevel;
	TileMap tmap;

	bool mouseDown;
	int fps_count;
	int lastTime;
	int num_tiles_row;
	int num_tiles_col;

	sf::Texture texture;
	sf::Sprite sprite;
	Camera* camera;
	ImageLoader tile_image_loader;
	ImageLoader entities_image_loader;


	bool handleEvents();
	bool fpsUpdate();
	bool handleKeyPresses(sf::Event&);

	void checkCollisions();

	void drawLevel();
	void loadImages();
	void drawEntities();
	void handleMousePresses(sf::Event&);
	void createLevel(std::string);
	void initWindow();
	void createLoaders();

};

#endif /* GAME_H_ */
