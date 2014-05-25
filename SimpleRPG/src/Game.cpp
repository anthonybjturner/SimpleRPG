/*
 * Game.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "../headers/Game.h"
#include <windows.h>
#include <iostream>
#include "../headers/Level.h"

#define GAME_SPEED (40.0)
#define GAME_WINDOW_WIDTH (1024)
#define GAME_WINDOW_HEIGHT (768)
#define GAME_WINDOW_TITLE ("Simple RPG")
#define LEVEL_ONE "../maps/level_one.txt"

using namespace std;

void Game::initWindow() {

	window = new RenderWindow(VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT),
	GAME_WINDOW_TITLE);
	camera = new Camera(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, 1.0);

}

Game::Game() {

	fps_count = 0;
	lastTime = 0;	//TODO optimize try making local field
	num_tiles_row = 250;
	num_tiles_col = 250;
	initWindow();
	createLoaders();
	createLevel("level_one.txt");
	mouseDown = false;
	loadImages();

}

void Game::createLoaders() {

	sf::Texture texture;
	if (texture.loadFromFile("images/enemy_sprite_sheet.png")) {

		entities_image_loader.addTexture(texture);

	}

	if (texture.loadFromFile("images/wall_01.png")) {

		tile_image_loader.addTexture(texture);
	} else
		cout << "wall not loaded" << endl;

	if (texture.loadFromFile("images/Grass11.png")) {
		tile_image_loader.addTexture(texture);
	} else
		cout << "grass not loaded" << endl;

	if (texture.loadFromFile("images/Grass15.png")) {
			tile_image_loader.addTexture(texture);
		} else
			cout << "grass 15 not loaded" << endl;

	if (texture.loadFromFile("images/clay.png")) {
			tile_image_loader.addTexture(texture);
	} else
		cout << "grass 15 not loaded" << endl;
}

void Game::loadImages() {

	const int NPC_ONE_TEXTURE = 0;

	sf::Texture& texture = entities_image_loader.getTexture(NPC_ONE_TEXTURE);

	entities_list.push_back(new Entity(texture));
	entities_list.push_back(new Entity(texture));
	entities_list.push_back(new Entity(texture));
	entities_list.push_back(new Entity(texture));
	entities_list.push_back(new Entity(texture));

}

void Game::createLevel(std::string file) {

	const int WALL_TILE = 0;
	const int GRASS_TILE = 1;
	const int GRASS_TILE_ALT = 2;
	const int CLAY_TILE = 3;
	//Temporary level for testing

	currentLevel = new Level(num_tiles_row, num_tiles_col);

	Tile* tile;
	int prob = 0;
	for (int y = 0; y < num_tiles_row; y++) {
		for (int x = 0; x < num_tiles_col; x++) {

			prob = (rand() % 10);
			if ( prob == 3) {
				//TODO change this to polymorphic sub class types
				tile = new Tile("wall",tile_image_loader.getTexture(WALL_TILE));
			} else if( prob == 5){
				tile = new Tile("grass15", tile_image_loader.getTexture(GRASS_TILE_ALT));
			}else{

				tile = new Tile("grass", tile_image_loader.getTexture(GRASS_TILE));
			}


			currentLevel->AddTile(x, y, tile);
		}
	}
}

void Game::start() {

	bool finished = false;

	int startTime = timeGetTime();
	int endTime = 0;
	int loopTime = 0;

	while (!finished) {

		startTime = timeGetTime();

		update(loopTime);
		//checkCollisions();
		render();
		finished = handleEvents();

		endTime = timeGetTime();
		loopTime = endTime - startTime;
		//sleep(1);

	}
//cout << fps_count / ((timeGetTime() - startTime) / 1000) << endl;

}

void Game::checkCollisions() {

	for (std::vector<Entity*>::iterator it = entities_list.begin();
			it != entities_list.end(); ++it) {

		Entity* t = *it;

		for (int y = 0; y < num_tiles_row; y++) {
			for (int x = 0; x < num_tiles_col; x++) {


				Tile* tile = currentLevel->GetTile(x,y);
				string tile_type = tile->getType();
				if( tile_type.compare("wall")){

					//Entity is on a wall, that is not allowed
					int entities_x = t->getPosition().x;
					int entities_y = t->getPosition().y;


					int left = t->getGlobalBounds().left;
					int top = t->getGlobalBounds().top;
					int width = t->getGlobalBounds().width;
					int height = t->getGlobalBounds().height;
					sf::Rect<float>rect(left, top, width, height);

					if( tile->collides(rect) ){

						//cout << "entities x is: "<<entities_x << "tiles x is: "<< x << endl;
						//cout << "entities y is: "<<entities_y << "tiles y is: "<< y << endl;

						//t->move(2, 2);

					}

				}
			}
		}

	}
}

void Game::update(int delta) {

	updateEntities(delta);
	camera->Update();

}

void Game::updateEntities(int delta) {

	for (std::vector<Entity*>::iterator it = entities_list.begin();
			it != entities_list.end(); ++it) {

		Entity* t = *it;
		t->moveEntity(delta, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	}

}

void Game::render() {

	if (window->isOpen()) {
		window->clear();

		drawLevel();
		player.draw(window);
		drawEntities();
		window->display();
		sleep(10);

	}

}

void Game::drawEntities() {

	for (std::vector<Entity*>::iterator it = entities_list.begin();
			it != entities_list.end(); ++it) {

		Entity* t = *it;
		t->draw(window);

	}

}

void Game::drawLevel() {

//Camera offsets
	int camOffsetX, camOffsetY;
	Tile* tile;

//Get the tile bounds we need to draw and Camera bounds
	sf::IntRect bounds = camera->GetTileBounds(30);

//Figure out how much to offset each tile
	camOffsetX = camera->GetTileOffset(30).x;
	camOffsetY = camera->GetTileOffset(30).y;

//Loop through and draw each tile
//We're keeping track of two variables in each loop. How many tiles
//we've drawn (x and y), and which tile on the map we're drawing (tileX
//and tileY)
	for (int y = 0, tileY = bounds.top; y < bounds.height; y++, tileY++) {
		for (int x = 0, tileX = bounds.left; x < bounds.width; x++, tileX++) {
			//Get the tile we're drawing
			tile = currentLevel->GetTile(tileX, tileY);
			if (tile)
				tile->draw((x * tile->TILE_WIDTH) - camOffsetX,
						(y * tile->TILE_HEIGHT) - camOffsetY, window);
		}
	}
}

bool Game::handleEvents() {

	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
			return true;
		}

		handleMousePresses(event);

		bool quit = handleKeyPresses(event);
		if (quit)
			return true;
	}

	return false;

}

bool Game::handleKeyPresses(sf::Event& event) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		// left key is pressed: move our character
		player.moveLeft(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		// left key is pressed: move our character
		player.moveRight(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		// left key is pressed: move our character
		player.moveUp(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		// left key is pressed: move our character
		player.moveDown(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

		int signal = MessageBoxA(NULL, "Are you sure you want to quit?",
				"Exit SimpleRPG?", MB_OKCANCEL | 0);
		if (signal == 1) {

			return true;
		}
	}

	return false;

}

void Game::handleMousePresses(sf::Event& event) {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (mouseDown == false) {
			// left key is pressed: move our character
			//player.moveLeft(5);
			sf::Vector2i click_position = sf::Mouse::getPosition();
			int mouse_x = click_position.x;
			int mouse_y = click_position.y;

			int x = camera->GetPosition().x + mouse_x;
			int y = camera->GetPosition().y + mouse_y;
			camera->GoToCenter(x, y);
			mouseDown = true;

		}

	}

	if (event.type == sf::Event::MouseButtonReleased)
		mouseDown = false;

}

bool Game::fpsUpdate() {

	double currentTime = timeGetTime() - lastTime;
	if (currentTime < GAME_SPEED) {
		return false;
	}

	fps_count++;
	lastTime = timeGetTime();
	return true;

}

void Game::sleep(int seconds) {

	Sleep(seconds);

}

Game::~Game() {

//Delete all tiles we created in createLevel();
	for (int y = 0; y < num_tiles_row; y++) {
		for (int x = 0; x < num_tiles_col; x++) {
			delete currentLevel->GetTile(x, y);
		}
	}

	delete window;
	delete currentLevel;

	for (std::vector<Entity*>::iterator it = entities_list.begin();
			it != entities_list.end(); ++it) {

		delete *it;
	}
}

