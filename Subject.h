#pragma once
#include "MyString.h"
#include <stdio.h>

struct Subject {
	MyString title;

	int hourEven = 0; 

	void CreateSubject();
	void PrintSubject(); 
	void RemakeSubject();

	void SaveBinSubject(FILE* a);
	void LoadBinSubject(FILE* a);
};