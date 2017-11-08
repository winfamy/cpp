#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void displayReverse(string);

int main() {
	string s;
	cout << "String: ";
	getline(cin, s);

	displayReverse(s);

	return 0;
}

void displayReverse(string s) {
	for(int i = s.length(); i >= 0; i--) {
		cout << s[i];
	}
	cout << endl;
}