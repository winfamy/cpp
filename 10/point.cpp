#include "point.h"
#include <string>
#include <iostream>

using namespace std;

point::point() {
	myX = 0;
	myY = 0;
}

point::point(int x, int y) {
	myX = x;
	myY = y;
}

int point::getY() {
	return myY;
}

int point::getX() {
	return myX;
}

int main() {

	return 0;
}