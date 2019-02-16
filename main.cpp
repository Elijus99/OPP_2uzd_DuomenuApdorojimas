#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <random>
#include <vector>
#include <algorithm>

using std::cin;
using std::string;
using std::endl;
using std::cout;
using std::setprecision;
using std::setw;

struct stud {
	string vard;
	string pav;
	int n;
	std::vector<int> nd;
	double galutinis;
};

void ivedimas(char &GType, std::vector<stud> &ls, int &VSize, int &PSize);
void rikiavimas(std::vector<int> x[], int n);
void isvedimas(std::vector<stud> ls, int VSize, int PSize, char GType);

int main()
{
	int VSize = 10, PSize = 10;
	char GType{};
	std::vector<stud> ls;
	ivedimas(GType, ls, VSize, PSize);
	isvedimas(ls, VSize, PSize, GType);
	system("pause");
	return 0;
}

void rikiavimas(std::vector<int> x[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (x[j] < x[i]) {
				std::swap(x[i], x[j]);
			}
		}
	}
}


void ivedimas(char &GType, std::vector<stud> &ls, int &VSize, int &PSize)
{
	bool valid_input = false;
	int N;

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

	do {
		cout << "Ka norite naudoti galutinio balo skaiciavimui: vidurki ar mediana? (Iveskite 'v' arba 'm')" << endl;
		cin >> GType;
		if (GType == 'v' || GType == 'V' || GType == 'M' || GType == 'm') {
			break;
		}
		else {
			cout << "That input is invalid!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (GType != 'v' || GType != 'V' || GType != 'M' || GType != 'm');

	double vidurkis, egzaminas, mediana;
	char choice;
	int j, temp;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution <int> gen(1, std::nextafter(10, DBL_MAX));
	for (int i = 0; i < N; i++)
	{
		ls.push_back(stud());
		cout << "Iveskite " << i + 1 << "-o studento varda" << endl;
		cin >> ls[i].vard;
		if (VSize < ls[i].vard.size()) {
			VSize = ls[i].vard.size();
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Iveskite " << i + 1 << "-o studento pavarde" << endl;
		cin >> ls[i].pav;
		if (PSize < ls[i].pav.size()) {
			PSize = ls[i].pav.size();
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		choice = 'x';
		do {
			cout << "Ar norite pazymius bei egzamino rezultata ivesti, ar juos sugeneruoti automatiskai? (Iveskite 'i' arba 'g')" << endl;
			cin >> choice;
			if (choice == 'i' || choice == 'I' || choice == 'G' || choice == 'g') {
				break;
			}
			else {
				cout << "That input is invalid!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		} while (choice != 'i' || choice != 'I' || choice != 'G' || choice != 'g');

		ls[i].n = 0;
		j = 0;
		if (choice == 'i' || choice == 'I') {
			do {
				do {
					cout << "Iveskite " << j + 1 << "-o namu darbo rezultata (Iveskite -1, kai noresite uzbaigti rezultatu vedima)" << endl;
					cin >> temp;
					if (temp > -1 && temp < 11 && cin.fail() == false) {
						(ls[i].nd).push_back(temp);
						ls[i].n++;
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
			} while (temp != -1);
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
			cin >> ls[i].n;
			cout << "Sugeneruoti pazymiai: ";
			for (int j = 0; j < ls[i].n; j++)
			{
				(ls[i].nd).push_back(gen(mt));
				cout << ls[i].nd[j] << " ";
			}
			egzaminas = gen(mt);
			cout << endl;
			cout << "Egzamino rezultatas: " << egzaminas;
			cout << endl;
		}

		vidurkis = 0;
		for (int j = 0; j < ls[i].n; j++)
		{
			vidurkis += ls[i].nd[j];
		}
		if (ls[i].n == 0) {
			vidurkis = 0;
		}
		else {
			vidurkis /= ls[i].n;
		}
		std::sort(ls[i].nd.begin(), ls[i].nd.end());
		if (ls[i].n > 0) {
			if (ls[i].n % 2 == 1) {
				mediana = ls[i].nd[ls[i].n / 2];
			}
			else {
				mediana = (double)(ls[i].nd[ls[i].n / 2 - 1] + ls[i].nd[ls[i].n / 2]) / 2;
			}
		}
		else {
			mediana = 0;
		}

		if (GType == 'v') {
			ls[i].galutinis = 0.4 * vidurkis + 0.6 * egzaminas;

		}
		else if (GType == 'm') {
			ls[i].galutinis = 0.4 * mediana + 0.6 * egzaminas;

		}
		cout << endl;
	}
}

void isvedimas(std::vector<stud> ls, int VSize, int PSize, char GType)
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
	if (GType == 'V' || GType == 'v') {
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
	for (int i = 0; i < ls.size(); i++)
	{
		cout << std::left << setw(VSize + 6) << ls[i].vard << setw(PSize + 7) << ls[i].pav << setprecision(3) << ls[i].galutinis << endl;
	}
}