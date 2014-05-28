/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "../headers/Player.h"

Player::Player(Level*lev, sf::Texture& texture) : Sprite(lev, texture){

	setPosition(300,200);
	this->switchDirection();
	x = 300;
	y = 200;
}


bool Player::simulateAI(Sprite* sprite){

return true;
}
void Player::idleUpdate(sf::Vector2f cords){

	x = cords.x;
	y = cords.y;

}


void Player::setLocation(double x, double y) {

	this->setPosition(x, y);

}

void Player::moveRight(float x) {


	source.y = RIGHT;
	this->moveE(x, 0);

}

void Player::moveLeft(float x) {

	source.y = LEFT;
	this->moveE(-x, 0);
}

void Player::moveUp(float y) {

	source.y = UP;
	this->moveE(0, -y);
}

void Player::moveDown(float y) {

	source.y = DOWN;
	this->moveE(0, y);
}

void Player::moveTo(float x, float y) {


}

bool Player::moveE(float x, float y){

	if( source.x  >3){
		source.x = 0;
	}

	this->move(x, y);
	this->switchDirection();

	return true;
}

void Player::switchDirection() {

	int width = 34;
	int height = 54;

	int frame = source.x * width;
	int facing = source.y*height;
	sf::IntRect rect(frame,facing,width,height);

	this->setTextureRect(rect);
	source.x++;//After every move, we increment to the next frame (next animation)

}

void Player::draw(sf::RenderWindow* window, float x, float y) {

	window->draw((*this));

}

Player::~Player() {

	//delete p_player_image_manager;
}

