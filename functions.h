#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "libraries.h"

struct stud {
	string vard;
	string pav;
	int n;
	std::vector<int> nd;
	double galutinis;
	string group;
};

void ivedimas(string &GType, std::vector<stud> &ls, int &VSize, int &PSize);
double galutinis(int egzaminas, string GType, int n, std::vector<int> nd);
void isvedimas(std::vector<stud> ls, int VSize, int PSize, string GType);
bool exist(const char *fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::vector<stud> &ls);
void SortToGroups(std::vector<stud> &ls);
void OutputToFiles(std::vector<stud> &ls, string GType, int VSize, int PSize);

#endif