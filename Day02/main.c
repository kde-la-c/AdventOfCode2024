#include "../libft.h"

int main()
{
	int		report[1000][10], fd, ret = 0, lines = 4;
	char	**split, *line;

	fd = open("test.txt", O_RDONLY);
	ft_bzero(&report, sizeof(int) * 10000);
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
		int	balance = 0, diff = -1, feq = 0;
		for (int j = 0; report[i][j] && report[i][j + 1]; j++)
		{
			int	nb = report[i][j], next = report[i][j + 1];
			if (nb < next || nb == next && balance > 0)
				balance--;
			else if (nb > next || nb == next && balance < 0)
				balance++;
			else
				feq = 1;
			if (abs(nb - next) > 3)
				if (diff == -1)
					diff = j;
				else
					diff = -2;
		}
		int	bol = (diff == -1 && abs(balance) == report[i][9] - 1)
			|| (diff == -1 && ((abs(balance) == report[i][9] - 2 && !feq) || (abs(balance) == report[i][9] - 2) && feq))
			|| (diff > -1 && abs(balance) == report[i][9] - 1);
		printf("%i : bal %i, diff %i, feq %i, sz %i\n", bol, balance, diff, feq, report[i][9]);
		if (bol)
			ret++;
		// if (!diff && abs(balance) == report[i][9] - 1)
		// 	ret++;
	}
	printf("%i\n", ret);
}