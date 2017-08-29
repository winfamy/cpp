#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	string fullName = "";
	int cups;
	string petName = "";

	cout << "Enter name: ";
	cin >> fullName;
	/*
	cin stops reading at whitespace, so spaces don't work
	*/
	//getline(cin, fullName);

	cout << "How many cups of coffee: ";
	cin >> cups;

	cin.ignore(80, '\n');
	// need if previous input is simple
	// ignore 80 characters OR until newline

	cout << "What's your pet's name: ";
	cin >> petName;

	cout << "Your name: " << fullName << endl;
	cout << "Coffee: " << cups << endl;
	cout << "Pet's name: " << petName << endl;

	cout << "Here's some fancy formatting" << endl;
	cout << setfill('-');

	cout << right << setw(30) << "All about me" << left << setw(8) << "-" << endl;
	cout << fixed;
	cout << showpoint;
	cout << setprecision(2);
	cout << setfill(' ');

	cout << left << setw(14) << "Name: " << right << setw(14) << fullName << endl;
	cout << left << setw(14) << "Coffee: " << right << setw(14) << cups << endl;
	cout << left << setw(14) << "Pet: " << right << setw(14) << petName << endl;


	return 0;
}