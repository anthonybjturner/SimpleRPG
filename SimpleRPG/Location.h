/*
 * Location.h
 *
 *  Created on: May 19, 2014
 *      Author: Anthony
 */

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
public:
	Location();
	virtual ~Location();
	double getX();
	double getY();
	void setX(double);
	void setY(double);

private:
	double x, y;
};

#endif /* LOCATION_H_ */
