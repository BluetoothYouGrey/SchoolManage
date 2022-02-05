#pragma once
#include "ClassRoom.h"
#include "teacher.h"
#include "ManagerViewers.h"
#include <windows.h> 

struct School {
	MyString title;

	bool TypeAuth = false;
	bool pincode = false;
	int password = 0;
	MyString secretWord;

	int counterClass = 0;
	ClassRoom* arrClass = new ClassRoom[counterClass];

	int counterTeacher = 0;
	teacher* arrTeacher = new teacher[counterTeacher];

	int counterViewers = 0;
	Viewers* arrViewers = new Viewers[counterViewers];

	void RemakeWord();
	int SeachViewers(char* name);
	void addViewers();
	void deleteViewers();
	void PrintViewers();

	void CreateSchool();
	void CreatePassword();
	void RemakePassword();
	void CheeckPassword();
	void deleteSchool();

	void PrintClassRoom();
	void PrintTeacher();

	void addTeacher();
	int SeacrhTeacher();
	void deleteTeacher();
	void RemakeTeacher();
	void SortTeacher();

	void addClass();
	int SeacrhClass();
	void deleteClass();
	void RemakeClass();

	void AddSubject(int index);
	void printSubject(int index);
	void deleteSubject(int index);
	void RemakeSubject(int index);
	void SortSubject(int index);
	
	void AddPuple(int index);
	void PrintPuple(int index);
	void deletePuple(int index);
	void RemakePuple(int index);
	void SortPuple(int index);

	bool CheeckMD();

	void SaveAllBin(FILE* a);
	void SaveTeacherBin(FILE* a);
	void SaveClassBin(FILE* a);
	void SaveSetting(FILE* a);
	void SaveViewers(FILE* a);

	void LoadAllDin(FILE* a);
	void LoadTeacherBin(FILE* a);
	void LoadClassBin(FILE* a);
	void LoadSetting(FILE* a);
	void LoadViewers(FILE* a);
};