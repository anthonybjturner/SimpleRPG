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
	window = new RenderWindow(VideoMode(1024,768),GAME_TITLE);
	window->setActive(false);
	//sf::Thread thread(&renderingThread, &window);
	 //   thread.launch();
}

Game::~Game() {

}

void Game::start(){

	while( !finished ){

		update();
		//render();
		handleEvents();
		sleep(1000);
	}

}

void Game::update(){

	std::cout << "Updating" << endl;
}


void Game::render(){

	    sf::CircleShape shape(100.f);
	    shape.setFillColor(sf::Color::Green);

	    if (window->isOpen())
	    {
	    	window->clear();
	    	window->draw(shape);


	       // window->display();
	    }

}

void Game::handleEvents(){

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

}

void renderingThread(sf::RenderWindow* window)
{
    // the rendering loop
	 sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window->isOpen())
	{
		window->clear();
		window->draw(shape);


	    window->display();
	}
}

void Game::sleep(int seconds){

	Sleep (seconds);

}


int main(){

	Game* game = new Game();

	game->start();
	return 0;
}

