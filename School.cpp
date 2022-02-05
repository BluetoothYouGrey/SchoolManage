#include "School.h"


void School::CreateSchool() {
	char tmp[100];

	cout << "Введите название школы: ";
	cin.ignore();
	cin.getline(tmp, 100);
	title.setMyString(tmp);
}

void School::CreatePassword() {
	system("cls");
	char tmp[100];

	cout << "МЕНЮ СОЗДАНИЕ ПАРОЛЯ..." << endl;
	do {
		cout << "Введите 4х значный пароль: ";
		cin >> password;
	} while (password <= 1000 && password >= 9999);

	cout << "Введите секретное слово для его восстановления... " << endl;
	cout << "выберите один из вопросов и ответьте: " << endl << endl;
	cout << "1. Как зовут вашего кота: \n";
	cout << "2. Как ваш называли в детсве\n";
	cout << "3. Любимый сериал/фильм \n";
	cout << "4. Любое слово\n";
	cout << "Ответ: ";

	cin.ignore();
	cin.getline(tmp, 100);
	secretWord.setMyString(tmp);

	cout << "\n Ваше слово: \"" << secretWord.str << "\", запиши его!" << endl;

	pincode = true;

	cout << "Продолжение через 30 секунд... \n";
	Sleep(4000);
	
	return;
}

void School::RemakePassword() {
	system("cls");
	char tmp[100];
	int tmp1 = 0;
	int newpassword = 0;

	cout << "МЕНЮ ВОССТАНОВЛЕНИЯ ПАРОЛЯ... \n" << endl;
	cout << "Вопросы для секретного слова: " << endl;
	cout << "1. Как зовут вашего кота: \n";
	cout << "2. Как ваш называли в детсве\n";
	cout << "3. Любимый сериал/фильм \n";
	cout << "4. Любое слово\n";
	cout << "Ответ: ";
	cin.ignore();
	cin.getline(tmp, 100);

	if (strcmp(tmp, secretWord.str) == 0) {
		cout << "Вы прошли проверку... " << endl;
		cout << "Хотите изменить пароль или напомнить(0, 1): ";
		cin >> tmp1;

		do {
			switch (tmp1) {
			default: cout << "Erorr: Wrong Answer\n"; break;
			case 0:
				do {
					cout << "Введите новый пароль(4 знака): ";
					cin >> newpassword;
					system("cls");
				} while (newpassword <= 1000 && newpassword >= 9999);
				password = newpassword;
				break;
			case 1:
				cout << "ВАШ ПАРОЛЬ: " << password << endl;
				break;
			}
		} while (tmp1 <= 0 && tmp1 >= 1);
	}

	cout << "Продолжение через 30 секунд... " << endl;
	Sleep(3000);
}

void School::deleteSchool() {
	for (int i = 0; i < counterClass; i++)
		arrClass[i].deleteClass();

	counterTeacher = 0;
	counterClass = 0;

	delete[] arrTeacher;
	delete arrClass;
}

void School::CheeckPassword() {
	system("cls");
	int password1 = 0;
	int TypeAuth1 = 0;

	do {
		cout << "Введите параметры входа: \n 1. Админ \n 2. режим просмотра \n 3. Выход \n" ;
		cout << "Ваш выбор: ";
		cin >> TypeAuth1;

		if (TypeAuth1 == 2) {
			addViewers();
			TypeAuth = true;
		}
		else if (TypeAuth1 == 1) {
			TypeAuth = false;
			do {
				cout << "Введите пароль: ";
				cin >> password1;

				if (password1 != password) {
					cout << "Хотите востановать пароль(0, 1): ";
					cin >> password1;

					if (password1 == 1)
						RemakePassword();
				}
			} while (password1 != password);
		}
		else if (TypeAuth1 == 3) {
			exit(0);

		}
		system("cls");
	} while (TypeAuth1 < 0 && 3 > TypeAuth1);
}

void School::addViewers() {
	char tmp1[100];

	cout << "Введите ваше имя: ";
	cin.ignore();
	cin.getline(tmp1, 100);

	int index = SeachViewers(tmp1);
	if (index == -1) {
		Viewers* tmp = new Viewers[++counterViewers];

		for (int i = 0; i < counterViewers - 1; i++) {
			tmp[i] = arrViewers[i];
		}

		tmp[counterViewers - 1].Name.setMyString(tmp1);
		tmp[counterViewers - 1].CreateViewer();

		if (arrViewers != NULL) delete[] arrViewers;
		arrViewers = tmp;
	} else {
		arrViewers[index].counterViewer++;
	}
}

int School::SeachViewers(char* name) {
	int index = -1;

	for (int i = 0; i < counterViewers; i++) {
		if (strcmp(arrViewers[i].Name.str, name) == 0) 
			index = i;	
	}
	return index;
}

void School::RemakeWord() {
	int password1 = 0;
	char tmp[100];
	do {
		cout << "Введите пароль: ";
		cin >> password1;

		if (password1 != password) {
			cout << "Пароль неверный! \n";

			if (password1 == 1) {
				cout << "Введите новое слово: " << endl;
				cin.ignore();
				cin.getline(tmp, 100);
				secretWord.setMyString(tmp);

				cout << "ВАШЕ НОВОЕ СЛОВО: " << secretWord.str << endl;
				Sleep(3500);
			}
				
		}
	} while (password1 != password);
}

void School::PrintClassRoom() {
	cout << "- Школа: " << title.str << endl;

	for (int i = 0; i < counterClass; i++) {
		arrClass[i].PrintClass();
		cout << endl;
	}
}

void School::PrintTeacher() {
	cout << "- Школа: " << title.str << endl;

	for (int i = 0; i < counterTeacher; i++)
		arrTeacher[i].PrintTeacher();
}

void School::deleteViewers() {
	char tmp1[100];
	cout << "Введите имя: ";
	cin.ignore();
	cin.getline(tmp1, 100);

	int index = SeachViewers(tmp1);

	if (index == -1) 
		cout << "Пользователь не найден! " << endl;
	else {
		Viewers* tmp = new Viewers[--counterViewers];

		for (int i = 0, j = 0; i < counterViewers + 1; i++) {
			if (index == i)
				continue;
			tmp[j++] = arrViewers[i];
		}

		if (arrViewers != NULL) delete[] arrViewers;

		arrViewers = tmp;
	}
}

void School::PrintViewers() {
	for (int i = 0; i < counterViewers; i++)
		arrViewers[i].PrintViewer();
	cout << endl;
}

void School::addTeacher() {
	teacher* tmp = new teacher[++counterTeacher];

	if (counterTeacher - 1 == 0)
		tmp[counterTeacher - 1].CreateTeacher();
	else {
		for (int i = 0; i < counterTeacher - 1; i++)
			tmp[i] = arrTeacher[i];


		tmp[counterTeacher - 1].CreateTeacher();
	}


	if (arrTeacher != NULL) delete[] arrTeacher;

	arrTeacher = tmp;
}

int School::SeacrhTeacher() {
	int index = -1;

	if (counterTeacher == 0)
		cout << "Учителей не найденно... \n";
	else {
		for (int i = 0; i < counterTeacher; i++)
			cout << i + 1 << ": " << arrTeacher[i].Name.str << " " << arrTeacher[i].MiddleName.str << endl;

		cout << "Введите номер: ";
		cin >> index;

		index--;
	}

	return index;
}

void School::deleteTeacher() {
	int index = SeacrhTeacher();

	if (index == -1)
		return;
	else {
		teacher* tmp = new teacher[--counterTeacher];

		for (int i = 0, j = 0; i < counterTeacher+1; i++) {
			if (i == index)
				continue;
			tmp[j++] = arrTeacher[i];
		}

		if (arrTeacher != NULL) delete[] arrTeacher;

		arrTeacher = tmp;
	}
}

void School::RemakeTeacher() {
	int index = SeacrhTeacher();

	if (index == -1)
		return;
	else
		arrTeacher[index].RemakeTeacher();

}

void School::addClass() {
	ClassRoom* tmp = new ClassRoom[++counterClass];

	if (counterClass - 1 == 0)
		tmp[counterClass - 1].CreateClass();
	else {
		for (int i = 0; i < counterClass - 1; i++)
			tmp[i] = arrClass[i];
		tmp[counterClass - 1].CreateClass();
	}

	if (arrClass != NULL) delete[] arrClass;

	arrClass = tmp;
}

void School::SortTeacher() {
	teacher tmp;

	for (int i = 0; i < counterTeacher - 1; i++) {
		for (int j = 0; j < counterTeacher - 1; j++) {
			if (arrTeacher[j].yearWorked < arrTeacher[j + 1].yearWorked) {
				tmp = arrTeacher[j + 1];
				arrTeacher[j] = arrTeacher[j + 1];
				arrTeacher[j + 1] = tmp;
			}
		}
	}
}

int School::SeacrhClass() {
	int index = -1;

	for (int i = 0; i < counterClass; i++)
		cout << i + 1 << ": " << arrClass[i].NumberClass.str << endl;

	cout << "Введите класс: ";
	cin >> index;

	index--;

	return index;
}

void School::deleteClass() {
	int index = SeacrhClass();

	if (index == -1)
		return;
	else {
		ClassRoom* tmp = new ClassRoom[--counterClass];

		for (int i = 0, j = 0; i < counterClass + 1; i++) {
			if (i == index)
				continue;
			tmp[j++] = arrClass[i];
		}

		if (arrClass != NULL) delete[] arrClass;

		arrClass = tmp;
	}
}

void School::RemakeClass() {
	int index = SeacrhClass();

	if (index == -1)
		return;
	else
		arrClass[index].RemakeClass();
}

void School::AddSubject(int index) {
	arrClass[index].addSubject();
}

void School::SortSubject(int index) {
	arrClass[index].SortSubject();
}

void School::deleteSubject(int index) {
	arrClass[index].deletePuple();
}

void School::RemakeSubject(int index) {
	arrClass[index].RemakePuple();
}

void School::printSubject(int index) {
	arrClass[index].PrintSubjectClass();
}

void School::AddPuple(int index) {
		arrClass[index].addPuple();
}

void School::deletePuple(int index) {
	if (index == -1)
		return;
	else
		arrClass[index].deletePuple();
}

void School::RemakePuple(int index) {
	if (index == -1)
		return;
	else
		arrClass[index].RemakePuple();
}

void School::PrintPuple(int index) {
	cout << "Школа: " << title.str << endl;
	for (int i = 0; i < arrClass[index].counterPuple; i++) {
		arrClass[index].arrPuple[i].PrintPuple();
	}
	cout << endl;
}

void School::SaveAllBin(FILE* a) {
	SaveClassBin(a);
	SaveTeacherBin(a);
	SaveSetting(a);
	SaveViewers(a);
}

void School::SaveTeacherBin(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Teacher.bin", "wb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {
		fwrite(&counterTeacher, sizeof(int), 1, a);

		for (int i = 0; i < counterTeacher; i++)
			arrTeacher[i].SaveBinTeacher(a);

		fclose(a);
	}
}

void School::SaveClassBin(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Class.bin", "wb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {
		fwrite(&counterClass, sizeof(int), 1, a);

		for (int i = 0; i < counterClass; i++)
			arrClass[i].SaveBinClass(a);

		fclose(a);
	}

}

void School::SaveSetting(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Setting.bin", "wb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {

		fwrite(&title.length, sizeof(int), 1, a);
		fwrite(title.str, sizeof(char), title.length, a);

		fwrite(&pincode, sizeof(bool), 1, a);

		fwrite(&password, sizeof(int), 1, a);

		fwrite(&secretWord.length, sizeof(int), 1, a);
		fwrite(secretWord.str, sizeof(char), secretWord.length, a);

		fclose(a);
	}

}

void School::SaveViewers(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Viewers.bin", "wb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {

		fwrite(&counterViewers, sizeof(int), 1, a);

		for (int i = 0; i < counterViewers; i++)
			arrViewers[i].SaveViewersToBinFile(a);

		fclose(a);
	}
}

void School::SortPuple(int index) {
	arrClass[index].SortPuple();
}

void School::LoadAllDin(FILE* a) {
	LoadClassBin(a);
	LoadTeacherBin(a);
	LoadSetting(a);
	LoadViewers(a);
}

void School::LoadClassBin(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Class.bin", "rb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {
		fread(&counterClass, sizeof(int), 1, a);
		arrClass = new ClassRoom[counterClass];

		for (int i = 0; i < counterClass; i++)
			arrClass[i].LoadBinClass(a);

		fclose(a);
	}

}

void School::LoadTeacherBin(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Teacher.bin", "rb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {
		fread(&counterTeacher, sizeof(int), 1, a);
		arrTeacher = new teacher[counterTeacher];

		for (int i = 0; i < counterTeacher; i++)
			arrTeacher[i].LoadBinTeacher(a);

		fclose(a);
	}
}

bool School::CheeckMD() {
	WIN32_FIND_DATA FindFileData;
	//текущая директория 
	HANDLE hf = FindFirstFile("*", &FindFileData);

	INT i = 0;
	bool Seacrh = false;
	if (hf == INVALID_HANDLE_VALUE) {
		puts("Path not found");
		return false;
	}
	do {
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY
			&& !(strcmp(FindFileData.cFileName, ".") == 0)
			&& !(strcmp(FindFileData.cFileName, "..") == 0)) {
			if (strcmp(FindFileData.cFileName, "DataFiles") == 0) {
				Seacrh = true;
				return  true;
			}
		}
	} while (FindNextFile(hf, &FindFileData));
	FindClose(hf);

	if (!Seacrh)
		system("md DataFiles");
	return false;
}

void School::LoadViewers(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Viewers.bin", "rb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {

		fread(&counterViewers, sizeof(int), 1, a);
		arrViewers = new Viewers[counterViewers];

		for (int i = 0; i < counterViewers; i++)
			arrViewers[i].LoadViewersFromBinFile(a);

		fclose(a);
	}
}

void School::LoadSetting(FILE* a) {
	CheeckMD();
	fopen_s(&a, "DataFiles\\Setting.bin", "rb");

	if (a == NULL)
		cout << "Erorr: FILE DONT OPEN \n";
	else {

		fread(&title.length, sizeof(int), 1, a);
		title.str = new char[title.length];
		fread(title.str, sizeof(char), title.length, a);

		fread(&pincode, sizeof(bool), 1, a);

		fread(&password, sizeof(int), 1, a);

		fread(&secretWord.length, sizeof(int), 1, a);
		secretWord.str = new char[secretWord.length];
		fread(secretWord.str, sizeof(char), secretWord.length, a);

		fclose(a);
	}

}
