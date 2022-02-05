#include "Puple.h"

void Puple::CreatePuple() {
	char tmp[100];

	cout << "������� ��� �������: ";
	cin.ignore();
	cin.getline(tmp, 100);
	Name.setMyString(tmp);

	cout << "������� ������� �������: ";
	cin.getline(tmp, 100);
	Surname.setMyString(tmp);

	cout << "������� ���� �������� �������: " << endl;
	BirthDay.fillDate();

	cout << "������� ������� �������: ";
	cin >> age;
}

void Puple::PrintPuple() {
	cout << "  - ��: " << Name.str << " " << Surname.str << endl;
	cout << "  - ���� ��������: " << BirthDay.toString() << endl;
	cout << "  - �������: " << age << endl << endl;
}

void Puple::RemakePuple() {
	int menu = 0;
	Date T;
	char tmp[100];
	int tmp12 = 0;

	cout << "1 - ��� \n";
	cout << "2 - ������� \n";
	cout << "3 - ���� �������� \n";
	cout << "4 - ������� \n";
	cout << "������� ��� ���� ��������: ";
	cin >> menu;

	switch (menu) {
	default: cout << "\nError: Wrong answer \n"; break;
	case 1:
		cout << "������� ����� ���: ";
		cin.ignore();
		cin.getline(tmp, 100);
		Name.setMyString(tmp);
		cout << "��� ������� ������� ��������! ";
		break;
	case 2:
		cout << "������� ����� �������: ";
		cin.ignore();
		cin.getline(tmp, 100);
		Surname.setMyString(tmp);
		cout << "������� ������� ������� ��������! ";
		break;

	case 3:
		cout << "��������� ����� ���� ��������: " << endl;
		T.fillDate();

		BirthDay = T;

		cout << "���� �������� ������� ������� ��������! \n";
		break;

	case 4:
		cout << "������� ����� ������� �������: ";
		cin >> tmp12;

		age = tmp12;

		cout << "������� ������� ������� �������! \n";
		break;
	}
}

void Puple::SaveBinPuple(FILE* a) {
	fwrite(&Name.length, sizeof(int), 1, a);
	fwrite(Name.str, sizeof(char), Name.length, a);

	fwrite(&Surname.length, sizeof(int), 1, a);
	fwrite(Surname.str, sizeof(char), Surname.length, a);

	fwrite(&BirthDay.day, sizeof(int), 1, a);
	fwrite(&BirthDay.month, sizeof(int), 1, a);
	fwrite(&BirthDay.year, sizeof(int), 1, a);

	fwrite(&age, sizeof(int), 1, a);
}

void Puple::LoadBinPuple(FILE* a) {
	fread(&Name.length, sizeof(int), 1, a);
	Name.str = new char[Name.length];
	fread(Name.str, sizeof(char), Name.length, a);

	fread(&Surname.length, sizeof(int), 1, a);
	Surname.str = new char[Surname.length];
	fread(Surname.str, sizeof(char), Surname.length, a);

	fread(&BirthDay.day, sizeof(int), 1, a);
	fread(&BirthDay.month, sizeof(int), 1, a);
	fread(&BirthDay.year, sizeof(int), 1, a);

	fread(&age, sizeof(int), 1, a);
}
