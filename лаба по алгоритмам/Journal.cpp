#include "Journal.h"
#include <algorithm>

Journal::Journal()
	:students()
{

}

Journal::~Journal()
{
	for (auto S : students)
		delete S;
}

void Journal::AddStudent(Student* s)
{
	students.push_back(s);
}

void Journal::Sort()
{
	std::stable_sort(students.begin(), students.end(), [](Student* a, Student* b)
		{
			return a->GetId() < b->GetId();
		}
	);
}

void Journal::Print()
{
	for (auto S : students)
		S->Print();
}
