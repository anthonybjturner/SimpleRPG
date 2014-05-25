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
enum DIRECTIONS {DOWN, LEFT, RIGHT, UP};

using namespace std;

Entity::Entity(sf::Texture& texture) {

	setTexture(texture);

		source.x = 0;
		source.y = DOWN;

		dx = (rand() % 250)+80;
		dy = (rand() % 250)+80;

		int x = (rand()% 1024 );
		int y = (rand() % 768);

		this->switchDirection();
		initMoveSteps();
		resetSteps();
		this->setPosition(x, y);

}

void Entity::initMoveSteps() {

	move_probability = (std::rand() % 10);

	move_left_step_total = (std::rand() % 100) + 10;
	move_right_step_total = (std::rand() % 100) + 10;
	move_up_step_total = (std::rand() % 100) + 10;
	move_down_step_total = (std::rand() % 100) + 10;

}

void Entity::switchDirection() {

	int width = 26;
	int height = 32;
	int frame = source.x * width;
	int facing = source.y*height;
	sf::IntRect rect(frame,facing,width,height);

	this->setTextureRect(rect);
//	source.x++;//After every move, we increment to the next frame (next animation)

}

void Entity::setLocation(double x, double y) {

	this->setPosition(x, y);

}

void Entity::moveEntity(int delta, int border_width, int border_height) {

	int move_chance = std::rand() % 8;
	if (move_chance >= move_probability) {

		//Reset animation frames
		if (source.x * 26 >= (int)texture.getSize().x) {
			source.x = 0;
		}
		sf::Vector2f position = this->getPosition();
		//Do each move direction fully first, then move to the next possible move direction
		if (move_left_count > 0 ) {

			//28 is the entities width change this later.
			if( (position.x +  28) > 0){
				moveLeft(delta);
				move_left_count--;
			}else
				moveRight(delta);

		} else if (move_right_count > 0 ) {

			if((position.x + 28) < 1024){
				moveRight(delta);
				move_right_count--;
			}else
				moveLeft(delta);


		} else if (move_up_count > 0 ) {

			if( (position.y + 31) > 0){
				moveUp(delta);
				move_up_count--;
			}else{
				moveDown(delta);
				move_down_count= move_up_count;
				move_up_count = 0;
			}

		} else if (move_down_count > 0 ) {

			if((position.y + 31)< 768){
				moveDown(delta);
				move_down_count--;
			}else{
				moveUp(delta);
				//Since they can't move down, reassign those moves to the move_up_count
				move_up_count = move_down_count;
				move_down_count = 0;
			}

		} else {

			//Once we made it here, they moved in all possible directions, with the max allowed steps for each.
			//Reset there steps so they can move again
			resetSteps();
		}
	}

}

void Entity::resetSteps() {

	move_left_count = move_left_step_total;
	move_right_count = move_right_step_total;
	move_up_count = move_up_step_total;
	move_down_count = move_down_step_total;

}

void Entity::moveRight(float x) {

	source.y = RIGHT;
	this->switchDirection();
	this->move(x*dx/1000, 0);

}

void Entity::moveLeft(float x) {
	source.y = LEFT;

	if (animation_frame >= 4) {
		//move_left_animation_frame = 0;
	}
	this->switchDirection();
	this->move(-(x*dx/1000), 0);
	//move_left_animation_frame++;
}

void Entity::moveUp(float y) {
	source.y = UP;

	this->switchDirection();
	this->move(0, -(y*dy/1000));
}

void Entity::moveDown(float y) {
	source.y = DOWN;

	this->switchDirection();
	this->move(0, y*dy/1000);
}

void Entity::draw(sf::RenderWindow* window) {

	window->draw((*this));

}

Entity::~Entity() {

}

