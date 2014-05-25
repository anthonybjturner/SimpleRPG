/*
 * level.h
 *
 *  Created on: May 23, 2014
 *  Author: Anthony Turner
 *  Description: Level represents a playable map (or space) in SimpleRPG.
 *  Its purpose is that players, enemies, characters, entities etc.
 *  traverse the level, interact on it, and the main actor completes level objectives.
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "Tile.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Level {

public:

	Level();
	Level(int, int);
	Level(string, int, int);

	void AddTile(int x, int y, Tile* tile);
	Tile* GetTile(int x, int y);
	void LoadLevel();
	int GetWidth();
	int GetHeight();

	void draw(sf::RenderWindow* window);
	~Level();

private:

	  //Width and height of level (in tiles)
	int width, height;
	//A 2D array of Tile pointers
	std::vector<std::vector<Tile*> > map;
	void SetDimensions(int w, int h);
};

#endif /* LEVEL_H_ */
