/*
 * Entity.h
 *
 *  Created on: May 21, 2014
 *      Author: Anthony
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "SFML/Graphics.hpp"
#include <math.h>
#include "Level.h"
#include <iostream>

#define GAME_WINDOW_WIDTH (1024)
#define GAME_WINDOW_HEIGHT (768)

class Sprite: public sf::Sprite {


public:

	Sprite(Level *lev, sf::Texture& t);
	~Sprite();

	//functions
	virtual bool simulateAI(Sprite* sprite);
	virtual bool moveE(float x, float y);
	virtual void idleUpdate(sf::Vector2f);
	void setLocation(double, double);
	void draw(sf::RenderWindow*, float x, float y);
	void addGoal(Sprite* p);
	void switchDirection();
	bool isValidLevelMove(float x, float y);
	float getX();
	float getY();

protected:
	sf::Texture texture;
	sf::Vector2i source;
	sf::Vector2f facingDirection;
	Level* level;
	float x;
	float y;
	sf::Rect<float>perimeter;


	enum DIRECTIONS {DOWN, LEFT, RIGHT, UP};

};

#endif /* ENTITY_H_ */
