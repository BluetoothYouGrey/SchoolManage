#include "ClassRoom.h"

void ClassRoom::CreateClass() {
	char tmp[100];

	cout << "Введите название класса: ";
	cin.ignore();
	cin.getline(tmp, 100);
	NumberClass.setMyString(tmp);

}


void ClassRoom::PrintClass() {
	cout << " - Название класса: " << NumberClass.str << endl;

	if (counterPuple == 0) 
		cout << "  - Класс пустой... \n";
	else {
		for (int i = 0; i < counterPuple; i++) {
			arrPuple[i].PrintPuple();
		}
	}
}

void ClassRoom::PrintSubjectClass() {
	cout << "- Название класса: " << NumberClass.str << endl;

	if (counterPuple == 0)
		cout << "  - Класс пустой... \n";
	else {
		for (int i = 0; i < counterSubject; i++) {
			arrSubject[i].PrintSubject();
		}
	}
}

void ClassRoom::RemakeClass() {
	char tmp[100];

	cout << "Введите новое название класса: ";
	cin.ignore();
	cin.getline(tmp, 100);
	NumberClass.setMyString(tmp);
}

void ClassRoom::deleteClass() {
	counterPuple = 0;
	counterSubject = 0;

	delete[] arrPuple;
	delete[] arrSubject;
}

void ClassRoom::addPuple() {
	Puple* tmp = new Puple[++counterPuple];

	if (counterPuple - 1 == 0)
		tmp[counterPuple - 1].CreatePuple();
	else {
		for (int i = 0; i < counterPuple - 1; i++) {
			tmp[i] = arrPuple[i];
		}

		tmp[counterPuple - 1].CreatePuple();
	}

	if (arrPuple != NULL) delete[] arrPuple;

	arrPuple = tmp;
}

int ClassRoom::SeacrhPuple() {
	if (counterPuple == 0) 
		cout << "В классе нету учеников... \n";
	else {
		int tmp = 0;
		for (int i = 0; i < counterPuple; i++) {
			cout << i + 1 << ": " << arrPuple[i].Name.str << " " << arrPuple[i].Surname.str << endl;
		}
		cout << "Введите нужного ученика: ";
		cin >> tmp;

		tmp--;

		return tmp;
	}

	return -1;
}

void ClassRoom::deletePuple() {
	int index = SeacrhPuple();

	if (index == -1)
		return;
	else {
		Puple* tmp = new Puple[--counterPuple];

		for (int i = 0, j = 0; i < counterPuple + 1; i++) {
			if (i == index)
				continue;
			tmp[j++] = arrPuple[i];
		}

		if (arrPuple != NULL) delete[] arrPuple;

		arrPuple = tmp;
	}
}

void ClassRoom::RemakePuple() {
	int index = SeacrhPuple();

	if (index == -1)
		return;
	else
		arrPuple[index].RemakePuple();
}

void ClassRoom::SortPuple() {
	Puple tmp;

	for (int i = 0; i < counterPuple - 1; i++) {
		for (int j = 0; j < counterPuple - 1; j++) {
			if (strcmp(arrPuple[j].Name.str, arrPuple[j + 1].Name.str) > 0) {
				tmp = arrPuple[j + 1];
				arrPuple[j] = arrPuple[j + 1];
				arrPuple[j + 1] = tmp;
			}
		}
	}
}

void ClassRoom::addSubject() {
	Subject* tmp = new Subject[++counterSubject];

	if (counterSubject - 1 == 0) 
		tmp[counterSubject - 1].CreateSubject();
	else {
		for (int i = 0; i < counterSubject - 1; i++) 
			tmp[i] = arrSubject[i];
		tmp[counterSubject - 1].CreateSubject();
	}

	if (arrSubject != NULL) arrSubject;

	arrSubject = tmp;
}

int ClassRoom::SeacrhSubject() {
	int index = -1;

	if (counterSubject == 0) 
		cout << "Предметов в данном классе не найденно... " << endl;
	else {
		for (int i = 0; i < counterPuple; i++) 
			cout << i + 1 << ": " << arrSubject[i].title.str << endl;
		cout << "Введите нужный вам предмет: ";
		cin >> index;
		index--;
	}

	return index;
}

void ClassRoom::deleteSubject() {
	int index = SeacrhSubject();

	if (index == -1)
		return;
	else {
		Subject* tmp = new Subject[--counterSubject];

		for (int i = 0, j = 0; i < counterSubject + 1; i++) {
			if (i == index)
				continue;
			tmp[j++] = arrSubject[i];
		}

		if (arrSubject != NULL) delete[] arrSubject;

		arrSubject = tmp;
	}
}

void ClassRoom::RemakeSubject() {
	int index = SeacrhPuple();

	if (index == -1)
		return;
	else
		arrSubject[index].RemakeSubject();
}

void ClassRoom::SortSubject() {
	Subject tmp;
	for (int i = 0; i < counterSubject - 1; i++) {
		for (int j = 0; j < counterSubject - 1; j++) {			
			if (strcmp(arrSubject[j].title.str, arrSubject[j + 1].title.str) > 0) {
				tmp = arrSubject[j + 1];
				arrSubject[j] = arrSubject[j + 1];
				arrSubject[j + 1] = tmp;
			}		
		}
	}
}

void ClassRoom::SaveBinClass(FILE* a) {
	fwrite(&counterPuple, sizeof(int), 1, a);
	fwrite(&counterSubject, sizeof(int), 1, a);

	fwrite(&NumberClass.length, sizeof(char), 1, a);
	fwrite(NumberClass.str, sizeof(char), NumberClass.length, a);

	for (int i = 0; i < counterPuple; i++) 
		arrPuple[i].SaveBinPuple(a);
	
	for (int i = 0; i < counterSubject; i++) 
		arrSubject[i].SaveBinSubject(a);
}

void ClassRoom::LoadBinClass(FILE* a) {
	fread(&counterPuple, sizeof(int), 1, a);
	arrPuple = new Puple[counterPuple];

	fread(&counterSubject, sizeof(int), 1, a);
	arrSubject = new Subject[counterSubject];

	fread(&NumberClass.length, sizeof(char), 1, a);
	NumberClass.str = new char[NumberClass.length];
	fread(NumberClass.str, sizeof(char), NumberClass.length, a);

	for (int i = 0; i < counterPuple; i++) 
		arrPuple[i].LoadBinPuple(a);
	
	for (int i = 0; i < counterSubject; i++)
		arrSubject[i].LoadBinSubject(a);
}
