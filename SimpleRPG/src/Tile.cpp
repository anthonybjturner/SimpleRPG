/*
 * Level.cpp
 *
 *  Created on: May 23, 2014
 *      Author: Anthony
 */

#include "../headers/Tile.h"
#include <iostream>

Tile::Tile() {

	//tile_image = new sf::Image();

}


Tile::Tile(string type, sf::Texture& image) {

	setTexture(image);

}

Tile::~Tile() {

}

void Tile::setImage(string n){




}

bool Tile::collides(sf::Rect<float>& rect){

	return this->getGlobalBounds().intersects(rect);
}

string Tile::getType(){

	return type;
}

void Tile::draw(int x, int y, sf::RenderWindow* window){

	setPosition(x,y);
	window->draw(*this);

}
