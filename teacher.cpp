#include "teacher.h"

void teacher::CreateTeacher() {
	char tmp[100];

	cout << "Введите имя учителя: ";
	cin.ignore();
	cin.getline(tmp, 100);
	Name.setMyString(tmp);
	
	cout << "Введите отчетво учителя: ";
	cin.getline(tmp, 100);
	MiddleName.setMyString(tmp);

	cout << "Заполните дату рождения учителя: " << endl;
	BirthDay.fillDate();

	cout << "Введите должность учителя: ";
	cin.ignore();
	cin.getline(tmp, 100);
	MainWork.setMyString(tmp);

	cout << "Введите стаж учителя: ";
	cin >> yearWorked;
}

void teacher::PrintTeacher() {
	cout << " - ИО: " << Name.str << " " << MiddleName.str << endl;
	cout << " - Дата рождения: " << BirthDay.toString() << endl;
	cout << " - Должность: " << MainWork.str << endl;
	cout << " - стаж: " << yearWorked << endl << endl;
}

void teacher::RemakeTeacher() {
	int menu = 0;
	Date T;
	char tmp[100];
	int ia = 0;

	cout << "1 - изменить ИО \n";
	cout << "2 - изменить дату рождения \n";
	cout << "3 - изменить должность \n";
	cout << "4 - изменить стаж \n";
	cout << "Ваш выбор: ";
	cin >> menu;
	
	switch (menu) {
	default: cout << "Erorr: Wrong Answer \n"; break;
	case 1:
		cout << "Введите новое имя: ";
		cin.ignore();
		cin.getline(tmp, 100);
		Name.setMyString(tmp);

		cout << "Введите новое отчество: ";
		cin.ignore();
		cin.getline(tmp, 100);
		MiddleName.setMyString(tmp);
		break;
	case 2:
		cout << "Введите новую дату рождения: " << endl;
		T.fillDate();

		BirthDay = T;
		break;
	case 3:
		cout << "Введите новою должность: ";
		cin.ignore();
		cin.getline(tmp, 100);
		MainWork.setMyString(tmp);

		break;
	case 4:
		cout << "Введите новый стаж: ";
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
