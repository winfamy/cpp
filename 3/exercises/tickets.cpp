#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	string name, job, age;
	int sum;
	cout << "Name: ";
	getline(cin, name);
	cout << "Job: ";
	getline(cin, job);
	cout << "Age: ";
	cin >> age;

	cout << "Ticket sales for: " << name << endl;
	cout << "Occupation: " << job << endl;
	cout << "Age: " << age << endl << endl;

	cout << setfill('=') << setw(40) << "=" << endl;
	cout << setfill(' ') << setw(20) << left << "Price" << right << setw(20) << "Sold" << endl;
	cout << setfill('=') << setw(40) << "=" << endl;

	ifstream fin;
	fin.open("compiled/data/tickets.txt");

	char data[8][10];
	for (int i = 0; i < 8; i+=2) {
		fin >> data[i] >> data[i+1];
		cout << setfill(' ');
		cout << setprecision(2) << setw(20) << left << data[i];
		cout << setprecision(0) << setw(20) << right << data[i+1] << endl;

		sum += stoi(data[i])*stoi(data[i+1]);
	}

	cout << setw(40) << setfill('=') << "=" << endl;
	cout << "Revenue: " << sum << endl;

	return 0;
}