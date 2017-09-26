#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream fin;
	ofstream fout;

	int number;
	char accountType;
	int minBalance;
	double currentBalance;

	fin.open("./compiled/data/accounts.txt");
	fout.open("./outfiles/accounts.txt");

	for	(int i = 0; i < 5; i++) {
		fin >> number >> accountType >> minBalance >> currentBalance;
		cout << "Number: " << number << endl;
		cout << "Type: " << accountType << endl;
		cout << "Minbalance: " << minBalance << endl;
		cout << "Current Balance: " << currentBalance << endl;

		fout << showpoint << fixed << setprecision(2) << showpoint;

		if (currentBalance < minBalance) {
			if (accountType == 'S') {
			fout << showpoint << fixed << setprecision(2) <<left << setw(8) << string("#") + to_string(number) << setw(10) << (accountType == 'S' ? "Savings" : "Checking") << setw(8) << "$" + to_string(minBalance) << "$" << (double)currentBalance - 10 << endl;

				fout << "Account received a $10.00 service fee." << endl;
			} else {
				fout << showpoint << fixed << setprecision(2) << left << setw(8) << string("#") + to_string(number) << setw(10) << (accountType == 'S' ? "Savings" : "Checking") << setw(8) << "$" + to_string(minBalance) << "$" << (double)(currentBalance - 25) << endl;
				fout << "Account received a $25.00 service fee." << endl;
			}
		} else {
			if (accountType == 'S') {
				fout << showpoint << fixed << setprecision(2) << left << setw(8) << string("#") + to_string(number) << setw(10) << (accountType == 'S' ? "Savings" : "Checking") << setw(8) << "$" + to_string(minBalance) << "$" << currentBalance + currentBalance*.04 << endl;
				fout << "Account received 4% interest." << endl;
			} else {
				if (currentBalance >= minBalance + 5000) {
					fout << showpoint << fixed << setprecision(2) << left << setw(8) << string("#") + to_string(number) << setw(10) << (accountType == 'S' ? "Savings" : "Checking") << setw(8) << "$" + to_string(minBalance) << "$" << currentBalance + currentBalance*.05 << endl;
					fout << "Account received 5% interest." << endl;
				} else {
					fout << showpoint << fixed << setprecision(2) << left << setw(8) << string("#") + to_string(number) << setw(10) << (accountType == 'S' ? "Savings" : "Checking") << setw(8) << "$" + to_string(minBalance) << "$" << currentBalance + currentBalance*.03 << endl;
					fout << "Account received 3% interest." << endl;
				}
			}
		}

		fout << endl;
	}

	return 0;
}