#include "../AoC.hpp"

int	numlen(int nb)
{
	int i = 0;
	if (nb / 10 == 0)
		return (1);
	else
		return (1 + numlen(nb / 10));
}

int	calc_line(string line)
{
	int	pos = 0, i, j, nb1, nb2, ret = 0, size = line.size();
	while (pos < size && i != string::npos)
	{
		// this_thread::sleep_for (std::chrono::seconds(1));
		i = line.find("mul(", pos);
		j = line.find("don't()", pos);
		// cout << "i " << i << ", j " << j << endl;
		if (j < i && j != string::npos)
		{
			pos = j + 7;
			j = line.find("do()", pos);
			pos = j + 4;
		}
		else
		{
			pos = i + 4;
			if (pos < size && isdigit(line.at(pos)))
			{
				nb1 = atoi(&line.at(pos));
				pos += numlen(nb1);
				if (pos < size && line.at(pos) == ',' && pos++)
				{
					nb2 = atoi(&line.at(pos));
					pos += numlen(nb2);
					if (line.at(pos) == ')')
					{
						cout << nb1 << ',' << nb2 << endl;
						ret += nb1 * nb2;
					}
				}
			}
		}
	}
	return (ret);
}

int main()
{
	ifstream		input("input.txt");
	string			line;
	list<string>	lines;
	int				ret = 0;

	for (int i = 0; getline(input, line); i++)
	{
		lines.push_back(line);
	}

	list<string>::iterator	it = lines.begin();
	for (; it != lines.end(); it++)
	{
		ret += calc_line(*it);
	}
	cout << ret << endl;
	return (0);
}