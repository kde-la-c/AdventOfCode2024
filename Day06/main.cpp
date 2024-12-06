#include "../AoC.hpp"

typedef enum e_direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT
}	t_direction;

int	height, width;

class coords
{
public:
	int	l, c;
	bool isOnRange();
	coords(int line, int column);
	~coords();
};

bool coords::isOnRange()
{
	return (l >= 0 && l < height - 1 && c >= 0 && c < width - 1);
}

coords::coords(int line, int column)
{
	l = line;
	c = column;
}

coords::~coords()
{
}
coords cords(0, 0);

bool	check_ahead(vector<string> map, int dir)
{
	coords	tmp(cords);
	if (dir == UP)
	{
		tmp.l--;
		return (tmp.isOnRange() && map.at(cords.l - 1).at(cords.c) != '#');
	}
	else if (dir == RIGHT)
	{
		tmp.c++;
		return (tmp.isOnRange() && map.at(cords.l).at(cords.c + 1) != '#');
	}
	else if (dir == DOWN)
	{
		tmp.l++;
		return (tmp.isOnRange() && map.at(cords.l + 1).at(cords.c) != '#');
	}
	else if (dir == LEFT)
	{
		tmp.c--;
		return (tmp.isOnRange() && map.at(cords.l).at(cords.c - 1) != '#');
	}
	return (false);
}

int	go(vector<string> *map, int direction)
{
	int	ret = 0, dir = direction % 4;

	while (cords.isOnRange() && check_ahead(*map, dir))
	{
		if (map->at(cords.l).at(cords.c) == '.')
		{
			ret++;
			map->at(cords.l).at(cords.c) = 'x';
		}
		if (dir == UP)
			cords.l--;
		else if (dir == RIGHT)
			cords.c++;
		else if (dir == DOWN)
			cords.l++;
		else if (dir == LEFT)
			cords.c--;
	}
	if (cords.isOnRange() && map->at(cords.l).at(cords.c) == '.')
	{
		ret++;
		map->at(cords.l).at(cords.c) = 'x';
	}
	return (ret);
}

int main()
{
	ifstream		input("test.txt");
	ofstream		output("out.txt");
	string			line;
	vector<string>	map;
	int				ret = 0, tmp;

	for (; getline(input, line); )
	{
		map.push_back(line);
	}
	height = map.size();
	width = map.at(0).size();

	for (int l = 0; l < height; l++)
		for (int c = 0; c < width; c++)
			if (map.at(l).at(c) == '^')
			{
				cords = coords(l, c);
				map.at(l).at(c) = '.';
				break;
			}
	
	for (int i = 0; cords.isOnRange(); i++)
	{
		tmp = go(&map, i);
		if (tmp <= 0)
			break;
		ret += tmp;
	}
	
	for (int l = 0; l < height; l++)
	{
		output << map.at(l) << endl;
	}
	cout << ret + 1 << endl;
}