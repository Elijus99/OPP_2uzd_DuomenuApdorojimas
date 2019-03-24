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

void ivedimas(string &GType, std::deque<stud> &ls, int &VSize, int &PSize);
double galutinis(int egzaminas, string GType, int n, std::vector<int> nd);
bool exist(const char *fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::deque<stud> &ls);
std::deque<stud> iterpkKietus(std::deque<stud>& ls);
void OutputToFiles(std::deque<stud> &ls, std::deque<stud> minksti, string GType, int VSize, int PSize);

#endif