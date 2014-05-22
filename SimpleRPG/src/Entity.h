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
		void moveEntity(sf::Vector2i);

	private:

		//member variables
		sf::Texture texture;
		ImageLoader* p_entity_image_manager;
		int dx;
		int dy;
		//functions
		void loadTexture(int index);
		void loadImages();
};

#endif /* ENTITY_H_ */
