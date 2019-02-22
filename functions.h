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
};

void ivedimas(string &GType, std::vector<stud> &ls, int &VSize, int &PSize);
double galutinis(double egzaminas, string GType, int n, std::vector<int> nd);
void isvedimas(std::vector<stud> ls, int VSize, int PSize, string GType);
bool exist(const char *fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);

#endif