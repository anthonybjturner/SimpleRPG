/*
 * Game.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "../headers/Game.h"
#define LEVEL_ONE "../maps/level_one.txt"


using namespace std;

void Game::initWindow() {

	window = new sf::RenderWindow(
			sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT),
			GAME_WINDOW_TITLE);

	camera = new Camera(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, 1.0);

}

Game::Game() {

	srand(time(0));
	fps_count = 0;
	lastTime = 0;	//TODO optimize try making local field

	initWindow();
	createLoaders();

	createLevel("level_one.txt");
	player = new Player(currentLevel, player_image_manager.getTexture(0));
	mouseDown = false;

	createEnemies();
}

void Game::createLoaders() {

	sf::Texture texture;

	if (texture.loadFromFile("images/player_sprite_sheet.png"))
		player_image_manager.addTexture(texture);

	if (texture.loadFromFile("images/enemy_sprite_sheet.png")) {

		entities_image_loader.addTexture(texture);

	}

}

void Game::createEnemies() {

	int enemy_count = (rand()%GAME_WINDOW_WIDTH/100)+5;

	for (int i = 0; i < enemy_count; i++) {
		Enemy* enemy = new Enemy(currentLevel, entities_image_loader.getTexture(0));
		entities_list.push_back(enemy);

	}


	for (std::vector<Enemy*>::iterator enemy_it = entities_list.begin();
				enemy_it != entities_list.end(); ++enemy_it) {

	//	(*enemy_it)->addEnemies(entities_list);
	}
}

void Game::createLevel(std::string file) {

	int num_tiles_row = GAME_WINDOW_WIDTH / 32;
	int num_tiles_col = GAME_WINDOW_HEIGHT / 32;

	currentLevel = new Level(num_tiles_row, num_tiles_col);

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
		sleep(10);

	}
//cout << fps_count / ((timeGetTime() - startTime) / 1000) << endl;

}

void Game::checkCollisions() {

}

void Game::update(int delta) {

	updateEntities(delta);
	//camera->Update();

}

void Game::updateEntities(int delta) {

	sf::Vector2f cords = (sf::Vector2f) window->mapCoordsToPixel(
			player->getPosition());
	player->idleUpdate(cords);

	for (std::vector<Enemy*>::iterator it = entities_list.begin();
			it != entities_list.end(); ++it) {

		Enemy* current_enemy = *it;
		cords = (sf::Vector2f) window->mapCoordsToPixel(
				current_enemy->getPosition());
		current_enemy->idleUpdate(cords);//Update the enemies coordinates before doing the next few calls

		sf::Vector2f distance_away;
		current_enemy->simulateAI(player);
	}

}

void Game::render() {

	if (window->isOpen()) {
		window->clear();

		currentLevel->drawLevel(window);
		player->draw(window, 0, 0);
		drawEntities();
		window->display();

	}

}

void Game::drawEntities() {

	for (std::vector<Enemy*>::iterator it = entities_list.begin();
			it != entities_list.end(); ++it) {

		Enemy* t = *it;
		t->draw(window, 0, 0);
	}
}

void Game::drawLevel() {

//Camera offsets
	int camOffsetX, camOffsetY;
	//Tile* tilse;

//Get the tile bounds we need to draw and Camera bounds
	//sf::IntRect bounds = camera->GetTileBounds(30);
//
//Figure out how much to offset each tile
	//camOffsetX = camera->GetTileOffset(30).x;
	//camOffsetY = camera->GetTileOffset(30).y;

//Loop through and draw each tile
//We're keeping track of two variables in each loop. How many tiles
//we've drawn (x and y), and which tile on the map we're drawing (tileX
//and tileY)

	currentLevel->drawLevel(window);

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
		player->moveLeft(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		// left key is pressed: move our character
		player->moveRight(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		// left key is pressed: move our character
		player->moveUp(10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		// left key is pressed: move our character
		player->moveDown(10);
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


	for (std::vector<Enemy*>::iterator it = entities_list.begin();
		it != entities_list.end(); ++it) {

		delete *it;
	}
	delete window;
	delete player;
	//delete currentLevel;
}

