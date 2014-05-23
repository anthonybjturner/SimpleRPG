/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "../headers/Player.h"
#include <iostream>
const static int UP_FACING = 1;
const static int DOWN_FACING = 2;
const static int LEFT_FACING = 3;
const static int RIGHT_FACING = 4;

using namespace std;

Player::Player() {

	if( loadImage() ){

		this->setTexture(texture, false);
		this->switchDirection(DOWN_FACING);
	}

}

bool Player::loadImage() {

	if (!texture.loadFromFile("images/player_sprite_sheet.png")) {
			return false;
	}

	return true;

}

void Player::switchDirection(int index) {


		sf::IntRect rect;
		rect.height = 50;
		rect.width = 36;
		rect.left = 0;

		switch (index) {

		case DOWN_FACING:

			rect.top = 0;
			break;

		case LEFT_FACING:

			rect.top = 50 +5;
			break;

		case RIGHT_FACING:

			rect.top = 100 +9;
			break;

		case UP_FACING:

			rect.top = 150 +11;
			break;

		}
		this->setTextureRect(rect);
}

void Player::setLocation(double x, double y) {

	this->setPosition(x, y);

}

void Player::moveRight(float x) {

	this->switchDirection(RIGHT_FACING);
	this->move(x, 0);

}

void Player::moveLeft(float x) {

	this->switchDirection(LEFT_FACING);
	this->move(-x, 0);
}

void Player::moveUp(float y) {

	this->switchDirection(UP_FACING);
	this->move(0, -y);
}

void Player::moveDown(float y) {

	this->switchDirection(DOWN_FACING);
	this->move(0, y);
}

void Player::moveTo(float x, float y) {

	this->move(x, y);

}


void Player::draw(sf::RenderWindow* window) {

	window->draw((*this));

}

Player::~Player() {

	//delete p_player_image_manager;
}

