#include "Puple.h"

void Puple::CreatePuple() {
	char tmp[100];

	cout << "Введите имя ученика: ";
	cin.ignore();
	cin.getline(tmp, 100);
	Name.setMyString(tmp);

	cout << "Введите фамилию ученика: ";
	cin.getline(tmp, 100);
	Surname.setMyString(tmp);

	cout << "Введите дату рождение ученика: " << endl;
	BirthDay.fillDate();

	cout << "Введите возраст ученика: ";
	cin >> age;
}

void Puple::PrintPuple() {
	cout << "  - ФИ: " << Name.str << " " << Surname.str << endl;
	cout << "  - Дата рождения: " << BirthDay.toString() << endl;
	cout << "  - Возраст: " << age << endl << endl;
}

void Puple::RemakePuple() {
	int menu = 0;
	Date T;
	char tmp[100];
	int tmp12 = 0;

	cout << "1 - имя \n";
	cout << "2 - фамилия \n";
	cout << "3 - дату рождения \n";
	cout << "4 - возраст \n";
	cout << "Введите что надо изменить: ";
	cin >> menu;

	switch (menu) {
	default: cout << "\nError: Wrong answer \n"; break;
	case 1:
		cout << "Введите новое имя: ";
		cin.ignore();
		cin.getline(tmp, 100);
		Name.setMyString(tmp);
		cout << "Имя ученика успешно изменено! ";
		break;
	case 2:
		cout << "Введите новую фамилию: ";
		cin.ignore();
		cin.getline(tmp, 100);
		Surname.setMyString(tmp);
		cout << "фамилия ученика успешно изменена! ";
		break;

	case 3:
		cout << "Заполните новую дату рождения: " << endl;
		T.fillDate();

		BirthDay = T;

		cout << "Дата рождения ученика успешно изменена! \n";
		break;

	case 4:
		cout << "Введите новый возраст ученика: ";
		cin >> tmp12;

		age = tmp12;

		cout << "Возраст ученика успешно изменен! \n";
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
