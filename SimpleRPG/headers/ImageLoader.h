/*
 * ImageLoader.h
 *
 *  Created on: May 21, 2014
 *      Author: turnera1
 */

#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include "SFML/Graphics.hpp"
using namespace std;

class ImageLoader {
public:
	ImageLoader();
	virtual ~ImageLoader();

	void addTexture(sf::Texture& texture);
	sf::Texture& getTexture(int);

private:

	sf::Image image;
	vector<sf::Texture> image_list;
};

#endif /* IMAGELOADER_H_ */
