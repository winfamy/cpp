#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void print(const vector<string>&);
void removeLast(vector<string>&);
void addGuest(vector<string>&, string);
void replaceGuest(vector<string>&, string, string);
//void removeGuest(vector<string>&, string);
void removeGuest2(vector<string>&, string);
void removeGuestSlow(vector<string>&, string);


int main()
{
    vector<string> guestList(0);

    addGuest(guestList, "Amy");
    addGuest(guestList, "Bo");
    addGuest(guestList, "Carl");
    addGuest(guestList, "Doris");
    addGuest(guestList, "Eve");
    print(guestList);

    removeLast(guestList);
    print(guestList);

    addGuest(guestList, "Fred");
    print(guestList);

    replaceGuest(guestList, "Carl", "Cal");
    print(guestList);

    removeGuest2(guestList, "Amy");
    print(guestList);

    removeGuestSlow(guestList, "Bo");
    print(guestList);

    return 0;
}


void print(const vector<string>& guestList)
{
    cout << "Guests Invited:" << endl;

    for (int i = 0; i < int(guestList.size()); i++)
        cout << i + 1 << ". " << guestList[i] << endl;

    cout << endl;
}


void removeLast(vector<string>& guestList)
{
    guestList.resize(guestList.size() - 1);
}


void addGuest(vector<string>& guestList, string name)
{
    guestList.push_back(name);
}


void replaceGuest(vector<string>& guestList, string nameOld, string nameNew)
{
    replace (guestList.begin(), guestList.end(), nameOld, nameNew);
}


void removeGuest(vector<string>& guestList, string name)
{
    for (int i = 0; i < int(guestList.size()); i++)
        if (guestList[i] == name)
            guestList[i] = guestList[guestList.size()];

    guestList.resize(guestList.size() - 1);
}


void removeGuest2(vector<string>& guestList, string name)
{
    for (int i = 0; i < int(guestList.size()); i++)
    {
        if (guestList[i] == name)
        {
            guestList.erase(guestList.begin() + i);
            break;
        }
    }
}


void removeGuestSlow(vector<string>& guestList, string name)
{
    for (int i = 0; i < int(guestList.size()); i++)
        if (guestList[i] == name)
        {
            for (int j = i; j < int(guestList.size() - 1); j++)
                guestList[j] = guestList[j + 1];

            break;
        }

    guestList.resize(guestList.size() - 1);
}