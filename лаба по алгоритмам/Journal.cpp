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

void Journal::Sort(SortType type)
{

	switch (type)
	{
	case SortType::Name:
		std::stable_sort(students.begin(), students.end(), [](Student* a, Student* b)
			{
				int i(0);
				while ((int)a->GetFio().GetName().c_str()[i] ==
					(int)b->GetFio().GetName().c_str()[i])
					i++;
				return (int)a->GetFio().GetName().c_str()[i] <=
					(int)b->GetFio().GetName().c_str()[i];
			}
		);
		break;
	case SortType::SName:
		std::stable_sort(students.begin(), students.end(), [](Student* a, Student* b)
			{
				int i(0);
				while ((int)a->GetFio().GetSurname().c_str()[i] ==
					(int)b->GetFio().GetSurname().c_str()[i])
					i++;
				return (int)a->GetFio().GetSurname().c_str()[i] <=
					(int)b->GetFio().GetSurname().c_str()[i];
			}
		);
		break;
	case SortType::FName:
		std::stable_sort(students.begin(), students.end(), [](Student* a, Student* b)
			{
				int i(0);
				while ((int)a->GetFio().GetFathname().c_str()[i] ==
					(int)b->GetFio().GetFathname().c_str()[i])
					i++;
				return (int)a->GetFio().GetFathname().c_str()[i] <=
					(int)b->GetFio().GetFathname().c_str()[i];
			}
		);
		break;
	case SortType::Id:
		std::stable_sort(students.begin(), students.end(), [](Student* a, Student* b)
			{
				return a->GetId() < b->GetId();
			});
		break;
	default:
		break;
	}
	
}

void Journal::Print()
{
	for (auto S : students)
		S->Print();
}
