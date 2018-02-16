#include <string>

using namespace std;

class name {
	public:
		name();
		name(const name &n);
		name(string, string, string);
		string getFirst();
		string getMiddle();
		string getLast();
		void setFirst(string);
		void setMiddle(string);
		void setLast(string);
		void displayName();
		void marry(string);
		void displayInvert();
	protected:
		string first;
		string middle;
		string last;
};