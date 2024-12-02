#include "../AoC.hpp"

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

	for (int i = 0; i < 1000; i++)
	{
		int size = report[i].size(), balance = 0, diff = 0;
		list<int>::iterator it = report[i].begin();
		int prec = *it;
		it++;
		for (; it != report[i].end(); it++)
		{
			if (prec < *it || prec == *it && balance > 0)
				balance++;
			else if (prec > *it || prec == *it && balance < 0)
				balance--;
			// if (abs(prec - *it) > 3)
			// 	diff++;
			prec = *it;
		}
		if (report[i].size() && abs(balance) == size - 1 && diff == 0)
			ret += 1;
	}
	cout << ret << endl;

	// ret = 0;
	// for (int i = 0; i < 1000; i++)
	// {
	// 	bool safe = true;
	// 	list<int>::iterator it = report[i].begin();
	// 	int prec = *it;
	// 	it++;
	// 	for (bool sense = prec < *it; it != report[i].end() && safe; it++)
	// 	{
	// 		if (prec < *it != sense)
	// 			safe = false;
	// 		prec = *it;
	// 	}
	// 	it = report[i].begin();
	// 	prec = *it;
	// 	it++;
	// 	for (; it != report[i].end() && safe; it++)
	// 	{
	// 		if (abs(prec - *it) > 3)
	// 			safe = false;
	// 		prec = *it;
	// 	}
	// 	if (safe)
	// 		ret ++;
				
	// }
	// cout << ret << endl;
	
}