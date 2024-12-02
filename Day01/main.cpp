#include "../AoC.hpp"

int main()
{
	ifstream	input("input.txt");
	string		line, str1, str2;
	list<int>	lst1, lst2;
	int			ret = 0;

	while (getline(input, line))
	{
		str1 = line.substr(0, 5);
		str2 = line.substr(8, 5);
		lst1.push_back(atoi(str1.c_str()));
		lst2.push_back(atoi(str2.c_str()));
	}
	lst1.sort();
	lst2.sort();
	list<int>::iterator	it1 = lst1.begin();
	list<int>::iterator	it2 = lst2.begin();
	for (; it1 != lst1.end(); it1++, it2++)
	{
		ret += abs(*it1 - *it2);
	}
	// cout << ret << endl;

	ret = 0;
	for (it1 = lst1.begin(); it1 != lst1.end(); it1++)
	{
		int rep = 0;
		for (it2 = lst2.begin(); it2 != lst2.end(); it2++)
		{
			if (*it1 == *it2)
				rep++;
		}
		ret += rep * *it1;
	}
	cout << ret << endl;
}