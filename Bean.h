#pragma once
#include "Menu.h"

 // 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


void Bean(School& T, FILE* a) {
	int menu = 0;
	T.LoadAllDin(a);

	if (T.pincode) {
		T.CheeckPassword();
		system("cls");
	}
	else
		cout << "������ ������� ������ � �������� ����� � ���� ��������! \n";

	while (T.TypeAuth == true) {
		ViewersMenu(T, a);

		if (T.TypeAuth == false)
			break;
	}

	do {
		cout << "1 - ���� �������� \n";
		cout << "2 - ���� ������� \n";
		cout << "3 - ���� �������� \n";
		cout << "4 - ���� ��������� \n";
		cout << "5 - ���� ������������� \n";
		cout << "----------------------\n";
		cout << "6 - ��������� \n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;

		switch (menu) {
		default: cout << "Erorr: Wrong Answer \n"; break;
		case 1: MenuTeacher(T); break;
		case 2: MenuClass(T); break;
		case 3: MenuPuple(T); break;
		case 4: MenuSubject(T); break;
		case 5: MenuONViewers(T); break;
		case 6: SettingMenu(T); break;
		case 0: 
			T.SaveAllBin(a); break;
			exit(0);
		}
		T.SaveAllBin(a);
	} while (menu != 0);

}