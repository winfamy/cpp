#include <iostream>
#include <string>

using namespace std;

int main() {
	string name = "Grady";

	for (char& c : name) {
		cout << c << "\t\t" << (int)c << endl;
	}

	return 0;
}