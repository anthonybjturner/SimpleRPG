/*
 * Entity.cpp
 *
 *  Created on: May 21, 2014
 *      Author: Anthony
 */

#include "../headers/Entity.h"

/*
 * Player.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "../headers/Player.h"
#include <iostream>
const static int FRONT_FACING = 0;
const static int UP_FACING = 1;
const static int DOWN_FACING = 2;
const static int LEFT_FACING = 3;
const static int RIGHT_FACING = 4;

using namespace std;

Entity::Entity() {

	if (loadImage()) {

		this->setTexture(texture, false);
		this->switchDirection(DOWN_FACING);
		dx = 3;
		dy = 3;

		int x = (std::rand() % 1024);
		int y = (std::rand() % 740);


		initMoveSteps();
		resetSteps();

		animation_frame = 0;
		move_right_animation_frame = 0;

		this->setPosition(x, y);
	}
}

void Entity::initMoveSteps() {

	move_probability = (std::rand() % 10);

	move_left_step_total = (std::rand() % 100) + 10;
	move_right_step_total = (std::rand() % 100) + 10;
	move_up_step_total = (std::rand() % 100) + 10;
	move_down_step_total = (std::rand() % 100) + 10;

}
bool Entity::loadImage() {

	if (!texture.loadFromFile("images/enemy_sprite_sheet.png")) {
		return false;
	}

	return true;
}

void Entity::switchDirection(int index) {

	sf::IntRect rect;
	rect.height = 31;
	rect.width = 28;

	switch (animation_frame) {

	case 0:
		rect.left = 5;//coordinate for the first animation image
		break;
	case 1:
		rect.left = 35;//coordinate for the second animation image
		break;
	case 2:
		rect.left = 65;//coordinate for the third animation image
		break;
	case 3:
		rect.left = 95;
		break;

	case 4:
		rect.left = 130;
		break;

	case 5:
		rect.left = 160;
		break;

	case 6:
		rect.left = 195;
		break;

	case 7:
		rect.left = 225;
		break;
	}

	switch (index) {

	case DOWN_FACING:

		rect.top = 0;
		// frame = move_down_count%4;
		//	rect.left = rect.width * frame;
		break;

	case LEFT_FACING:

		rect.top = 33;
		break;

	case RIGHT_FACING:

		rect.top = 65;
		break;
	case UP_FACING:

		rect.top = 97;
		break;

	}
	this->setTextureRect(rect);
}

void Entity::setLocation(double x, double y) {

	this->setPosition(x, y);

}

void Entity::moveEntity() {

	int move_chance = std::rand() % 8;
	if (move_chance >= move_probability) {


		//Reset animation frames
		if (animation_frame >= 4) {
			animation_frame = 0;
		}
		sf::Vector2f position = this->getPosition();
		//Do each move direction fully first, then move to the next possible move direction
		if (move_left_count > 0 && position.x > 0) {
			moveLeft(dx);
			move_left_count--;

		} else if (move_right_count > 0 && (position.x + 30) < 1024) {

			moveRight(dx);
			move_right_count--;

		} else if (move_up_count > 0 && (position.y + 50) > 0) {
			moveUp(dy);
			move_up_count--;

		} else if (move_down_count > 0 && position.y < 768) {
			moveDown(dy);
			move_down_count--;
		} else {

			//Once we made it here, they moved in all possible directions, with the max allowed steps for each.
			//Reset there steps so they can move again
			resetSteps();
		}
		animation_frame++;//After every move, we increment to the next frame (next animation)
	}

}

void Entity::resetSteps() {

	move_left_count = move_left_step_total;
	move_right_count = move_right_step_total;
	move_up_count = move_up_step_total;
	move_down_count = move_down_step_total;

}

void Entity::moveRight(float x) {

	this->switchDirection(RIGHT_FACING);
	this->move(x, 0);

}

void Entity::moveLeft(float x) {

	if (animation_frame >= 4) {
		//move_left_animation_frame = 0;
	}
	this->switchDirection(LEFT_FACING);
	this->move(-x, 0);
	//move_left_animation_frame++;
}

void Entity::moveUp(float y) {

	this->switchDirection(UP_FACING);
	this->move(0, -y);
}

void Entity::moveDown(float y) {

	this->switchDirection(DOWN_FACING);
	this->move(0, y);
}

void Entity::draw(sf::RenderWindow* window) {

	window->draw((*this));

}

Entity::~Entity() {

}

