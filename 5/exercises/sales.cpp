#include <iostream>
#include <string>

using namespace std;

string generateAsterisks(int count) {
	string asterisks = "";
	count = count/100;
	for (int i = 0; i < count; i++) {
		asterisks += "*";
	}

	return asterisks;
}

int main() {
	int sales1, sales2, sales3, sales4, sales5;

	cout << "Enter sales1: ";
	cin >> sales1;
	cout << "Enter sales2: ";
	cin >> sales2;
	cout << "Enter sales3: ";
	cin >> sales3;
	cout << "Enter sales4: ";
	cin >> sales4;
	cout << "Enter sales5: ";
	cin >> sales5;

	cout << endl << "SALES CHART" << endl;
	cout << "Store 1: " << generateAsterisks(sales1) << endl;
	cout << "Store 2: " << generateAsterisks(sales2) << endl;
	cout << "Store 3: " << generateAsterisks(sales3) << endl;
	cout << "Store 4: " << generateAsterisks(sales4) << endl;
	cout << "Store 5: " << generateAsterisks(sales5) << endl;

	return 0;
}