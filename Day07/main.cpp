#include "../AoC.hpp"

int	result_checker(vector<long> equation, int pos)
{
	return (0);
}

int main()
{
	ifstream				input("input.txt");
	string					line;
	vector<vector<long>>	equations;
	int						ret = 0;

	for (int i = 0; getline(input, line); i++)
	{
		istringstream	str(line);	
		vector<long>		equation;
		do
		{
			string lvl;
			str >> lvl;
			equation.push_back(atoi(lvl.c_str()));
		} while (str);
		equations.push_back(equation);
	}

	for (int i = 0; i < equations.size(); i++)
	{
		for (int j = 0; j < equations.at(i).size(); j++)
		{
			if (result_checker(equations.at(i), 1))
				ret += equations.at(i).at(0);
		}
		
	}
	

	cout << ret << endl;
}