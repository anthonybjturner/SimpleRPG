/*
 * Enemy.h
 *
 *  Created on: May 25, 2014
 *      Author: Anthony
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Sprite.h"
//Player includes Sprite.h so we don't need to include Sprite.h
//Doing so would cause a cyclic redundancy.
class Enemy: public Sprite {



public:

	Enemy(Level* lev, sf::Texture&t);
	~Enemy();

	bool simulateAI(Sprite* sprite);
	bool moveE(float,float);
	void idleUpdate(sf::Vector2f);
	bool isInViewingDistance(const sf::Rect<float> opponents_rect);
	void addEnemies(std::vector<Enemy*> entities_list);
	sf::Vector2f calculateDistance(Sprite*opponent);
	std::vector<Enemy*> entities_list;

private:
	sf::Vector2f viewing_distance;
};




#endif /* ENEMY_H_ */
