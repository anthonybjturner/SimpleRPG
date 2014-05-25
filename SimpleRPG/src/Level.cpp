/*
 * Level.cpp
 *
 *  Created on: May 23, 2014
 *      Author: Anthony
 */

#include "../headers/Level.h"
#include "../headers/Tile.h"

enum TEXTURES {
	WALL, GRASS, ROCKS, HILL
};

#include <vector>
#include "../headers/Level.h"
#include "../headers/Tile.h"

Level::Level(int w, int h)
{
	SetDimensions(w, h);
	this->width = w;
	this->height = h;
}

Level::~Level()
{

}

int Level::GetHeight()
{
	return height;
}

int Level::GetWidth()
{
	return width;
}

void Level::SetDimensions(int w, int h)
{
	//w rows
	map.resize(w);

	//Each row has h columns of null Tile pointers
	for(int i = 0; i < w; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int x, int y, Tile* tile)
{
	map[x][y] = tile;
}

Tile* Level::GetTile(int x, int y)
{
	return map[x][y];
}

void Level::LoadLevel()
{
	//Eventually we'll write code to load level data from a
	//file, but for now we'll just make it all up.
}

