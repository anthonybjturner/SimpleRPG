/*
 * Game.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Player.h"
#include "Game.h"
#include <windows.h>
#include <iostream>

using namespace std;

Game::Game() {

	finished = false;
	vm.height = 768;
	vm.width = 1024;
	window = new RenderWindow(vm, GAME_TITLE);
	window->setActive(false);
	player = new Player();
	//sf::Thread thread(&renderingThread, &window);
	//   thread.launch();
}

Game::~Game() {

	delete player;
}

void Game::start() {

	while (!finished) {

		update();
		render();
		handleEvents();
		sleep(15);

	}

}

void Game::update() {

	std::cout << "Updating" << endl;
}

void Game::render() {

	if (window->isOpen()) {
		window->clear();
		sf::RectangleShape bg(sf::Vector2f(1024, 768));
		bg.setFillColor(sf::Color(100, 250, 50));

		window->draw(bg);
		window->draw(player->getImage());
		window->display();
	}

}

void Game::handleEvents() {

	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
			finished = true;
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

}

void Game::sleep(int seconds) {

	Sleep(seconds);

}

int main() {

	Game game;
	game.start();
	return 0;
}

