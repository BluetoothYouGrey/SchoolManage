#pragma once
#include "School.h"

void MenuTeacher(School& T) {
	int menu = 0;
	system("cls");
	do {
		cout << "1 - �������� �������             \n";
		cout << "2 - �������� ��������            \n";
		cout << "3 - ������� �������              \n";
		cout << "4 - �������� ���������� � �������\n";
		cout << "---------------------------------\n";
		cout << "0 - ����� � ������ ����          \n";
		cout << "������� �����: ";
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

	cout << "������� ����� ��� ���� ��������: " << endl;
	PupleClass = T.SeacrhClass();

	system("cls");

	
	do {
		cout << "����� - " << T.arrClass[PupleClass].NumberClass.str << endl;
		cout << "1 - �������� �������    \n";
		cout << "2 - ������� �������     \n";
		cout << "3 - �������� ��������   \n";
		cout << "4 - �������� �������    \n";
		cout << "5 - ����������          \n";
		cout << "------------------------\n";
		cout << "0 - ����� � ������� ����\n";
		cout << "��� �����: ";
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

	cout << "������� ����� ��� ���� ���������: " << endl;
	PupleSubject = T.SeacrhClass();

	system("cls");

	
	do {
		cout << "����� - " << T.arrClass[PupleSubject].NumberClass.str << endl;
		cout << "1 - �������� �������    \n";
		cout << "2 - �������� ���������  \n";
		cout << "3 - ������� �������     \n";
		cout << "4 - �������� �������    \n";
		cout << "5 - ���������� ���������\n";
		cout << "------------------------\n";
		cout << "0 - ����� � ������� ����\n";
		cout << "��� �����: ";
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
		cout << "1 - ���������� ���������\n";
		cout << "2 - ���������� ����������\n";
		cout << "---------------------------\n";
		cout << "3 - �������� ����� \n";
		cout << "4 - �������� ����� \n";
		cout << "5 - ����������� ������ \n";
		cout << "6 - ������� �����\n";
		cout << "---------------------------\n";
		cout << "0 - ����� � ������� ���� \n";
		cout << "������� �����: ";
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
		cout << "## 1 - ������� ��� ����     ##\n";
		cout << "## 2 - ��������� ��� ���    ##\n";
		cout << "## 3 - �������� ��� ���     ##\n";
		cout << "## 4 - �������� �����SEC    ##\n";
		cout << "## 5 - ��������  �����      ##\n";
		cout << "## 6 - ������ ����������    ##\n";
		cout << "##############################\n";
		cout << "## 0 - ����� � ������� ���� ##\n";
		cout << "��� �����: ";
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
		cout << "## 1 - �������� ��������    ##\n";
		cout << "## 2 - �������� �������     ##\n";
		cout << "## 3 - �������� ��������    ##\n";
		cout << "## 4 - �������� ���������   ##\n";
		cout << "##############################\n";
		cout << "## 10 - �������             ##\n";
		cout << "��� �����: ";
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
		cout << "## 1 - ������� ������������  ##\n";
		cout << "## 2 - �������� ������������ ##\n";
		cout << "###############################\n";
		cout << "## 0 - �����                 ##\n";
		cout << "��� �����: ";
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
