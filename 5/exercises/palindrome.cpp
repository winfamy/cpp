#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

void menu();
char getInput();
void handleInput();
void stringPalindrone();
void numberPalindrone();

void stringPalindrone() {
	string str, orig;
	cout << "Enter string: ";
	getline(cin, str);

	str.erase(remove_if(str.begin(), str.end(), [](char c) {
		return !isalpha(c);
	}), str.end());
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	orig = str;

    int n = str.length();
    for (int i=0; i<n/2; i++)
       swap(str[i], str[n-i-1]);

	if (str == orig) {
		cout << "palindrome" << endl;
	}
}

void numberPalindrone() {
	int a,no,b,temp=0;
	cout<<"Number: ";
	cin>>no;
	b=no;
	while(no>0) {
		a=no%10;
		no=no/10;
		temp=temp*10+a;
	}

	if(temp==b)
		cout<<"palindrome" << endl;
}






void menu() {
	cout << "1: String Palindrome" << endl;
	cout << "2: Numeric Palindrome" << endl;
	cout << "3: Exit" << endl;
}

char getInput() {
	char c;
	cout << "Input: ";
	cin >> c;
	return c;
}

void handleInput(char c) {
	cout << endl;
	switch(c) {
		case '1':
			stringPalindrone();
			break;
		case '2':
			numberPalindrone();
			break;
		case '3':
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "Invalid input!" << endl;
	}
}

int main() {
	while (true) {
		menu();
		handleInput(getInput());
	}

	return 0;
}