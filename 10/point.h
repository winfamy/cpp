#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;

class point {
	public:
		point();
		point(int, int);
		void setX(int);
		void setY(int);
		int getX();
		int getY();
		void moveHor(int);
		void moveVer(int);
	private:
		int myX;
		int myY;
};

#endif