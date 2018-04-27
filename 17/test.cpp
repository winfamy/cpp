#include <iostream>
#include <string>

using namespace std;

struct dog {
	char name[20];
	string breed;
	int age;
};

void fill(dog &d, char *n, string b, int age) {
	strcpy(d.name, n);
	d.breed = b;
	d.age = age;
}

int main() {
	dog* elvis = new dog;
	char name[20] = {'e', 'l', 'v', 'i', 's'};
	string breed = "golden";
	fill(*elvis, name, breed, 12);
}