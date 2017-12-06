#include <iostream>

using namespace std;

enum triangleType { scalene, isosceles, equilateral, noTriangle };
void getLengths(double&, double&, double&);
triangleType shape(double&, double&, double&);
void displayShape(triangleType);

int main() {
	double side1, side2, side3;
	getLengths(side1, side2, side3);

	return 0;
}

void getLengths(double& side1, double& side2, double& side3) {
	cout << "Side 1: ";
	cin >> side1;
	cout << "Side 2: ";
	cin >> side2;
	cout << "Side 3: ";
	cin >> side3;

	displayShape(shape(side1, side2, side3));
}

triangleType shape(double& side1, double& side2, double& side3) {
	if (side1 + side2 < side3)
		return noTriangle;
	else if (side2 + side3 < side1)
		return noTriangle;
	else if (side1 + side3 < side2)
		return noTriangle;
	else if (side1 == side2 && side2 == side3)
		return equilateral;
	else if (side1 == side2 || side2 == side3 || side3 == side1)
		return isosceles;
	else
		return scalene;
}

void displayShape(triangleType type) {
	switch(type) {
		case scalene:
			cout << "scalene" << endl;
			break;
		case isosceles:
			cout << "isosceles" << endl;
			break;
		case equilateral:
			cout << "equilateral" << endl;
			break;
		case noTriangle:
			cout << "noTriangle" << endl;
			break;
	}
}