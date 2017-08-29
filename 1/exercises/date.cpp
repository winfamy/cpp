#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
	time_t rawtime;
	struct tm* timeObj;

	time(&rawtime);
	timeObj = localtime(&rawtime);

	cout << timeObj->tm_mday << " "
		 << timeObj->tm_mon << " "
		 << timeObj->tm_year + 1900 << endl;

	return 0;
}