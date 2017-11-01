#include <iostream>
#include <string>
using namespace std;

void test(int first, int& second);
int Getp(string str, char p);

int Getp(string str, char p) {
	int index = 0;
	for(char c : str) {
		if(c == p) {
			return index;
		}
		index++;
	}

	return -1;
}

int main() {
	cout << Getp("string", 't') << endl;

	return 0;
}

void test(int first, int& second) {
	int third;

	third = first + second * second + 2;
	first = second - first;
	second = 2 * second;

	cout << first << " " << second << " " << third << endl;
}