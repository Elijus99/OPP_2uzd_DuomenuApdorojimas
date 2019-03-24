#include "functions.h"
#include "libraries.h"
#include <algorithm>
#include <chrono>

int main()
{
	int VSize = 10, PSize = 10;
	string GType{"v"};
	std::deque<stud> ls;
	ivedimas(GType, ls, VSize, PSize);
	auto start = std::chrono::high_resolution_clock::now();
	std::deque<stud> minksti = iterpkKietus(ls);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::sort(ls.begin(), ls.end(), compareAlphabet);
	std::sort(minksti.begin(), minksti.end(), compareAlphabet);
	OutputToFiles(ls, minksti, GType, VSize, PSize);
	cout << "IterpkKietus funkcija uztruko: " << setprecision(10) << diff.count() << " s" << endl;
	system("pause");
	return 0;
}