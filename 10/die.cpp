#include "die.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

Die::Die (int t) {
	times = t;
	outcomes = {
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0
	};
}

int Die::rollDie () {
	int roll;
	srand(time(0));
	for (int i = 0; i < times; i++) {
		roll = (rand() % 6 + 1) + (rand() % 6 + 1);
		outcomes[roll] += 1;
	}
}

void Die::displayTable () {
	cout << setprecision(2) << showpoint << fixed;
	cout << setw(10) << "Number" << setw(20) << "Probability" << setw(20) << "Occurence" << endl;

	cout << setw(10) << "2" << setw(20) << "1/36" << setw(20) << (double)outcomes[2]/times << endl;
	cout << setw(10) << "3" << setw(20) << "2/36" << setw(20) << (double)outcomes[3]/times << endl;
	cout << setw(10) << "4" << setw(20) << "3/36" << setw(20) << (double)outcomes[4]/times << endl;
	cout << setw(10) << "5" << setw(20) << "4/36" << setw(20) << (double)outcomes[5]/times << endl;
	cout << setw(10) << "6" << setw(20) << "5/36" << setw(20) << (double)outcomes[6]/times << endl;
	cout << setw(10) << "7" << setw(20) << "6/36" << setw(20) << (double)outcomes[7]/times << endl;
	cout << setw(10) << "8" << setw(20) << "5/36" << setw(20) << (double)outcomes[8]/times << endl;
	cout << setw(10) << "9" << setw(20) << "4/36" << setw(20) << (double)outcomes[9]/times << endl;
	cout << setw(10) << "10" << setw(20) << "3/36" << setw(20) << (double)outcomes[10]/times << endl;
	cout << setw(10) << "11" << setw(20) << "2/36" << setw(20) << (double)outcomes[11]/times << endl;
	cout << setw(10) << "12" << setw(20) << "1/36" << setw(20) << (double)outcomes[12]/times << endl;
}

int main() {
	int t;
	cout << "Roll count: ";
	cin >> t;

	Die d = Die(t);
	d.rollDie();
	d.displayTable();

	return 0;
}