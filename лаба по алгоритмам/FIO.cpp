#include "FIO.h"

FIO::FIO()
	:name(),sname(),fname()
{
	
}

FIO::FIO(string name, string sname, string fname)
{
	this->name = name;
	this->sname = sname;
	this->fname = fname;
}

FIO::~FIO()
{
	
}

string FIO::GetName()
{
	return name;
}

string FIO::GetSurname()
{
	return sname;
}

string FIO::GetFathname()
{
	return fname;
}

void FIO::SetName(string name)
{
	this->name = name;
}

void FIO::SetSurname(string sname)
{
	this->sname = name;
}

void FIO::SetFathname(string fname)
{
	this->fname = fname;
}

void FIO::Print()
{
	cout << name << " " << sname << " " << fname << " ";
}

