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
		cout << "Срочно укажите пароль и название школы в меню настроек! \n";

	while (T.TypeAuth == true) {
		ViewersMenu(T, a);

		if (T.TypeAuth == false)
			break;
	}

	do {
		cout << "1 - Меню учителей \n";
		cout << "2 - Меню классов \n";
		cout << "3 - Меню учеников \n";
		cout << "4 - Меню предметов \n";
		cout << "5 - Меню пользователей \n";
		cout << "----------------------\n";
		cout << "6 - Настройки \n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
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