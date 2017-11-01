#include <iostream>
#include <string>

using namespace std;

double low = 100;
void findLowest(int temp);
double calcAverage(int number, int sum);

void findLowest(int temp, double &low) {
	if (temp < low)
		low = temp;
}

double calcAverage(int number, int sum) {
	return (double)(sum - low)/(number - 1);
}

int main() {
	int numberOfTests, temp, sum = 0;
	cout << "Scores: ";
	cin >> numberOfTests;

	for	(int i = 0; i < numberOfTests; i++) {
		cin >> temp;
		if (!(temp < 0 || temp > 100)) {
			findLowest(temp, low);
			sum += temp;
		}
	}

	cout << "Average dropped: " << calcAverage(numberOfTests, sum) << endl;

	return 0;
}