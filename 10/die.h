#include <string>
#include <vector>

using namespace std;

class Die {
	public:
		Die(int);
		int rollDie();
		void displayTable();
	private:
		vector<int> outcomes;
		int times;
};