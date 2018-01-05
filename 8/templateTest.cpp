#include <iostream>

using namespace std;



template <typename t>
t getMin(t arr[7]) {
	t mini = arr[0];
	for (int i = 0; i < 7; i++)
		if (arr[i] < mini)
			mini = arr[i];
	return mini;
}

int main() {
	int arr[7] = {1, 2, 3, 4, 5, 6, 7};
	cout << getMin<int>(arr) << endl;
	return 0;
}
