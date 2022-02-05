#include "Subject.h"

void Subject::CreateSubject() {
	char tmp[100];

	cout << "Введите название предмета: ";
	cin.ignore();
	cin.getline(tmp, 100);
	title.setMyString(tmp);

	cout << "Введите количсетво часов: ";
	cin >> hourEven;
}

void Subject::PrintSubject() {
	cout << " - Название: " << title.str << endl;
	cout << " - Количество часов: " << hourEven << endl << endl;
}

void Subject::RemakeSubject() {
	int menu = 0;

	cout << "1 - Название\n";
	cout << "2 - количество часов\n";
	cout << "Ввш выбор: ";
	cin >> menu;

	switch (menu) {
	default: cout << "Erorr: Wrong Answer \n"; break;
	case 1:
		char tmp[100];

		cout << "Введите новое название: ";
		cin.ignore();
		cin.getline(tmp, 100);
		title.setMyString(tmp);
		break;
	case 2:
		cout << "Введите новое количество часов: ";
		cin >> hourEven;
		break;
	}
}

void Subject::SaveBinSubject(FILE* a) {
	fwrite(&title.length, sizeof(int), 1, a);
	fwrite(title.str, sizeof(char), title.length, a);

	fwrite(&hourEven, sizeof(int), 1, a);
}

void Subject::LoadBinSubject(FILE* a) {
	fread(&title.length, sizeof(int), 1, a);
	title.str = new char[title.length];
	fread(title.str, sizeof(char), title.length, a);

	fread(&hourEven, sizeof(int), 1, a);
}
