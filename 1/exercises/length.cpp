#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int centimeters, yards, feet, inches;
	cout << "Enter centimeters: ";
	cin >> centimeters;

	inches = round(centimeters/2.54);
	feet = inches/12;
	yards = feet/3;

	cout << yards << " yard(s) " << feet % 3 << " feet (foot) and " << inches % 12 << " inch(es)" << endl;

	return 0;
}