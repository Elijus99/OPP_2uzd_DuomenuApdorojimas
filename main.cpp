#include "functions.h"
#include "libraries.h"
#include <algorithm>

int main()
{
	int VSize = 10, PSize = 10;
	string GType{};
	std::vector<stud> ls;
	ivedimas(GType, ls, VSize, PSize);
	std::sort(ls.begin(), ls.end(), compareAlphabet);
	isvedimas(ls, VSize, PSize, GType);
	system("pause");
	return 0;
}