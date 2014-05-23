/*
 * ImageLoader.cpp
 *
 *  Created on: May 21, 2014
 *      Author: turnera1
 */

#include "../headers/ImageLoader.h"
#include <iostream>

ImageLoader::ImageLoader() {




}

ImageLoader::~ImageLoader() {

	//Delete all images on the Heap.
	for(std::vector<sf::Image*>::iterator it = image_list.begin(); it != image_list.end(); ++it) {

		delete *it;//Dereferencing iterator pointer to get to Image*

	}
}


/**
 * Adds a image to the ImageLoader
 */
void ImageLoader::addImage(sf::Image* image){

	image_list.push_back((image));
}

sf::Image* ImageLoader::getImage(int index){

	return image_list[index];
}

