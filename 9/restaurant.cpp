#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct MenuItem {
	string name;
	double price;
};

void getData(vector<MenuItem> &v) {
	ifstream fin;
	fin.open("./data/menu.txt");

	string name;
	double price;
	for (int i = 0; i < 8; i++) {
		getline(fin, name);
		fin >> price;
		fin.ignore();
		v.push_back((MenuItem){ name, price });
	}

	cout << "done" << endl;
}

void printMenu(vector<MenuItem> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << left << i + 1 << ".  " << setw(20) << v[i].name << setw(7) << v[i].price << endl;
	}
	cout << "E. " << setw(20) << "Exit" << endl;
}

void printCheck(vector<MenuItem> v) {
	int sum = 0;
	cout << setprecision(2) << showpoint << fixed;
	for (int i = 0; i < v.size(); i++) {
		cout << setw(20) << v[i].name << "$" << setw(5) << v[i].price << endl;
		sum += v[i].price;
	}
	cout << setw(20) << "Tax" << "$" << setw(5) << sum*.07 << endl;
	cout << setw(20) << "Total" << "$" << setw(5) << sum + sum*.07 << endl;
}

int main() {
	vector<MenuItem> order;
	vector<MenuItem> menu;

	getData(menu);
	printMenu(menu);

	char val;
	while (!(val == 69 || val == 101)) {
		cout << "Item: ";
		cin >> val;
		// cout << val << endl;
		if (val >= 49 && val <= 56) {
			order.push_back(menu[val-49]);
		} else if (val == 69 || val == 101) {
			break;
		} else {
			cout << "Not a valid option!" << endl;
		}
	}

	printCheck(order);

	cout << "Press enter to exit..." << endl;
	cin.get();

	return 0;
}
