#include "functions.h"
#include "libraries.h"
#include <limits>
#include <random>
#include <algorithm>
#include <cfloat>
#include <fstream>

void ivedimas(string &GType, std::list<stud> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1)
{
	bool valid_input = false;
	int N;
	string choice;
	do {
		cout << "Ka norite naudoti galutinio balo skaiciavimui: vidurki ar mediana? (Iveskite 'v' arba 'm')" << endl;
		cin >> GType;
		if (GType == "v" || GType == "V" || GType == "M" || GType == "m") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (GType != "v" || GType != "V" || GType != "M" || GType != "m");
	string choose;
	int chooseN;
	do {
		cout << "Ar norite sugeneruoti studentu saraso faila ? (y/n)" << endl;
		cin >> choose;
		if (choose == "y" || choose == "Y" || choose == "N" || choose == "n") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (choose != "y" || choose != "Y" || choose != "N" || choose != "n");
	if (choose == "y" || choose == "Y") {
		do {
			cout << "Kiek irasu faile norite generuoti? " << endl;
			cin >> chooseN;
			if (!(valid_input = cin.good())) {
				cout << "That input is invalid!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (!valid_input);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		string name = "StudentList" + std::to_string(chooseN) + ".txt";
		auto start = std::chrono::high_resolution_clock::now();
		generate(chooseN, name, GType, ls);
		auto end = std::chrono::high_resolution_clock::now();
		diff1 = end - start;
	}

	do {
		cout << "Ar norite nuskaityti duomenis is failo 'kursiokai.txt'? (y/n)" << endl;
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "N" || choice == "n") {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (choice != "y" || choice != "Y" || choice != "N" || choice != "n");
	string fileName = "StudentList100000.txt";
	if (choice == "y" || choice == "Y") {
		InputFromFiles(choice, fileName, VSize, PSize, ls, GType);
	}
	do {
		cout << "Keliu studentu duomenis norite irasyti?" << endl;
		cin >> N;
		if (!(valid_input = cin.good())) {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input);
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int egzaminas;
	int j, temp;
	int SIZE = ls.size();
	std::list<stud>::iterator it = ls.begin();
	for (int i = SIZE; i < (N + SIZE); i++)
	{
		ls.push_back(stud());
		cout << "Iveskite " << i + 1 << "-o studento varda" << endl;
		cin >> it->vard;
		if (VSize < it->vard.size()) {
			VSize = it->vard.size();
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Iveskite " << i + 1 << "-o studento pavarde" << endl;
		cin >> it->pav;
		if (PSize < it->pav.size()) {
			PSize = it->pav.size();
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		choice = 'x';
		do {
			cout << "Ar norite pazymius bei egzamino rezultata ivesti, ar juos sugeneruoti automatiskai? (Iveskite 'i' arba 'g')" << endl;
			cin >> choice;
			if (choice == "i" || choice == "I" || choice == "G" || choice == "g") {
				break;
			}
			else {
				cout << "That input is invalid!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (choice != "i" || choice != "I" || choice != "G" || choice != "g");

		it->n = 0;
		j = 0;
		if (choice == "i" || choice == "I") {
			while (true) {
				try {
					do {
						cout << "Iveskite " << j + 1 << "-o namu darbo rezultata (Iveskite -1, kai noresite uzbaigti rezultatu vedima)" << endl;
						cin >> temp;
						if (temp == -1) {
							throw - 1;
						}
						if (temp > -1 && temp < 11 && cin.fail() == false) {
							(it->nd).push_back(temp);
							it->n++;
							j++;
						}
						if (!(valid_input = cin.good())) {
							cout << "That input is invalid!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						else if (temp > 10 || temp < -1) {
							cout << "That input is invalid!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							valid_input = false;
						}
					} while (!valid_input);
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				catch (...) {
					cout << "Homework input operation has been stopped!" << endl;
					break;
				}
			}

			do {
				cout << "Iveskite studento egzamino rezultata" << endl;
				cin >> egzaminas;
				if (!(valid_input = cin.good())) {
					cout << "That input is invalid!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			} while (!valid_input);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			cout << "Kiek pazymiu norite sugeneruoti?" << endl;
			cin >> it->n;
			cout << "Sugeneruoti pazymiai: ";
			for (int j = 0; j < it->n; j++)
			{
				(it->nd).push_back(RandomNumber());
				cout << it->nd[j] << " ";
			}
			egzaminas = RandomNumber();
			cout << endl;
			cout << "Egzamino rezultatas: " << egzaminas;
			cout << endl;
		}
		it->galutinis = galutinis(egzaminas, GType, it->n, it->nd);
		std::advance(it, 1);
		cout << endl;
	}
}

double galutinis(int egzaminas, string GType, int n, std::vector<int> nd)
{
	double vidurkis = 0;
	for (int j = 0; j < n; j++)
	{
		vidurkis += nd[j];
	}
	vidurkis = division(vidurkis, n);
	std::sort(nd.begin(), nd.end());
	double mediana;
	if (n > 0) {
		if (n % 2 == 1) {
			mediana = nd[n / 2];
		}
		else {
			mediana = (double)(nd[n / 2 - 1] + nd[n / 2]) / 2;
		}
	}
	else {
		mediana = 0;
	}
	double galutinis;
	if (GType == "v" || GType == "V") {
		galutinis = 0.4 * vidurkis + 0.6 * egzaminas;
	}
	else if (GType == "m" || GType == "M") {
		galutinis = 0.4 * mediana + 0.6 * egzaminas;
	}
	return galutinis;
}

void isvedimas(std::list<stud> vargs, std::list<stud> kiet, int VSize, int PSize, string GType)
{
	cout << "Vardas";
	for (int i = 0; i < VSize; i++)
	{
		cout << " ";
	}
	cout << "Pavarde";
	for (int i = 0; i < PSize; i++)
	{
		cout << " ";
	}
	if (GType == "V" || GType == "v") {
		cout << "Galutinis (Vid.)" << endl;
	}
	else {
		cout << "Galutinis (Med.)" << endl;
	}
	for (int i = 0; i < PSize + VSize + 29; i++)
	{
		cout << "-";
	}
	cout << endl;
	std::list<stud>::iterator it = kiet.begin();
	for (int i = 0; i < kiet.size(); i++)
	{
		cout << std::left << setw(VSize + 6) << it->vard << setw(PSize + 7) << it->pav << std::fixed << setprecision(2) << it->galutinis << endl;
		std::advance(it, 1);
	}
	it = vargs.begin();
	for (int i = 0; i < vargs.size(); i++)
	{
		cout << std::left << setw(VSize + 6) << it->vard << setw(PSize + 7) << it->pav << std::fixed << setprecision(2) << it->galutinis << endl;
		std::advance(it, 1);
	}
}

bool exist(string fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
};
bool compareAlphabet(const stud& a, const stud& b)
{
	return a.vard < b.vard;
};
double division(int a, int b)
{
	if (b == 0) {
		return 0;
	}
	return ((double)a / b);
}
int RandomNumber()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution <int> gen(1, std::nextafter(10, DBL_MAX));
	return gen(mt);
}

void generate(int n, string OutputFileName, string GType, std::list<stud> &ls)
{
	int egzaminas;
	stud student;
	std::ofstream out(OutputFileName);
	if (GType == "V" || GType == "v") {
		out << "Vardas          " << "Pavarde          " << "ND1   " << "ND2   " << "ND3   " << "ND4   " << "ND5   " << "Galutinis (Vid.)" << endl;
	}
	else {
		out << "Vardas          " << "Pavarde          " << "ND1   " << "ND2   " << "ND3   " << "ND4   " << "ND5   " << "Galutinis (Med.)" << endl;
	}
	out << endl;
	for (int i = 0; i < n; i++)
	{
		student.vard = "Vardas" + std::to_string(i + 1);
		student.pav = "Pavarde" + std::to_string(i + 1);
		for (int j = 0; j < 5; j++)
		{
			(student.nd).push_back(RandomNumber());
		}
		egzaminas = RandomNumber();
		student.galutinis = galutinis(egzaminas, GType, 5, student.nd);
		ls.push_back(student);
		out << std::left << setw(16) << student.vard << std::left << setw(17) << student.pav << std::left << setw(6) << student.nd[0] << std::left << setw(6) << student.nd[1] << std::left << setw(6) << student.nd[2] << std::left << setw(6) << student.nd[3] << std::left << setw(6) << student.nd[4] << std::fixed << setprecision(2) << student.galutinis << endl;
		(student.nd).clear();
	}
}
void SortToGroups(std::list<stud> &ls, std::list<stud> &vargs, std::list<stud> &kiet)
{
	std::list<stud>::iterator it = ls.begin();
	for (int i = 0; i < ls.size(); i++)
	{
		if (it->galutinis < 5.0) {
			vargs.push_back({ it->vard, it->pav, it->n, it->nd, it->galutinis });
		}
		else {
			kiet.push_back({ it->vard, it->pav, it->n, it->nd, it->galutinis });
		}
		std::advance(it, 1);
	}

}
void InputFromFiles(string choice, string fileName, int &VSize, int &PSize, std::list<stud> &ls, string GType)
{
	if (exist(fileName)) {
		std::ifstream in(fileName);
		in.ignore(10000, '\n');
		string vard, pav;
		std::vector<int> nd;
		double egzaminas, gal;
		int n = 5, j = 0;
		int temp;
		while (in >> vard >> pav) {
			if (VSize < vard.size()) {
				VSize = vard.size();
			}
			if (PSize < pav.size()) {
				PSize = pav.size();
			}
			nd.clear();
			for (int i = 0; i < n; i++)
			{
				in >> temp;
				nd.push_back(temp);
			}
			in >> egzaminas;
			gal = galutinis(egzaminas, GType, n, nd);
			ls.push_back({ vard, pav, n, nd, gal });
		}
		cout << "---Duomenys nuskaityti!---" << endl;
	}
	else {
		cout << "---Failas 'kursiokai.txt' nebuvo rastas---" << endl;
	}
}
void OutputToFiles(std::list<stud> kiet, std::list<stud> vargs, string GType, int VSize, int PSize)
{
	std::ofstream outToK("kietiakai.txt");
	std::ofstream outToV("vargsiukai.txt");
	outToK << "Vardas";
	outToV << "Vardas";
	for (int i = 0; i < VSize; i++)
	{
		outToK << " ";
		outToV << " ";
	}
	outToK << "Pavarde";
	outToV << "Pavarde";
	for (int i = 0; i < PSize; i++)
	{
		outToK << " ";
		outToV << " ";
	}
	if (GType == "V" || GType == "v") {
		outToK << "Galutinis (Vid.)" << endl;
		outToV << "Galutinis (Vid.)" << endl;
	}
	else {
		outToK << "Galutinis (Med.)" << endl;
		outToV << "Galutinis (Med.)" << endl;
	}
	for (int i = 0; i < PSize + VSize + 29; i++)
	{
		outToK << "-";
		outToV << "-";
	}
	outToK << endl;
	outToV << endl;
	std::list<stud>::iterator it = vargs.begin();
	for (int i = 0; i < vargs.size(); i++)
	{
		outToV << std::left << setw(VSize + 6) << it->vard << setw(PSize + 7) << it->pav << std::fixed << setprecision(2) << it->galutinis << endl;
		std::advance(it, 1);
	}
	it = kiet.begin();
	for (int i = 0; i < kiet.size(); i++)
	{
		outToK << std::left << setw(VSize + 6) << it->vard << setw(PSize + 7) << it->pav << std::fixed << setprecision(2) << it->galutinis << endl;
		std::advance(it, 1);
	}
}