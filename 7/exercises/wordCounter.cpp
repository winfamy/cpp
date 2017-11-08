#include <iostream>
#include <string>

using namespace std;

int wordCount(string s);

int main() {
	string s;
	cout << "String: ";
	getline(cin, s);

	cout << wordCount(s) << endl;

	return 0;
}

int wordCount(string s) {
	int space_count = 1;
	for(char c : s)
		if (c == ' ')
			space_count++;
	return space_count;
}