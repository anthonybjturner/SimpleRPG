/*
 * Entity.cpp
 *
 *  Created on: May 21, 2014
 *      Author: Anthony
 */

#include "Entity.h"


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



Entity::Entity() {

	p_entity_image_manager = new ImageLoader();
	loadImages();
	this->loadTexture(FRONT_FACING);
	dx = (std::rand() % 6)+1;
	dy = (std::rand() % 6)+1;


}


void Entity::loadImages(){

	sf::Image* p_image = new sf::Image();
		p_image->loadFromFile("images/player-front.png");
		p_entity_image_manager->addImage(p_image);

		p_image = new sf::Image();
		p_image->loadFromFile("images/player-up.png");
		p_entity_image_manager->addImage(p_image);

		p_image = new sf::Image();
		p_image->loadFromFile("images/player-down.png");
		p_entity_image_manager->addImage(p_image);

		p_image = new sf::Image();
		p_image->loadFromFile("images/player-left.png");
		p_entity_image_manager->addImage(p_image);

		p_image = new sf::Image();
		p_image->loadFromFile("images/player-right.png");
		p_entity_image_manager->addImage(p_image);


}


void Entity::loadTexture(int index) {

	if (!texture.loadFromImage(*p_entity_image_manager->getImage(index))) {
		// error...
	} else {

		this->setTexture(texture);
	}
}

void Entity::setLocation(double x, double y) {

	this->setPosition(x, y);

}

void Entity::moveEntity(sf::Vector2i window_position){

	const sf::Vector2f& position = this->getPosition();

	int current_x = (int)position.x;
	int current_y = (int)position.y;


	if( current_x > window_position.x){

		this->moveLeft(dx);


	}else if ( current_x < 0){

		this->moveRight(dx);
	}


	if( current_y > window_position.y ){

		this->moveUp(dy);

	}else if (current_y < 0){

		this->moveDown(dy);

	}


}

void Entity::moveRight(float x) {

	this->loadTexture(RIGHT_FACING);
	this->move(x, 0);

}

void Entity::moveLeft(float x) {

	this->loadTexture(LEFT_FACING);
	this->move(-x, 0);
}

void Entity::moveUp(float y) {

	this->loadTexture(UP_FACING);
	this->move(0, -y);
}

void Entity::moveDown(float y) {

	this->loadTexture(DOWN_FACING);
	this->move(0, y);
}

void Entity::draw(sf::RenderWindow* window) {

	window->draw((*this));

}

Entity::~Entity() {

	delete p_entity_image_manager;
}


