#include "functions.h"
#include "libraries.h"
#include <algorithm>

int main()
{
	int VSize = 10, PSize = 10;
	string GType{"v"};
	std::vector<stud> ls, vargs;
	std::chrono::duration<double> diff1 = {};
	ivedimas(GType, ls, VSize, PSize, diff1);
	auto start = std::chrono::high_resolution_clock::now();
	SortToGroups(ls, vargs);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end - start;
	start = std::chrono::high_resolution_clock::now();
	sort(ls.begin(), ls.end(), compareAlphabet);
	sort(vargs.begin(), vargs.end(), compareAlphabet);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff3 = end - start;
	isvedimas(ls, vargs, VSize, PSize, GType);
	start = std::chrono::high_resolution_clock::now();
	OutputToFiles(ls, vargs, GType, VSize, PSize);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff4 = end - start;
	cout << "StudentList.txt generavimas uztruko: " << std::fixed << setprecision(4) << diff1.count() << " s" << endl;
	cout << "Studentu rusiavimas i kategorijas uztruko: " << std::fixed << setprecision(4) << diff2.count() << " s" << endl;
	cout << "Studentu rikiavimas uztruko: " << std::fixed << setprecision(4) << diff3.count() << " s" << endl;
	cout << "Isvedimas i failus uztruko: " << std::fixed << setprecision(4) << diff4.count() << " s" << endl;
	std::chrono::duration<double> diff = diff1 + diff2 + diff3 + diff4;
	cout << "Viso uztruko: " << std::fixed << setprecision(4) << diff.count() << " s" << endl;
	system("pause");
	return 0;
}