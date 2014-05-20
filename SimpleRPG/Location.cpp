/*
 * Location.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#include "Location.h"

Location::Location() {

	x = y = 0.0;

}

double Location::getX(){

	return x;
}
double Location::getY(){

	return y;
}

void Location::setX(double x){

	this->x = x;
}

void Location::setY(double y){

	this->y = y;
}

Location::~Location() {
	// TODO Auto-generated destructor stub
}

