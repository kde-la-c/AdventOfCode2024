#include "../libft.h"

int	*remove_one(int report[10], int pos)
{
	// printf("input %i %i %i %i %i\n", report[0], report[1], report[2], report[3], report[4]);
	int *ret = malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		ret[i] = report[i];
	}
	while (ret[pos + 1])
	{
		if (pos >= 0)
			ret[pos] = ret[pos + 1];
		pos++;
	}
	while (pos < 9)
		ret[pos++] = 0;
	return (ret);
}

int main()
{
	int		lines = 1000;
	int		report[lines][10], *rep, fd, ret = 0;
	char	**split, *line;

	fd = open("input.txt", O_RDONLY);
	ft_bzero(&report, sizeof(int) * (lines * 10));
	for (int i = 0; i < lines; i++)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		free(line);
		for (int j = 0; split[j]; j++)
		{
			report[i][j] = ft_atoi(split[j]);
		}
		ft_dfree((void **)split);
		report[i][9] = ft_mathei((void **)split);
	}

	for (int i = 0; i < lines; i++)
	{
		rep = report[i];
		int safe = 0;
		for (int k = 0; k < report[i][9] + 1; k++)
		{
			// printf("%i %i %i %i %i\n", rep[0], rep[1], rep[2], rep[3], rep[4]);
			int	balance = 0, diff = 0, feq = 0/* , safe = 0 */;
			for (int j = 0; rep[j] && rep[j + 1]; j++)
			{
				int	nb = rep[j], next = rep[j + 1];
				if (nb < next || nb == next && balance > 0)
					balance--;
				else if (nb > next || nb == next && balance < 0)
					balance++;
				// else
				// 	feq = 1;
				if (abs(nb - next) > 3)
				{
					diff = 1;
					// if (diff == -1)
					// 	diff = j;
					// else
					// 	diff = -2;
				}
			}
			if ((!diff && abs(balance) == report[i][9] - 1 && !k) || (!diff && abs(balance) == report[i][9] - 2 && k))
			{
				safe = 1;
				break;
			}
			rep = remove_one(report[i], k);
		}
		// if (!diff && abs(balance) == report[i][9] - 1)
			ret += safe;
	}
	printf("%i\n", ret);
}