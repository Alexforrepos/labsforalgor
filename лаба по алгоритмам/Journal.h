#pragma once
#include "Student.h"

enum class SortType
{
	Name,SName,FName,Id,IdSystem
};
enum class FindType
{
	Name,Sname,Fname
};

class Journal
{
private:
	vector<Student*> students;
public:
	Journal();
	~Journal();

	void Fill(string filepath);
	void Clear();
	void AddStudent(Student* s);
	void Sort(SortType type);
	void Print();
	Student* Find(FindType type,string name);
};

