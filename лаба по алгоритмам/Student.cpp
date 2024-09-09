#include "Student.h"

Student::Student()
	:fio(),ID(0),Marks()
{
}

Student::Student(FIO fio, int ID)
	:Student()
{
	this->fio = fio;
	this->ID = ID;
}

Student::~Student()
{
}

void Student::SetFio(FIO fio)
{
	this->fio = fio;
}

void Student::SetId(int ID)
{
	this->ID;
}

void Student::AddMark(int mark)
{
	if (mark > 0 && mark < 6)
		Marks.push_back(mark);
}

FIO Student::GetFio()
{
	return fio;
}

int Student::GetId()
{
	return ID;
}

void Student::Print()
{
	fio.Print();
	cout << ID <<" ";
	for (int s : Marks)
		cout << s << " ";
	cout<<endl;
}
