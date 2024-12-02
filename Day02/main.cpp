#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

using namespace std;

int main()
{
	ifstream	input("input.txt");
	string		line;
	list<int>	report[1000];
	int			tmp, ret = 0;

	for (int i = 0; getline(input, line); i++)
	{
		istringstream str(line);	
		do
		{
			string lvl;
			str >> lvl;
			report[i].push_back(atoi(lvl.c_str()));
		} while (str);		
	}
	// for (int i = 0; i < 1000; i++)
	// {
	// 	list<int>::iterator it = report[i].begin();
	// 	int prec = *it;
	// 	it++;
	// 	for (bool sign = prec > *it, dud = 0; it != report[i].end(); it++) // 0 = <, 1 = >
	// 	{
	// 		if (prec > *it != sign)
	// 		{
	// 			prec = -1;
	// 			break;
	// 		}
	// 		prec = *it;
	// 	}
	// 	if (prec != -1)
	// 		ret += 1;
	// }

	for (int i = 0; i < 1000; i++)
	{
		bool safe = true;
		list<int>::iterator it = report[i].begin();
		int prec = *it;
		it++;
		for (bool sense = prec < *it; it != report[i].end() && safe; it++)
		{
			if (prec < *it != sense)
				safe = false;
			prec = *it;
		}
		it = report[i].begin();
		prec = *it;
		it++;
		for (; it != report[i].end() && safe; it++)
		{
			if (abs(prec - *it) > 3)
				safe = false;
			prec = *it;
		}
		if (safe)
			ret ++;
				
	}
	cout << ret << endl;
	
}