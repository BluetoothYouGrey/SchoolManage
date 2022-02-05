#pragma once
#include "MyString.h"
#include "Date.h"
#include <stdio.h>

struct teacher {
	MyString Name;
	MyString MiddleName;

	Date BirthDay;

	MyString MainWork;

	int yearWorked = 0;

	void CreateTeacher();
	void PrintTeacher();
	void RemakeTeacher();

	void SaveBinTeacher(FILE* b);
	void LoadBinTeacher(FILE* b);
};