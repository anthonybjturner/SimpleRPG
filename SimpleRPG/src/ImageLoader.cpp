/*
 * ImageLoader.cpp
 *
 *  Created on: May 21, 2014
 *      Author: turnera1
 */

#include "ImageLoader.h"

ImageLoader::ImageLoader() {
	// TODO Auto-generated constructor stub

}

ImageLoader::~ImageLoader() {

}

void ImageLoader::addImage(sf::Image& image){

	image_list.push_back(image);
}

sf::Image& ImageLoader::getImage(int index){

	return image_list[index];
}

