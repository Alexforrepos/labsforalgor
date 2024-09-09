#include <iostream>
#include "Journal.h"
#include <fstream>

int main()
{
    system("chcp 1251 > 0");
    Journal j;
    Student* S;
    string name, sname, fname;
    vector<int> tmpvector;
    int id;
    long long allmarks;


    ifstream file("kptnc.txt");
    if (!file.is_open())
    {
        cout << "err\n";
        exit(-1);
    }
    while (!file.eof())
    {
        file >> name >> sname >> fname >> id >> allmarks;
        S = new Student(FIO(name, sname, fname), id);
        while (allmarks != 0)
        {
            tmpvector.push_back(allmarks % 10);
            allmarks /= 10;
        }
        for (auto a = tmpvector.end(); a != tmpvector.begin();)
        {
            --a;
            S->AddMark(*a);
        }
        j.AddStudent(S);
        tmpvector.clear();
    }
    j.Print();
    j.Sort();
    cout << "----------------------------------------------------------------------------------------------" << endl;
    j.Print();
    file.close();
}