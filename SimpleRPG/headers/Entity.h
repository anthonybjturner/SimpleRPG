/*
 * Entity.h
 *
 *  Created on: May 21, 2014
 *      Author: Anthony
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "SFML/Graphics.hpp"
#include "ImageLoader.h"

class Entity: public sf::Sprite {
public:
	Entity();
	virtual ~Entity();

	void setLocation(double, double);

		sf::Sprite& getImage();
		void moveRight(float);
		void moveLeft(float);
		void moveUp(float);
		void moveDown(float);
		void draw(sf::RenderWindow*);
		void moveEntity(int);

	private:

		//member variables
		sf::Texture texture;
		sf::Vector2i source;
		int dx;
		int dy;

		int move_left_count;
		int move_right_count;
		int	move_up_count;
		int move_down_count;
		int animation_frame;
		int move_right_animation_frame;

		int move_left_step_total;
		int move_right_step_total;
		int move_up_step_total;
		int move_down_step_total;

		int move_probability;

		//functions
		void switchDirection();
		bool loadImage();
		void resetSteps();
		void initMoveSteps();


};

#endif /* ENTITY_H_ */
