#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int wins, losses, ties = 0;
	cout << "Wins, losses, ties: ";
	cin >> wins >> losses >> ties;

	int totalPoints = wins + ties;
	double percentage = double(wins)/(ties + losses + wins);
	string name;
	cout << "name: ";
	cin >> name;

	cout << setfill(' ');

	cout << left << setw(14) << "Name: " << right << setw(14) << name << endl;
	cout << left << setw(14) << "Total Points: " << right << setw(14) << totalPoints << endl;
	cout << left << setw(14) << "Percentage: " << right << setw(14) << percentage << endl;

	return 0;
}