/*
 * Level.cpp
 *
 *  Created on: May 23, 2014
 *      Author: Anthony
 */

#include "../headers/Tile.h"

Tile::Tile(std::string s_type) {

	this->type = s_type;
}

Tile::~Tile() {

}

std::string Tile::getType(){

	return type;
}
