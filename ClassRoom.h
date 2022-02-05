#pragma once
#include "Puple.h"
#include "Subject.h"

struct ClassRoom {
	MyString NumberClass;

	int counterPuple = 0;
	Puple* arrPuple = new Puple[counterPuple];

	int counterSubject = 0;
	Subject* arrSubject = new Subject[counterSubject];

	void CreateClass();
	void PrintClass();
	void PrintSubjectClass();
	void RemakeClass();
	void deleteClass();
	
	void addPuple();
	int SeacrhPuple();
	void deletePuple();
	void RemakePuple();
	void SortPuple();

	void addSubject();
	int SeacrhSubject();
	void deleteSubject();
	void RemakeSubject();
	void SortSubject();

	void SaveBinClass(FILE* a);
	void LoadBinClass(FILE* a);
};