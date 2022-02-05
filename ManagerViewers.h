#pragma once
#include "MyString.h";
#include "Date.h";
#include <cstdio>

struct Viewers {
	MyString Name;
	Date Day;
	int counterViewer = 0;

	void CreateViewer();
	void PrintViewer();

	void SaveViewersToBinFile(FILE* a);
	void LoadViewersFromBinFile(FILE* a);
};