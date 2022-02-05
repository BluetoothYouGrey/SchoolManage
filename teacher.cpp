#include "teacher.h"

void teacher::CreateTeacher() {
	char tmp[100];

	cout << "������� ��� �������: ";
	cin.ignore();
	cin.getline(tmp, 100);
	Name.setMyString(tmp);
	
	cout << "������� ������� �������: ";
	cin.getline(tmp, 100);
	MiddleName.setMyString(tmp);

	cout << "��������� ���� �������� �������: " << endl;
	BirthDay.fillDate();

	cout << "������� ��������� �������: ";
	cin.ignore();
	cin.getline(tmp, 100);
	MainWork.setMyString(tmp);

	cout << "������� ���� �������: ";
	cin >> yearWorked;
}

void teacher::PrintTeacher() {
	cout << " - ��: " << Name.str << " " << MiddleName.str << endl;
	cout << " - ���� ��������: " << BirthDay.toString() << endl;
	cout << " - ���������: " << MainWork.str << endl;
	cout << " - ����: " << yearWorked << endl << endl;
}

void teacher::RemakeTeacher() {
	int menu = 0;
	Date T;
	char tmp[100];
	int ia = 0;

	cout << "1 - �������� �� \n";
	cout << "2 - �������� ���� �������� \n";
	cout << "3 - �������� ��������� \n";
	cout << "4 - �������� ���� \n";
	cout << "��� �����: ";
	cin >> menu;
	
	switch (menu) {
	default: cout << "Erorr: Wrong Answer \n"; break;
	case 1:
		cout << "������� ����� ���: ";
		cin.ignore();
		cin.getline(tmp, 100);
		Name.setMyString(tmp);

		cout << "������� ����� ��������: ";
		cin.ignore();
		cin.getline(tmp, 100);
		MiddleName.setMyString(tmp);
		break;
	case 2:
		cout << "������� ����� ���� ��������: " << endl;
		T.fillDate();

		BirthDay = T;
		break;
	case 3:
		cout << "������� ����� ���������: ";
		cin.ignore();
		cin.getline(tmp, 100);
		MainWork.setMyString(tmp);

		break;
	case 4:
		cout << "������� ����� ����: ";
		cin >> ia;

		yearWorked = ia;
		break;
	}
}

void teacher::SaveBinTeacher(FILE* b) {
	fwrite(&Name.length, sizeof(int), 1, b);
	fwrite(Name.str, sizeof(char), Name.length, b);

	fwrite(&MiddleName.length, sizeof(int), 1, b);
	fwrite(MiddleName.str, sizeof(char), MiddleName.length, b);

	fwrite(&MainWork.length, sizeof(int), 1, b);
	fwrite(MainWork.str, sizeof(char), MainWork.length, b);

	fwrite(&BirthDay.day, sizeof(int), 1, b);
	fwrite(&BirthDay.month, sizeof(int), 1, b);
	fwrite(&BirthDay.year, sizeof(int), 1, b);

	fwrite(&yearWorked, sizeof(int), 1, b);
}

void teacher::LoadBinTeacher(FILE* b) {
	fread(&Name.length, sizeof(int), 1, b);
	Name.str = new char[Name.length];
	fread(Name.str, sizeof(char), Name.length, b);

	fread(&MiddleName.length, sizeof(int), 1, b);
	MiddleName.str = new char[MiddleName.length];
	fread(MiddleName.str, sizeof(char), MiddleName.length, b);

	fread(&MainWork.length, sizeof(int), 1, b);
	MainWork.str = new char[MainWork.length];
	fread(MainWork.str, sizeof(char), MainWork.length, b);

	fread(&BirthDay.day, sizeof(int), 1, b);
	fread(&BirthDay.month, sizeof(int), 1, b);
	fread(&BirthDay.year, sizeof(int), 1, b);

	fread(&yearWorked, sizeof(int), 1, b);
}
