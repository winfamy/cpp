#include <iostream>
using namespace std;

void testDefaultParam(int u, int v = 5, double z = 3.2);

void testDefaultParam(int& u, int v, double z) {
	int a;
	u = u + static_cast<int>(2 * v + 2);
	a = u + v * z;
	cout << "a = " << a << endl;
}



int main() {
	testDefaultParam(6);
	testDefaultParam(3, 4);
	testDefaultParam(3, 0, 2.8);

	return 0;
}