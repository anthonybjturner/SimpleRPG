/*
 * TileMap.h
 *
 *  Created on: May 24, 2014
 *      Author: Anthony
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_
#include "SFML/Graphics.hpp"

class TileMap : public sf::Drawable, public sf::Transformable{

public:
	TileMap();
	~TileMap();
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

#endif /* TILEMAP_H_ */
