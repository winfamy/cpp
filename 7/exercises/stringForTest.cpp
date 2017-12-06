#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	string name = "bobby";
	string snew = "";
	for (char c : name) {
		if (c == 'b') {
			snew += "bb";
		} else {
			snew += c;
		}
	}

	cout << snew.substr(ceil(snew.length()/2.0), snew.length()) << endl;

	cout << snew << endl;

	return 0;
}