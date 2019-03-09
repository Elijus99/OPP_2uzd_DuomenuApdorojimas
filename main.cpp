#include "functions.h"
#include "libraries.h"
#include <algorithm>
#include <chrono>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	int VSize = 10, PSize = 10;
	string GType{"v"};
	std::deque<stud> ls, vargs;
	ivedimas(GType, ls, VSize, PSize);
	std::sort(ls.begin(), ls.end(), compareAlphabet);
	isvedimas(ls, VSize, PSize, GType);
	SortToGroups(ls, vargs);
	OutputToFiles(ls, vargs, GType, VSize, PSize);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Programos veikimas uztruko: " << diff.count() << " s" << endl;
	system("pause");
	return 0;
}