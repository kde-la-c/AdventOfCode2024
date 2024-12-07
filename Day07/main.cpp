#include "../AoC.hpp"

int main()
{
	ifstream			input("input.txt");
	string				line;
	vector<vector<int>>	equations;
	int					ret = 0;

	for (int i = 0; getline(input, line); i++)
	{
		istringstream	str(line);	
		vector<int>		equation = equations.at(i);
		do
		{
			string lvl;
			str >> lvl;
			equation.push_back(atoi(lvl.c_str()));
		} while (str);		
	}


	cout << ret << endl;
}