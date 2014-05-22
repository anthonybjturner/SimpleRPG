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

	void addImage(sf::Image* image);
	sf::Image* getImage(int);

private:

	sf::Image image;
	vector<sf::Image*> image_list;
};

#endif /* IMAGELOADER_H_ */
