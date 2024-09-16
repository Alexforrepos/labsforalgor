#include "Journal.h"
#include <algorithm>
#include <fstream>
#include <sstream>
Journal::Journal()
	:students()
{

}



Journal::~Journal()
{
	this->Clear();
}
void Journal::Fill(std::string filepath)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		std::cerr << "Error ofile: " << filepath << std::endl;
		exit(-2);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		int number, id, mark;
		std::string name, sname, fname;

		if (!(ss >> number >> name >> sname >> fname >> id))
		{
			std::cerr << "Error rline: " << line << std::endl;
			continue;
		}

		Student* student = new Student(FIO(name, sname, fname), id);
		student->SetSystemId(number);

		while (ss >> mark)
		{
			student->AddMark(mark);
		}
		students.push_back(student);
	}
	file.close();
}

void Journal::Clear()
{
	for (auto S : students)
		delete S;
	students.clear();
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
	case SortType::IdSystem:
		stable_sort(students.begin(), students.end(), [](Student* a, Student* b)
			{
				return a->GetSId() < b->GetSId();
			});
		break;
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

Student* Journal::Find(FindType type,string name)
{
	vector<Student*>::iterator S;
	switch (type)
	{
	case FindType::Name:
		S = find_if(students.begin(), students.end(),
			[name](Student* a)
			{
				return a->GetFio().GetName() == name;
			});
		if (S != students.end())
			return *S;
		return nullptr;
		break;
	case FindType::Sname:
		S = find_if(students.begin(), students.end(),
			[name](Student* a)
			{
				return a->GetFio().GetSurname() == name;
			});
		if (S!= students.end())
			return *S;
		return nullptr;
		break;
	case FindType::Fname:
		S = std::find_if(students.begin(), students.end(),
			[name](Student* a)
			{
				return a->GetFio().GetFathname() == name;
			});
		if (S != students.end())
			return *S;
		return nullptr;
		break;
	default:
		break;
	}

}

