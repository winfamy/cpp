#include <iostream>
#include <string>

using namespace std;

int* allo(int size) {
	int *array = new int[size];
	return array;
}

void sortIt(int* p, int elems)		
{					
					
	int startPos, minIndex; 
	int minValue;

	for (startPos = 0; startPos < (elems - 1); startPos++)
	{
		minIndex = startPos;
		minValue = p[startPos];

		for(int i = startPos + 1; i < elems; i++)
		{
			if (p[i] < minValue)
			{
				minValue = p[i];
				minIndex = i;
			}
		}

		p[minIndex] = p[startPos];
		p[startPos] = minValue;
	}
}

double average(int array[], int size) {
	int sum;
	for (int i = 0; i < size; i++) {
		sum = sum + array[i];
	}

	return (double)sum/size;
}

int main() {
	cout << "Size: ";
	int size;
	cin >> size;

	int* array = allo(size);
	for (int i = 0; i < size; i++) {
		cout << "Enter score: ";
		cin >> array[i];
		cout << array[i] << endl;
	}

	double avg = average(array, size);

	sortIt(array, size);
	cout << "Scores:" << endl;
	for (int j = 0; j < size; j++) {
		cout << " " << array[j] << ".00" << endl;
	}

	cout << "average: " << avg << endl;
}