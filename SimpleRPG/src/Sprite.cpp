/*
 * Sprite.cpp
 * Created on: May 21, 2014
 * Author: Anthony
 */

#include "../headers/Sprite.h"
Sprite::Sprite(Level *lev, sf::Texture& t) {

	this->setTexture(t, false);
	level = lev;
	source.x = 0;
	source.y = DOWN;
	this->switchDirection();
	this->x = rand() % 1024;
	this->y = rand() % 768;

}

float Sprite::getX() {

	return x;
}

float Sprite::getY() {

	return y;
}

/*
 * Adds the specified Sprite as a 'goal' for this Sprite
 */
void Sprite::addGoal(Sprite* goal) {}

bool Sprite::moveE(float x, float y) {return false;}

/*
 * @param xpos and ypos: The amount in pixels to check if is valid move
 */
bool Sprite::isValidLevelMove(float xpos, float ypos) {

	float x_calc = nearbyintf(xpos);
	float y_calc = nearbyintf(ypos);

	sf::Vector2i tile_coordinates = level->pixelsToTileCoordinate(x_calc,
			y_calc);

	Tile*tile = level->GetTile(tile_coordinates.x, tile_coordinates.y);
	if( tile == NULL){

		return false;
	}

	std::string type = tile->getType();
	if (type == (TILE_WALL)) {
			return false;
	}

	return true;
}

void Sprite::draw(sf::RenderWindow* window, float x, float y) {

	window->draw(*this);

}
void Sprite::switchDirection() {

	int width = 26;
	int height = 28; //Maybe 32 height
	int frame = source.x * width;
	int facing = source.y * height;
	sf::IntRect rect(frame, facing, width, height);

	this->setTextureRect(rect);
	source.x++; //After every move, we increment to the next frame (next animation)

}

void Sprite::setLocation(double x, double y) {

	this->setPosition(x, y);

}

Sprite::~Sprite() {

}

bool Sprite::simulateAI(Sprite* sprite){ return false;}
//Abstract/virtual
void Sprite::idleUpdate(sf::Vector2f) {}

