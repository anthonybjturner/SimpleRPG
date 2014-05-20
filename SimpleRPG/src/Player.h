/*
 * Player.h
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Location.h"
#include <SFML/Graphics.hpp>

class Player {
public:
	Player();
	virtual ~Player();
	void setLocation(double, double);
	sf::Sprite& getImage();
	void moveRight(float);
	void moveLeft(float);
	void moveUp(float);
	void moveDown(float);
private:
	sf::Sprite Sprite;


};

#endif /* PLAYER_H_ */
