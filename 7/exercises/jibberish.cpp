#include <iostream>
#include <string>
#include <regex>

using namespace std;

string jib(string s);
void jibWords(string s);
int main() {
	string s, out;
	cout << "Enter phrase: ";
	getline(cin, s);

	jibWords(jib(s));
	return 0;
}

string jib(string s) {
	regex re("([a|o|i|u|y|e]+)");
	return regex_replace(s, re, "iddig$&");
}

void jibWords(string s) {
	for (int i = 0; i < s.length(); i++)
		cout << (char)tolower(s[i]);
	cout << endl;
}