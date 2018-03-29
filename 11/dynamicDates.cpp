#include "date.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	int day, month, year;
	date *d;
	bool looping = true;
	int choice;
	while(looping) {
		cout << "day: ";
		cin >> day;
		cout << "month: ";
		cin >> month;
		cout << "year: ";
		cin >> year;
		d = new date(day, month, year);

		cout << "Chosoe date format" << endl;
		cout << "1. MM/DD/YYYY" << endl;
		cout << "2. Month Day, Year" << endl;
		cout << "3. Day Month Year" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				(*d).displayDate1();
				break;
			case 2:
				(*d).displayDate2();
				break;
			case 3:
				(*d).displayDate3();
				break;
			default:
				cout << "You chose an invalid option, displaying 1." << endl;
				(*d).displayDate1();
				break;
		}

		cout << endl << endl;
		cout << "Choose an option to continue." << endl;
		cout << "1. Enter new date" << endl;
		cout << "2. Exit";
		cout << "Choice: ";
		cin >> choice;
		switch (choice) {
			if (choice == 2)
				looping = false;
		}
	} 

	return 0;
}