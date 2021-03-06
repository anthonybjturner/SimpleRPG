/*
 * ImageLoader.h
 *
 *  Created on: May 21, 2014
 *      Author: turnera1
 */

#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_
#include "SFML/Graphics.hpp"

class ImageLoader {

public:
	ImageLoader();
	virtual ~ImageLoader();

	void addTexture(sf::Texture& texture);
	sf::Texture& getTexture(int);

private:

	std::vector<sf::Texture> image_list;

};

#endif /* IMAGELOADER_H_ */
