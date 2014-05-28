/*
 * Tile.h
 *
 *  Created on: May 23, 2014
 *  Author: Anthony Turner
 *  Description: Tile represents a
 */

#ifndef TILE_H_
#define TILE_H_
#include <string>

#define TILE_WIDTH (32)
#define TILE_HEIGHT (32)

class Tile{


public:
	Tile(std::string name);
	~Tile();


	std::string getType();
	//bool collides(sf::Rect<float>& );

private:

	std::string type;

};


#endif /* TILE_H_ */
