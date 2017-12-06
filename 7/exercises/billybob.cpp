#include <iostream>
#include <string>

using namespace std;

void sort(string& a, string& b);

int main() {
	string name, location;

	cout << "Name: ";
	getline(cin, name);

	cout << "Location: ";
	getline(cin, location);

	for(int i = 0; i < name.length(); i++) {
		if (tolower(name[i]) == 'h') {
			cout << "H found at pos " << i << endl;
			break;
		} else if (i == name.length() - 1) {
			cout << "no h in your name" << endl;
		}
	}

	char letter;
	int occurences = 0;
	cout << "Letter: ";
	cin >> letter;
	for (int i = 0; i < name.length(); i++)
		if (tolower(name[i]) == tolower(letter))
			occurences++;
	cout << "Your name has " << letter << " " << occurences << " times" << endl;

	string word1, word2, word3;
	cout << "Enter 3 words: ";
	cin >> word1;
	cin >> word2;
	cin >> word3;

	sort(word1, word2);
	sort(word2, word3);
	sort(word1, word3);
	sort(word1, word2);

	cout << word1 << " " << word2 << " " << word3 << endl;
	cout << "cy@ " << name << " the great" << endl;

	return 0;
}

void sort(string& a, string &b) {
	if (a.length() < b.length()) {
		for(int i = 0; i < a.length(); i++) {
			if (tolower(a[i]) < tolower(b[i]))
				return;
			else {
				swap(a, b);
				break;
			}
		}
	} else {
		for(int i = 0; i < b.length(); i++) {
			if (tolower(a[i]) < tolower(b[i]))
				return;
			else {
				swap(a, b);
				break;
			}
		}
	}
}