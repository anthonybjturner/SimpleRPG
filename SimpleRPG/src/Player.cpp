/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Player.h"

Player::Player() {

	sf::Texture texture;
	if (!texture.loadFromFile("player.jpg"))
	{
	    // error...
	}else{

		//Sprite->
		//Sprite->se
		Sprite.setTexture(texture);
		//Sprite->setColor(sf::Color(0, 255, 255, 255));
		//Sprite->setPosition(000.f, 000.f);
		//Sprite->setRotation(30.f);
		///Sprite->setScale(2.f, 0.5f);
		//Sprite->setScale(sf::Vector2f(0.5f, 1.f)); // absolute scale factor
		//Sprite->scale(sf::Vector2f(1.5f, 1.f)); // factor relative to the current scale
	}
}


void Player::setLocation(double x, double y){

	Sprite.setPosition(x,y);

}

void Player::moveRight(float x){

	Sprite.move(x, 0);
}

void Player::moveLeft(float x){

	Sprite.move(-x, 0);
}

void Player::moveUp(float y){

	Sprite.move(0, -y);
}

void Player::moveDown(float y){

	Sprite.move(0, y);
}


sf::Sprite& Player::getImage(){

	return Sprite;

}


Player::~Player() {

}

