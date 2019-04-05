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

void ivedimas(string &GType, std::deque<stud> &ls, int &VSize, int &PSize, std::chrono::duration<double> &diff);
double galutinis(int egzaminas, string GType, int n, std::vector<int> nd);
void isvedimas(std::deque<stud> ls, int VSize, int PSize, string GType);
bool exist(string fileName);
bool compareAlphabet(const stud& a, const stud& b);
double division(int a, int b);
int RandomNumber();
void generate(int n, string OutputFileName, string GType, std::deque<stud> &ls);
void SortToGroups(std::deque<stud> &ls);
void InputFromFiles(string choice, string fileName, int &VSize, int &PSize, std::deque<stud> &ls, string GType);
void OutputToFiles(std::deque<stud> &ls, string GType, int VSize, int PSize);

#endif