/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Player.h"

Player::Player() {


	sprite = new sf::Sprite();
	this->loadTexture("images/player-front.png");


}

void Player::loadTexture(const std::basic_string<char> file){

	if (!texture.loadFromFile(file))
		{
		    // error...
		}else{

			sprite->setTexture(texture);
		}
}


void Player::setLocation(double x, double y){

	sprite->setPosition(x,y);

}

void Player::moveRight(float x){

	this->loadTexture("images/player-right.png");
	sprite->move(x, 0);
}

void Player::moveLeft(float x){

	this->loadTexture("images/player-left.png");
	sprite->move(-x, 0);
}

void Player::moveUp(float y){

	this->loadTexture("images/player-up.png");
	sprite->move(0, -y);
}

void Player::moveDown(float y){

	this->loadTexture("images/player-down.png");
	sprite->move(0, y);
}


sf::Sprite& Player::getImage(){

	return *sprite;

}

void Player::draw(sf::RenderWindow* window){

	window->draw((*sprite));

}


Player::~Player() {

}

