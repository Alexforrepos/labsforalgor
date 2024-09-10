#pragma once
#include "FIO.h"
#include <vector>
class Student
{

	FIO fio;
	int ID_student,ID_system;
	vector<int> Marks;
public:
	Student();
	Student(FIO, int ID);
	~Student();
	
	void SetFio(FIO fio);
	void SetStudentId(int ID);
	void SetSystemId(int ID);
	void AddMark(int mark);


	FIO GetFio();
	int GetId();
	int GetSId();

	void Print();
};
