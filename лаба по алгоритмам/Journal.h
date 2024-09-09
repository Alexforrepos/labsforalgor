#pragma once
#include "Student.h"


class Journal
{
private:
	vector<Student*> students;
public:
	Journal();
	~Journal();

	void AddStudent(Student* s);
	void Sort();
	void Print();
};

