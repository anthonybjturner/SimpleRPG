/*
 * Player.h
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Sprite.h"

class Player : public Sprite{

public:

	Player(Level*lev, sf::Texture& texture);
	~Player();

	void setLocation(double, double);
	void moveRight(float);
	void moveLeft(float);
	void moveUp(float);
	void moveDown(float);
	void moveTo(float x, float y);

	void draw(sf::RenderWindow*, float x, float y);
	void switchDirection();

	bool moveE(float x, float y);
	bool simulateAI(Sprite* sprite);
	void idleUpdate(sf::Vector2f);

};

#endif /* PLAYER_H_ */
