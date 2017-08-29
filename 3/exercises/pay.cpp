#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc,char** argv) {
	ofstream fout;
	fout.open("./outfiles/pay.txt");

	string name;
	int gross;

	cout << "Name: ";
	getline(cin, name);

	cout << "Gross Pay: ";
	cin >> gross;
	cout << gross << endl;

	fout << setfill('.') << setprecision(2) << fixed;
	fout << name << endl;
	fout << left << setw(20) << "Gross Amount: " << right << setw(15) << gross << endl;
	fout << left << setw(20) << "Federal Tax: " << right << setw(15) << gross*.15 << endl;
	fout << left << setw(20) << "State Tax: " << right << setw(15) << gross*.035 << endl;
	fout << left << setw(20) << "Social Security Tax: " << right << setw(15) << gross*.0575 << endl;
	fout << left << setw(20) << "Medicare Tax: " << right << setw(15) << gross*.0275 << endl;
	fout << left << setw(20) << "Pension Plan: " << right << setw(15) << gross*.05 << endl;
	fout << left << setw(20) << "Health Insurance: " << right << setw(15) << 75 << endl;
	fout << left << setw(20) << "Gross Pay: " << right << setw(15) << gross - (gross*.15) - (gross*.035) - (gross*.0575) - (gross*.0275) - (gross*.05) - 75 << endl;


	return 0;
}