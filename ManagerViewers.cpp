#include "ManagerViewers.h"

void Viewers::CreateViewer() {
	cout << "¬ведите дату захода: " << endl;
//	Day.fillDate();
	Day.getNowDate();

	
}

void Viewers::PrintViewer() {
	cout << " - " << Name.str << " " << Day.toString() << ", " << counterViewer << endl;
}

void Viewers::SaveViewersToBinFile(FILE* a) {
	fwrite(&Name.length, sizeof(int), 1, a);
	fwrite(Name.str, sizeof(char), Name.length, a);

	fwrite(&Day.year, sizeof(int), 1, a);
	fwrite(&Day.month, sizeof(int), 1, a);
	fwrite(&Day.day, sizeof(int), 1, a);

	fwrite(&counterViewer, sizeof(int), 1, a);
}

void Viewers::LoadViewersFromBinFile(FILE* a) {
	fread(&Name.length, sizeof(int), 1, a);
	Name.str = new char[Name.length];
	fread(Name.str, sizeof(char), Name.length, a);

	fread(&Day.year, sizeof(int), 1, a);
	fread(&Day.month, sizeof(int), 1, a);
	fread(&Day.day, sizeof(int), 1, a);

	fread(&counterViewer, sizeof(int), 1, a);
}
