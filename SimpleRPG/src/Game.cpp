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

	player = new Player();
	VideoMode vm(1024,768);
	window = new RenderWindow(vm, GAME_TITLE);
	window->setActive(false);

}

Game::~Game() {

	delete player;
	delete window;
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


}

void Game::render() {

	if (window->isOpen()) {
		window->clear();

		drawBackground();

		player->draw(window);
		window->display();
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
			player->moveLeft(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			// left key is pressed: move our character
			player->moveRight(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			// left key is pressed: move our character
			player->moveUp(5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			// left key is pressed: move our character
			player->moveDown(5);
		}
	}

	return false;

}

void Game::sleep(int seconds) {

	Sleep(seconds);

}

void Game::drawBackground(){

	sf::RectangleShape bg(sf::Vector2f(1024, 768));
	bg.setFillColor(sf::Color(100, 250, 50));
	window->draw(bg);

}
