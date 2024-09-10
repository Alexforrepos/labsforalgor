#include "Student.h"

Student::Student()
	:fio(),ID_student(0),Marks(),ID_system(0)
{
}

Student::Student(FIO fio, int ID)
	:Student()
{
	this->fio = fio;
	this->ID_student = ID;
}

Student::~Student()
{
}

void Student::SetFio(FIO fio)
{
	this->fio = fio;
}

void Student::SetStudentId(int ID)
{
	this->ID_student;
}

void Student::SetSystemId(int ID)
{
	this->ID_system = ID;
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
	return ID_student;
}

int Student::GetSId()
{
	return this->ID_system;
}

void Student::Print()
{
	cout << this->ID_system << " ";
	fio.Print();
	cout << ID_student <<":";
	for (int s : Marks)
		cout << s << " ";
	cout<<endl;
}
