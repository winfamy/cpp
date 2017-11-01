#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double retailPrice(double cost, double percentage);

int main() {
	double cost, markup;
	cout << "Cost: ";
	cin >> cost;

	cout << "Markup: ";
	cin >> markup;

	cout << "Retail: " << retailPrice(cost, markup) << endl;

	return 0;
}

double retailPrice(double cost, double percentage) {
	return cost + round(cost*percentage)/100;
}