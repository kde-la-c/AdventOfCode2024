#include "../AoC.hpp"

/* 
didn't manage to implement algorithm correctly due to a bad structure to begin
with.
It would have been a check each time we are on a 'x' cell if the line to it's
right would end with 'X' then '#', and be full of 'x' cells.
This would have ensured a possible infinite loop in case we placed an obstacle
just in front of the guard's current position.
 */

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

bool	check_ahead(vector<string> map, int dir, coords crd)
{
	coords	tmp(crd.l, crd.c);
	bool ret = false;
	if (dir == UP)
	{
		tmp.l--;
		ret = (tmp.isOnRange() && map.at(cords.l - 1).at(cords.c) != '#');
	}
	else if (dir == RIGHT)
	{
		tmp.c++;
		ret = (tmp.isOnRange() && map.at(cords.l).at(cords.c + 1) != '#');
	}
	else if (dir == DOWN)
	{
		tmp.l++;
		ret = (tmp.isOnRange() && map.at(cords.l + 1).at(cords.c) != '#');
	}
	else if (dir == LEFT)
	{
		tmp.c--;
		ret = (tmp.isOnRange() && map.at(cords.l).at(cords.c - 1) != '#');
	}
	// cout << "checked " << tmp.l << ' ' << tmp.c << endl;
	return (ret);
}

bool	check_loop(vector<string> *map, int dir)
{
	coords tmp(cords.l, cords.c);
	dir = (dir + 1) % 4;
	while (tmp.isOnRange() && check_ahead(*map, dir, tmp))
	{
		cout << '	' << map->at(tmp.l).at(tmp.c) << endl;
		if (dir == UP)
			tmp.l--;
		else if (dir == RIGHT)
			tmp.c++;
		else if (dir == DOWN)
			tmp.l++;
		else if (dir == LEFT)
			tmp.c--;
	}
	// cout << map->at(tmp.l).at(tmp.c) << " " << tmp.l << tmp.c << endl;
	// cout << (map->at(tmp.l).at(tmp.c) == 'X') << endl;
	return (map->at(tmp.l).at(tmp.c) == 'X');
}

int	go(vector<string> *map, int direction)
{
	int	ret = 0, dir = direction % 4;

	while (cords.isOnRange() && check_ahead(*map, dir, cords))
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
		if (check_loop(map, dir))
			ret++;
	}
	if (cords.isOnRange() && map->at(cords.l).at(cords.c) == '.')
	{
		ret++;
		map->at(cords.l).at(cords.c) = 'X';
	}
	// if ()
	// 	return (-1);
	return (ret);
}

int main()
{
	ifstream		input("test.txt");
	ofstream		output("out.txt");
	string			line;
	vector<string>	map;
	int				ret1 = 0, ret2 = 0, tmp;

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
	
	// for (int i = 0; cords.isOnRange(); i++)
	// {
	// 	tmp = go(&map, i);
	// 	if (tmp <= 0)
	// 		break;
	// 	ret1 += tmp;
	// }
	// cout << ret1 + 1 << endl;
	for (int i = 0; cords.isOnRange(); i++)
	{
		this_thread::sleep_for (std::chrono::milliseconds(100));

		cout << "hola" << endl;
		tmp = go(&map, i);
		if (tmp <= 0)
			break;
		ret2 += tmp;
	}
	cout << ret2 << endl;
	
	for (int l = 0; l < height; l++)
	{
		output << map.at(l) << endl;
	}
}

