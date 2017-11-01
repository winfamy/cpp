#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int people, instruction, renting;
double costBase = 0, costInstruction = 0, costRenting = 0, discount = 0;
const int BASE_CHARGE_CLIMBING = 350;
const int BASE_CHARGE_SCUBA = 1000;
const int BASE_CHARGE_SPELUNKING = 700;
const int INSTRUCTION_CHARGE_CLIMBING = 100;
const int INSTRUCTION_CHARGE_SCUBA = 100;
const int RENT_CHARGE_CLIMBING = 120;
const int RENT_CHARGE_SPELUNKING = 240;

void menu();
double climbing(int p, int i, int r);
double scuba(int p, int i);
double spelunking(int p, int r);
void getTotal();

int main() {
	menu();
	getTotal();
	return 0;
}

double climbing(int p, int i, int r) {
	costBase = p*BASE_CHARGE_CLIMBING;
	costInstruction = i*INSTRUCTION_CHARGE_CLIMBING;
	costRenting = r*RENT_CHARGE_CLIMBING;

	return p*BASE_CHARGE_CLIMBING + i*INSTRUCTION_CHARGE_CLIMBING + r*RENT_CHARGE_CLIMBING;
}

double scuba(int p, int i) {
	costBase = p*BASE_CHARGE_SCUBA;
	costInstruction = i*INSTRUCTION_CHARGE_SCUBA;

	return p*BASE_CHARGE_SCUBA + i*INSTRUCTION_CHARGE_SCUBA;
}

double spelunking(int p, int r) {
	costBase = p*BASE_CHARGE_SPELUNKING;
	costRenting = r*RENT_CHARGE_SPELUNKING;

	return p*BASE_CHARGE_SCUBA + r*RENT_CHARGE_SPELUNKING;
}

void getTotal() {
	discount = (people >= 5) ? costBase*.1 : 0;

	ofstream fout;
	fout.open("./outfiles/adventure.txt");

	fout << fixed << showpoint << setprecision(2);
	fout << left << setw(30) << setfill('.') << "People" << "  " <<setw(10) << setfill(' ') << right << people << endl;
	fout << left << setw(30) << setfill('.') << "Base Charges" << " $" << setw(10) << setfill(' ') << right << costBase << endl;
	fout << left << setw(30) << setfill('.') << "Discount" << "-$" << setw(10) << setfill(' ') << right << costBase*.1 << endl;
	fout << left << setw(30) << setfill('.') << "Instruction Cost" << " $" << setw(10) << setfill(' ') << right << costInstruction << endl;
	fout << left << setw(30) << setfill('.') << "Equipment Rental" << " $" << setw(10) << setfill(' ') << right << costRenting << endl;
	fout << setw(40) << setfill('-') << "-" << endl;

	fout << left << setw(32) << setfill('.') << "Subtotal" << setw(10) << setfill(' ') << right << costBase + costInstruction + costRenting - discount<< endl;
	fout << left << setw(32) << setfill('.') << "Tax" << setw(10) << setfill(' ') << right << (costBase + costInstruction + costRenting- discount)*.05 << endl;
	fout << left << setw(32) << setfill('.') << "Total" << setw(10) << setfill(' ') << right << costBase + costInstruction + costRenting - discount + (costBase + costInstruction + costRenting- discount)*.05 << endl;
	fout << left << setw(32) << setfill('.') << "Deposit" << setw(10) << setfill(' ') << right << (costBase + costInstruction + costRenting - discount)*.5 << endl;
}

void menu() {
	int choice;
	cout << "-- Adventure Camp --" << endl;
	cout << "1) Climbing " << endl;
	cout << "2) Scuba " << endl;
	cout << "3) Spelunking " << endl;
	cout << "4) Exit" << endl;

	cout << "Choice: ";
	cin >> choice;

	switch(choice) {
		case 1:
			cout << "People: ";
			cin >> people;
			cout << "Instruction: ";
			cin >> instruction;
			cout << "Renting: ";
			cin >> renting;

			climbing(people, instruction, renting);
			break;
		case 2:
		cout << "People: ";
			cin >> people;
			cout << "Instruction: ";
			cin >> instruction;

			scuba(people, instruction);
			break;
		case 3:
			cout << "People: ";
			cin >> people;
			cout << "Renting: ";
			cin >> renting;

			spelunking(people, renting);
			break;
		case 4:
			return;

	}
}