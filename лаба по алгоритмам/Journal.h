#pragma once
#include "Student.h"

enum class SortType
{
	Name,SName,FName,Id
};

class Journal
{
private:
	vector<Student*> students;
public:
	Journal();
	~Journal();

	void AddStudent(Student* s);
	void Sort(SortType type);
	void Print();
};

