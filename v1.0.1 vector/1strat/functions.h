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

void ivedimas(string &GType, std::vector<stud> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1);
double galutinis(int egzaminas, string GType, int n, std::vector<int> nd);
void isvedimas(std::vector<stud> ls, int VSize, int PSize, string GType);
bool exist(string fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::vector<stud> &ls);
void SortToGroups(std::vector<stud> &ls, std::vector<stud> &vargs, std::vector<stud> &kiet);
void InputFromFiles(string fileName, int &VSize, int &PSize, std::vector<stud> &ls, string GType);
void OutputToFiles(std::vector<stud> kiet, std::vector<stud> vargs,string GType, int VSize, int PSize);

#endif