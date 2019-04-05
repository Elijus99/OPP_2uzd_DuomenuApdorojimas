#include "functions.h"
#include "libraries.h"
#include <algorithm>

int main()
{
	int VSize = 10, PSize = 10;
	string GType{};
	std::deque<stud> ls;
	std::chrono::duration<double> diff1;
	ivedimas(GType, ls, VSize, PSize, diff1);
	auto start = std::chrono::high_resolution_clock::now();
	SortToGroups(ls);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end - start;
	std::sort(ls.begin(), ls.end(), compareAlphabet);
	isvedimas(ls, VSize, PSize, GType);
	OutputToFiles(ls, GType, VSize, PSize);
	cout << "Duomenu nuskaitymas is failu uztruko: " << std::fixed << setprecision(4) << diff1.count() << " s" << endl;
	cout << "Studentu rusiavimas i grupes uztruko: " << std::fixed << setprecision(4) << diff2.count() << " s" << endl;
	system("pause");
	return 0;
}