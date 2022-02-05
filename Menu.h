#pragma once
#include "School.h"

void MenuTeacher(School& T) {
	int menu = 0;
	system("cls");
	do {
		cout << "1 - добавить учителя             \n";
		cout << "2 - просмотр учителей            \n";
		cout << "3 - удалить учителя              \n";
		cout << "4 - изменить информацию о учителе\n";
		cout << "---------------------------------\n";
		cout << "0 - выйти в прошое меню          \n";
		cout << "Введите номер: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Answer \n"; break;
		case 1: T.addTeacher(); break;
		case 2: T.PrintTeacher(); break;
		case 3: T.deleteTeacher(); break;
		case 4: T.RemakeTeacher(); break;
		case 0: system("cls"); break;
		}
		cout << endl;

		if(menu != 2)
			system("cls");
	} while (menu != 0);
}

void MenuPuple(School& T) {
	int PupleClass = 0;
	int menu = 0;

	cout << "Введите класс для меню учеников: " << endl;
	PupleClass = T.SeacrhClass();

	system("cls");

	
	do {
		cout << "КЛАСС - " << T.arrClass[PupleClass].NumberClass.str << endl;
		cout << "1 - Добавить ученика    \n";
		cout << "2 - Удалить ученика     \n";
		cout << "3 - Просмотр учеников   \n";
		cout << "4 - Изменить ученика    \n";
		cout << "5 - Сортировка          \n";
		cout << "------------------------\n";
		cout << "0 - Выйти в прошлое меню\n";
		cout << "Ваш выбор: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Answer! \n"; break;
		case 1: T.AddPuple(PupleClass); break;
		case 2: T.deletePuple(PupleClass); break;
		case 3: T.PrintClassRoom(); break;
		case 4: T.RemakePuple(PupleClass); break;
		case 5: T.SortPuple(PupleClass); break;
		case 0: system("cls"); break;
		}
		cout << endl;
		if (menu != 3)
			system("cls");
	} while (menu != 0);
}

void MenuSubject(School& T) {
	int PupleSubject = 0;
	int menu = 0;

	cout << "Введите класс для меню предметов: " << endl;
	PupleSubject = T.SeacrhClass();

	system("cls");

	
	do {
		cout << "КЛАСС - " << T.arrClass[PupleSubject].NumberClass.str << endl;
		cout << "1 - Добавить предмет    \n";
		cout << "2 - Просмотр предметов  \n";
		cout << "3 - Удалить предмет     \n";
		cout << "4 - Изменить предмет    \n";
		cout << "5 - сортировка предметов\n";
		cout << "------------------------\n";
		cout << "0 - выйти в прошлое меню\n";
		cout << "Ваш выбор: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Answer\n"; break;
		case 1: T.AddSubject(PupleSubject); break;
		case 2: T.printSubject(PupleSubject); break;
		case 3: T.deleteSubject(PupleSubject); break;
		case 4: T.RemakeSubject(PupleSubject); break;
		case 5: T.SortSubject(PupleSubject); break;
		case 0: system("cls"); break;
		}
		cout << endl;
		if (menu != 2)
			system("cls");
	} while (menu != 0);
}

void MenuClass(School& T) {
	int menu = 0;
	system("cls");
	do {
		cout << "1 - управления учениками\n";
		cout << "2 - управления предметами\n";
		cout << "---------------------------\n";
		cout << "3 - добавить класс \n";
		cout << "4 - изменить класс \n";
		cout << "5 - просмотреть классы \n";
		cout << "6 - удалить класс\n";
		cout << "---------------------------\n";
		cout << "0 - выйти в прошлое меню \n";
		cout << "Введите номер: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Answer\n";  break;
		case 1:	MenuPuple(T); break;
		case 2: MenuSubject(T); break;
		case 3: T.addClass(); break;
		case 4: T.RemakeClass(); break;
		case 5: T.PrintClassRoom(); break;
		case 6: T.deleteClass(); break;
		case 0: system("cls"); break;
		}
		cout << endl;
		if (menu != 5)
			system("cls");
	} while (menu != 0);
}

void SettingMenu(School& T) {
	int menu = 0;
	FILE* a = NULL;
	system("cls");
	do {
		cout << "##############################\n";
		cout << "## 1 - Удалить всю базу     ##\n";
		cout << "## 2 - Поставить пин код    ##\n";
		cout << "## 3 - изменить пин код     ##\n";
		cout << "## 4 - изменить словоSEC    ##\n";
		cout << "## 5 - изменить  школу      ##\n";
		cout << "## 6 - ручное сохранение    ##\n";
		cout << "##############################\n";
		cout << "## 0 - выйти в прошлое меню ##\n";
		cout << "Ваш выбор: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Task \n"; break;
		case 1: T.deleteSchool(); break;
		case 2: T.CreatePassword(); break;
		case 3: T.RemakePassword(); break;
		case 4: T.RemakeWord(); break;
		case 5: T.CreateSchool(); break;
		case 6:
			T.SaveAllBin(a);
			break;
		case 0: system("cls"); break;
		}
		cout << endl;
		system("cls");
	} while (menu != 0);
}

void ViewersMenu(School& T, FILE* a) {
	int menu = 0;
	int index = 0;

	do {
		cout << "##############################\n";
		cout << "## 1 - просмотр учетелей    ##\n";
		cout << "## 2 - просмотр классов     ##\n";
		cout << "## 3 - просмотр учеников    ##\n";
		cout << "## 4 - просмотр предметов   ##\n";
		cout << "##############################\n";
		cout << "## 10 - переход             ##\n";
		cout << "Ваш выбор: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Task \n"; break;
		case 1: T.PrintTeacher(); break;
		case 2: T.PrintClassRoom(); break;
		case 3:  
			index = T.SeacrhClass();
			T.PrintPuple(index);
			break;
		case 4:
			index = T.SeacrhClass();
			T.printSubject(index);
			break;
		case 10: 
			exit(0);
			break;
		}
		cout << endl << endl;
		T.SaveAllBin(a);
	} while (menu != 0);
}

void MenuONViewers(School& T) {
	int menu = 0;


	do {
		cout << "###############################\n";
		cout << "## 1 - Удалить пользователя  ##\n";
		cout << "## 2 - просмотр пользвателей ##\n";
		cout << "###############################\n";
		cout << "## 0 - выйти                 ##\n";
		cout << "Ваш выбор: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Task \n"; break;
		case 1: T.deleteViewers(); system("cls"); break;
		case 2: T.PrintViewers(); break;
		case 0:
			system("cls");
			break;
		}
		cout << endl;

	} while (menu != 0);
}
