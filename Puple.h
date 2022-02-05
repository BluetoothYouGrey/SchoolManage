#pragma once
#include <stdio.h>
#include "Date.h"
#include "MyString.h"
#include <Windows.h>

struct Puple {
	MyString Name;
	MyString Surname;

	Date BirthDay;

	int age = 0;

	void CreatePuple();
	void PrintPuple();
	void RemakePuple();

	void SaveBinPuple(FILE* a);
	void LoadBinPuple(FILE* a);
};