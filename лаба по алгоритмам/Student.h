#pragma once
#include "FIO.h"
#include <vector>
class Student
{
	FIO fio;
	int ID;
	vector<int> Marks;
public:
	Student();
	Student(FIO, int ID);
	~Student();
	
	void SetFio(FIO fio);
	void SetId(int ID);
	void AddMark(int mark);

	FIO GetFio();
	int GetId();

	void Print();
};
