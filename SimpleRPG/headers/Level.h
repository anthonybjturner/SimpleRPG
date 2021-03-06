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
#include <vector>
#include "Tile.h"
#include "ImageLoader.h"

#define TILE_GRASS_ONE ("GrassOne")
#define TILE_GRASS_TWO ("GrassTWO")
#define TILE_CLAY ("Clay")
#define TILE_WALL ("Wall")



class Level {

public:

	Level(int, int);

	int getRandomNumberRowTiles(int);
	int getRandomNumberColTiles(int limit);

	int GetWidth();
	int GetHeight();
	Tile* GetTile(int x, int y);

	void AddTile(int x, int y, Tile* tile);
	void LoadLevel();
	void generateLevel();
	void drawLevel(sf::RenderWindow* window);
	void createLoader();
	sf::Vector2i pixelsToTileCoordinate(int x, int y);
	sf::Vector2i tileCoordinateToPixels(int tileX, int tileY);

	~Level();

private:

	  //Width and height of level (in tiles)
	int width, height;

	//A 2D array of Tile pointers
	std::vector< std::vector<Tile*> > map;
	void SetDimensions(int w, int h);
	ImageLoader tile_image_loader;


};

#endif /* LEVEL_H_ */
