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

void ivedimas(string &GType, std::list<stud> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff1);
double galutinis(int egzaminas, string GType, int n, std::vector<int> nd);
void isvedimas(std::list<stud> vargs, std::list<stud> kiet, int VSize, int PSize, string GType);
bool exist(string fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::list<stud> &ls);
void SortToGroups(std::list<stud> &ls, std::list<stud> &vargs, std::list<stud> &kiet);
void InputFromFiles(string choice, string fileName, int &VSize, int &PSize, std::list<stud> &ls, string GType);
void OutputToFiles(std::list<stud> kiet, std::list<stud> vargs, string GType, int VSize, int PSize);

#endif