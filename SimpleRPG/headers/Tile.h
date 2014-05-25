/*
 * Tile.h
 *
 *  Created on: May 23, 2014
 *  Author: Anthony Turner
 *  Description: Tile represents a
 */

#ifndef TILE_H_
#define TILE_H_
#include "Entity.h"
#include <string.h>
using namespace std;


class Tile : sf::Sprite{

public:
	Tile();
	Tile(string, sf::Texture& texture);
	~Tile();

	void setImage(string n);
	void draw(int, int, sf::RenderWindow* window);
	static const int TILE_WIDTH = 30;
	static const int TILE_HEIGHT = 30;
	string getType();
	bool collides(sf::Rect<float>& );

private:

	string type;

};


#endif /* TILE_H_ */
