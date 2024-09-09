#include <iostream>
#include "Journal.h"
#include <fstream>

void JournalFill(Journal& j)
{
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
    file.close();
}

int main()
{
    system("chcp 1251 > 0");
    Journal j;
    JournalFill(j);
    j.Print();
    j.Sort(SortType::Name);
    cout  << "----------------------------------------------------------------------------------------------" << endl << "SORT:NAME" << endl << "----------------------------------------------------------------------------------------------" << endl;
    j.Print();
    j.Sort(SortType::SName);
    cout <<"----------------------------------------------------------------------------------------------" << endl << "SORT:SNAME" << endl << "----------------------------------------------------------------------------------------------" << endl;
    j.Print();
    j.Sort(SortType::FName);
    cout <<  "----------------------------------------------------------------------------------------------" << endl << "SORT:FNAME" << endl << "----------------------------------------------------------------------------------------------" << endl;
    j.Print();
    j.Sort(SortType::Id);
    cout << "----------------------------------------------------------------------------------------------" << endl << "SORT:ID" << endl << "----------------------------------------------------------------------------------------------" << endl;
    j.Print();

 
}