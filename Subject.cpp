#include "Subject.h"

void Subject::CreateSubject() {
	char tmp[100];

	cout << "������� �������� ��������: ";
	cin.ignore();
	cin.getline(tmp, 100);
	title.setMyString(tmp);

	cout << "������� ���������� �����: ";
	cin >> hourEven;
}

void Subject::PrintSubject() {
	cout << " - ��������: " << title.str << endl;
	cout << " - ���������� �����: " << hourEven << endl << endl;
}

void Subject::RemakeSubject() {
	int menu = 0;

	cout << "1 - ��������\n";
	cout << "2 - ���������� �����\n";
	cout << "��� �����: ";
	cin >> menu;

	switch (menu) {
	default: cout << "Erorr: Wrong Answer \n"; break;
	case 1:
		char tmp[100];

		cout << "������� ����� ��������: ";
		cin.ignore();
		cin.getline(tmp, 100);
		title.setMyString(tmp);
		break;
	case 2:
		cout << "������� ����� ���������� �����: ";
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
