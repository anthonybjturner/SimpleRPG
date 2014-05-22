/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Player.h"
#include <iostream>
const static int FRONT_FACING = 0;
const static int UP_FACING = 1;
const static int DOWN_FACING = 2;
const static int LEFT_FACING = 3;
const static int RIGHT_FACING = 4;

using namespace std;

Player::Player() {

	p_player_image_manager = new ImageLoader();
	loadImages();
	this->loadTexture(FRONT_FACING);
}

void Player::loadImages() {

	sf::Image* p_image = new sf::Image();
	p_image->loadFromFile("images/player-front.png");
	p_player_image_manager->addImage(p_image);

	p_image = new sf::Image();
	p_image->loadFromFile("images/player-up.png");
	p_player_image_manager->addImage(p_image);

	p_image = new sf::Image();
	p_image->loadFromFile("images/player-down.png");
	p_player_image_manager->addImage(p_image);

	p_image = new sf::Image();
	p_image->loadFromFile("images/player-left.png");
	p_player_image_manager->addImage(p_image);

	p_image = new sf::Image();
	p_image->loadFromFile("images/player-right.png");
	p_player_image_manager->addImage(p_image);

}

void Player::loadTexture(int index) {

	if (!texture.loadFromImage(*p_player_image_manager->getImage(index))) {
		// error...
	} else {

		this->setTexture(texture);
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

	delete p_player_image_manager;
}

