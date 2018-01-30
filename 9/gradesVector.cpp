#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


double findAvg(const vector<double>&);


int main()
{
    ifstream fin;
    fin.open("./data/grades.txt");

    vector<double> grades(1);
    string name;

    getline(fin, name);

    fin >> grades[0];

    while(!fin.eof())
    {
        grades.resize(grades.size() + 1);
        fin >> grades[grades.size() - 1];
    }

    cout << "Student Name: " << name << endl;
    cout << "Average Grade: " << findAvg(grades) << endl << endl;


    fin.close();

    return 0;
}


double findAvg(const vector<double>& grades)
{
    if (grades.size() == 1)
        return grades[0];

    double sum = grades[0];
    double minVal = grades[0];

    for (int i = 1; i < grades.size(); i++)
    {
        sum += grades[i];

        if (grades[i] < minVal)
        {
            minVal = grades[i];
        }
    }

    return (double)(sum - minVal) / (double)(grades.size() - 1);
}
