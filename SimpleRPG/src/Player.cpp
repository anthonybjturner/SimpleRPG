/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Player.h"

const static int FRONT_FACING = 0;
const static int RIGHT_FACING = 1;
const static int LEFT_FACING = 2;
const static int UP_FACING = 3;
const static int DOWN_FACING = 4;

Player::Player() {

	this->loadTexture(FRONT_FACING);
	images = new ImageLoader();

	sf::Image image;
	image.loadFromFile("images/player-front.png");
	sf::Image image2;
	image2.loadFromFile("images/player-right.png");
	sf::Image image3;
	image3.loadFromFile("images/player-left.png");
	sf::Image image4;
	image4.loadFromFile("images/player-up.png");
	sf::Image image5;
	image5.loadFromFile("images/player-down.png");

	images->addImage(image);
	images->addImage(image2);
	images->addImage(image3);
	images->addImage(image4);
	images->addImage(image5);
}

void Player::loadTexture(int index) {

	if (!texture.loadFromImage(images->getImage(0))) {
		// error...
	} else {

		//this->setTexture(texture);
	}
}

void Player::setLocation(double x, double y) {

	this->setPosition(x, y);

}

void Player::moveRight(float x) {

	this->loadTexture(RIGHT_FACING);
	this->move(x, 0);

}

void Player::moveLeft(float x) {

	this->loadTexture(LEFT_FACING);
	this->move(-x, 0);
}

void Player::moveUp(float y) {

	this->loadTexture(UP_FACING);
	this->move(0, -y);
}

void Player::moveDown(float y) {

	this->loadTexture(DOWN_FACING);
	this->move(0, y);
}

void Player::draw(sf::RenderWindow* window) {

	window->draw((*this));

}

Player::~Player() {

}

