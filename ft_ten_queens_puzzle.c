/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:17:46 by dshushku          #+#    #+#             */
/*   Updated: 2022/11/01 16:17:47 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(int tab[10][10])
{
	int		i;
	int		j;
	char	temp;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (tab[j][i] == 1)
			{
				temp = j + '0';
				write(1, &temp, 1);
			}
		}
	}
	write(1, "\n", 1);
}

int	check_line(int tab[10][10], int r, int c)
{
	while (c >= 0)
	{
		c--;
		if (c < 0)
			break ;
		if (tab[r][c] == 1)
			return (0);
	}
	return (1);
}

int	check_diagonals(int tab[10][10], int r, int c)
{
	int		x;
	int		y;

	y = r;
	x = c;
	while (r <= 9 || c >= 0)
	{
		r++;
		c--;
		if (r > 9 || c < 0)
			break ;
		if (tab[r][c] == 1)
			return (0);
	}
	while (y >= 0 || x >= 0)
	{
		y--;
		x--;
		if (y < 0 || x < 0)
			break ;
		if (tab[y][x] == 1)
			return (0);
	}
	return (1);
}

int	solve(int tab[10][10], int c, int *count)
{
	int		r;

	r = 0;
	if (r > 9 && c > 9)
		return (1);
	while (r < 10)
	{
		if (check_diagonals(tab, r, c) && check_line(tab, r, c))
		{
			tab[r][c] = 1;
			if (c == 9)
			{
				ft_print_tab(tab);
				(*count)++;
			}
			if (solve(tab, c + 1, count))
				return (1);
		}
		r++;
	}
	r = -1;
	while (++r <= 9)
		tab[r][c - 1] = -1;
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int		tab[10][10];
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			tab[i][j] = 0;
	}
	solve(tab, 0, &count);
	return (count);
}
