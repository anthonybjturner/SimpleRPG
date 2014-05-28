/*
 * Game.h
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#ifndef GAME_H_
#define GAME_H_
#include <windows.h>
#include <SFML/Window/Mouse.hpp>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Camera.h"
#include "ImageLoader.h"
#define GAME_SPEED (40.0)
#define GAME_WINDOW_TITLE ("Simple RPG")

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

	Player* player;
	sf::RenderWindow* window;
	Level* currentLevel;
	//TileMap tmap;

	bool mouseDown;
	int fps_count;
	int lastTime;


	sf::Texture texture;
	sf::Texture w_texture;

	sf::Sprite sprite;
	Camera* camera;

	ImageLoader entities_image_loader;
	ImageLoader player_image_manager;


	std::vector<Enemy*> entities_list;

	bool handleEvents();
	bool fpsUpdate();
	bool handleKeyPresses(sf::Event&);

	void checkCollisions();
	void createEnemies();
	void drawLevel();
	void loadImages();
	void drawEntities();
	void handleMousePresses(sf::Event&);
	void createLevel(std::string);
	void initWindow();
	void createLoaders();

};

#endif /* GAME_H_ */
