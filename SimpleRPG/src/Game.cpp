/*
 * Game.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Game.h"
#include <windows.h>
#include <iostream>

using namespace std;
static const char* GAME_TITLE = "Simple RPG";

Game::Game() {

	window = new RenderWindow(VideoMode(1024, 768), GAME_TITLE);
	window->setActive(true);

	//loadImages();
}

Game::~Game() {

	delete window;
}

void Game::loadImages() {

	entities_list.push_back(new Entity());
	entities_list.push_back(new Entity());
	entities_list.push_back(new Entity());
	entities_list.push_back(new Entity());
	entities_list.push_back(new Entity());

	//for(std::vector<Entity>::iterator it = entities_list.begin(); it != entities_list.end(); ++it) {

	//}
}

void Game::start() {

	bool finished = false;

	while (!finished) {

		update();
		render();
		finished = handleEvents();
		sleep(15);

	}

}

void Game::update() {

	for(std::vector<Entity*>::iterator it = entities_list.begin(); it != entities_list.end(); ++it) {

			Entity* t = *it;
			t->moveEntity(window->getPosition());

		}

}

void Game::render() {

	if (window->isOpen()) {
		window->clear();

		drawBackground();

		player.draw(window);
		drawEntities();
		window->display();
	}

}

void Game::drawEntities() {

	for(std::vector<Entity*>::iterator it = entities_list.begin(); it != entities_list.end(); ++it) {

		Entity* t = *it;
		t->draw(window);

	}

}

bool Game::handleEvents() {

	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
			return true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			// left key is pressed: move our character
			player.moveLeft(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			// left key is pressed: move our character
			player.moveRight(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			// left key is pressed: move our character
			player.moveUp(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			// left key is pressed: move our character
			player.moveDown(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

			int signal = MessageBoxA(NULL, "Are you sure you want to quit?",
					"Exit SimpleRPG?", MB_OKCANCEL | 0);
			if (signal == 1) {

				return true;
			}
		}
	}

	return false;

}

void Game::sleep(int seconds) {

	Sleep(seconds);

}

void Game::drawBackground() {

	sf::RectangleShape bg(sf::Vector2f(1024, 768));
	bg.setFillColor(sf::Color(100, 250, 50));
	window->draw(bg);

}
