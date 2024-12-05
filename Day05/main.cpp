#include "../AoC.hpp"

vector<vector<int>>	get_myrules(vector<vector<int>> rules, vector<int> update)
{
	vector<vector<int>>	ret;
	for (int i = 0; i < rules.size(); i++)
	{
		for (int j = 0; j < update.size(); j++)
		{
			if (update.at(j) == rules.at(i).at(0) || update.at(j) == rules.at(i).at(1))
			{
				ret.push_back(rules.at(i));
				break;
			}
		}
	}
	return (ret);
}

bool	is_first(vector<vector<int>> myrules, int fst, int lst)
{
	for (int i = 0; i < myrules.size(); i++)
	{
		if (myrules.at(i)[1] == fst && myrules.at(i)[0] == lst)
			return (false);
	}
	return (true);
}

bool	is_ordered(vector<vector<int>> rules, vector<int> update)
{
	vector<vector<int>>	myrules = get_myrules(rules, update);

	for (int i = 0; i < update.size() - 1; i++)
	{
		for (int j = i + 1; j < update.size(); j++)
		{
			if (!is_first(myrules, update.at(i), update.at(j)))
				return (false);
		}
	}
	return (true);
}

vector<int>	reorder_upds(vector<vector<int>> rules, vector<int> update)
{
	vector<vector<int>>	myrules = get_myrules(rules, update);
	vector<int>			ret = update;
	int					tmp;

	for (int i = 0; i < ret.size() - 1; i++)
	{
		for (int j = i + 1; j < ret.size(); j++)
		{
			if (!is_first(myrules, ret.at(i), ret.at(j)))
			{
				tmp = ret.at(j);
				ret.at(j) = ret.at(i);
				ret.at(i) = tmp;
			}
		}
	}
	return (ret);
}

int main()
{
	ifstream			input("input.txt");
	string				line;
	vector<vector<int>>	rules, correctUpds, incorrectUpds;
	int					ret1 = 0, ret2 = 0;

	for (; getline(input, line) && line.size() == 5; )
	{
		vector<int>	rule;
		rule.push_back(atoi(line.c_str()));
		rule.push_back(atoi(line.c_str() + 3));
		rules.push_back(rule);
	}
	for (int i = 0; getline(input, line); i++)
	{
		vector<int>	update;
		for (int j = 0; j < line.size() + 1; j += 3)
		{
			update.push_back(atoi(line.c_str() + j));
		}
		if (is_ordered(rules, update))
			correctUpds.push_back(update);
		else
			incorrectUpds.push_back(update);
	}
	for (int i = 0; i < correctUpds.size(); i++)
	{
		ret1 += correctUpds.at(i).at((correctUpds.at(i).size() / 2));
	}
	cout << ret1 << endl;
	for (int i = 0; i < incorrectUpds.size(); i++)
	{
		incorrectUpds.at(i) = reorder_upds(rules, incorrectUpds.at(i));
		ret2 += incorrectUpds.at(i).at((incorrectUpds.at(i).size() / 2));
	}
	cout << ret2 << endl;
}