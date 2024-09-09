#pragma once
#include <string>
#include <iostream>
using namespace std;
class FIO
{
private:
	std::string name, sname, fname;
public:
#pragma region ctors
	FIO();
	FIO(string name,string sname,string fname);
	~FIO();
#pragma endregion
#pragma region Set/GetMeths
	string GetName();
	string GetSurname();
	string GetFathname();

	void SetName(string name);
	void SetSurname(string sname);
	void SetFathname(string fname);

	void Print();
#pragma endregion
};
