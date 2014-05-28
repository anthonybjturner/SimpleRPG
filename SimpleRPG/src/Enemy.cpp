/*
 * Enemy.cpp
 *
 *  Created on: May 25, 2014
 *      Author: Anthony
 */
#include "../headers/Enemy.h"
#include <iostream>
Enemy::Enemy(Level* lev, sf::Texture&t) :
		Sprite(lev, t) {

	do{
		x = rand() % GAME_WINDOW_WIDTH;
		y = rand() % GAME_WINDOW_HEIGHT;

	}while(!isValidLevelMove(x,y));


	viewing_distance.x = 3.0;
	viewing_distance.y = 3.0;

	//Use the number of tiles to determine the starting left and top position for perimeter.
	int perimeter_val = level->getRandomNumberRowTiles(5) ;
	perimeter.left = x - perimeter_val;//Calculate a beginning left perimeter value.
	perimeter.top = y - perimeter_val;
	perimeter.width = perimeter_val*2;
	perimeter.height = perimeter_val*2;

	setPosition(x, y);

}

Enemy::~Enemy() {
}

bool Enemy::isInViewingDistance(const sf::Rect<float> opponents_rect) {

	return perimeter.intersects(opponents_rect);
}

/**
 * Calculates this enemies distance away from an opponent
 */
sf::Vector2f Enemy::calculateDistance(Sprite*opponent) {

	sf::Vector2f distance_away;

	float goal_pos_x = opponent->getX();
	float goal_pos_y = opponent->getY();

	//Distance formula. The distance between the Sprites
	distance_away.x = goal_pos_x - x;
	distance_away.y = goal_pos_y - y;
	return distance_away;
}

bool Enemy::simulateAI(Sprite* sprite) {

	sf::Vector2f opponents_distance = calculateDistance(sprite);

	float opp_x = sprite->getX();
	float opp_y = sprite->getY();
	if (isInViewingDistance( sf::Rect<float>(opp_x, opp_y, 26,28) )) {

		float mag = sqrt(
				(opponents_distance.x * opponents_distance.x) + (opponents_distance.y * opponents_distance.y));

		opponents_distance.x = opponents_distance.x / (mag);
		opponents_distance.y = opponents_distance.y / (mag);

		if (!moveE(opponents_distance.x, opponents_distance.y)) {

			while (!moveE(rand() % 3 - 1, rand() % 3 - 1)) {

			}
		}
		return true;
	}

	return false;
}

void Enemy::addEnemies(std::vector<Enemy*> entities_list) {

	this->entities_list = entities_list;

}

bool Enemy::moveE(float posx, float posy) {

	float pos_x =  (x + posx);
	float pos_y =  (y + posy);

	if (isValidLevelMove(pos_x, pos_y)) {

		facingDirection.x = x;
		facingDirection.y = y;

		setPosition(pos_x, pos_y);
		//switchDirection();
		return true;
	}
	return false;
}

void Enemy::idleUpdate(sf::Vector2f coords) {

	x = coords.x;
	y = coords.y;

}

