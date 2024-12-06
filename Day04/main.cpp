#include "../AoC.hpp"

//   0 1 2 3 C
// 0 . . . .
// 1 . . . .
// 2 . . . .
// 3 . . . .
// L
int	height, width;

int check_straight(vector<string> lines, int l, int c)
{
	int	ret = 0;
	if (l >= 3)
		ret += lines.at(l - 1).at(c) == 'M' && lines.at(l - 2).at(c) == 'A' && lines.at(l - 3).at(c) == 'S';
	if (l <= width - 4)
		ret += lines.at(l + 1).at(c) == 'M' && lines.at(l + 2).at(c) == 'A' && lines.at(l + 3).at(c) == 'S';
	if (c >= 3)
		ret += lines.at(l).at(c - 1) == 'M' && lines.at(l).at(c - 2) == 'A' && lines.at(l).at(c - 3) == 'S';
	if (c <= height - 4)
		ret += lines.at(l).at(c + 1) == 'M' && lines.at(l).at(c + 2) == 'A' && lines.at(l).at(c + 3) == 'S';
	return (ret);
}

int check_diagonal(vector<string> lines, int l, int c)
{
	int	ret = 0;
	if (l >= 3 && c >= 3)
		ret += lines.at(l - 1).at(c - 1) == 'M' && lines.at(l - 2).at(c - 2) == 'A' && lines.at(l - 3).at(c - 3) == 'S';
	if (l >= 3 && c <= height - 4)
		ret += lines.at(l - 1).at(c + 1) == 'M' && lines.at(l - 2).at(c + 2) == 'A' && lines.at(l - 3).at(c + 3) == 'S';
	if (l <= width - 4 && c <= height - 4)
		ret += lines.at(l + 1).at(c + 1) == 'M' && lines.at(l + 2).at(c + 2) == 'A' && lines.at(l + 3).at(c + 3) == 'S';
	if (l <= width - 4 && c >= 3)
		ret += lines.at(l + 1).at(c - 1) == 'M' && lines.at(l + 2).at(c - 2) == 'A' && lines.at(l + 3).at(c - 3) == 'S';
	return (ret);
}

int	check_cross(vector<string> lines, int l, int c)
{
	int	ret = 0, i, j;
	if (l >= 1 && l <= width - 2 && c >= 1 && c <= height - 2)
	{
		ret += ((lines.at(l - 1).at(c - 1) == 'M' && lines.at(l + 1).at(c + 1) == 'S')
				|| (lines.at(l - 1).at(c - 1) == 'S' && lines.at(l + 1).at(c + 1) == 'M'))
			&& ((lines.at(l + 1).at(c - 1) == 'M' && lines.at(l - 1).at(c + 1) == 'S')
				|| (lines.at(l + 1).at(c - 1) == 'S' && lines.at(l - 1).at(c + 1) == 'M'));
	}
	return (ret);
}

int main()
{
	ifstream		input("input.txt");
	string			line;
	vector<string>	lines;
	int				ret1 = 0, ret2 = 0;

	for (int i = 0; getline(input, line); i++)
	{
		lines.push_back(line);
	}
	height = lines.size();
	width = lines.at(0).size();

	for (int l = 0; l < height; l++)
	{
		for (int c = 0; c < width; c++)
		{
			if (lines.at(l).at(c) == 'X')
			{
				ret1 += check_straight(lines, l, c);
				ret1 += check_diagonal(lines, l, c);
			}
			if (lines.at(l).at(c) == 'A')
				ret2 += check_cross(lines, l, c);
		}
	}
	cout << ret1 << endl;
	cout << ret2 << endl;
}