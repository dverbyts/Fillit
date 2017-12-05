/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:31:40 by dverbyts          #+#    #+#             */
/*   Updated: 2017/01/19 16:31:42 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_trm	ft_lstnew(t_trm array, int const x[4], int const y[4], char l)
{
	int z;

	z = 0;
	while (z < 4)
	{
		array.x[z] = x[z];
		array.y[z] = y[z];
		z++;
	}
	array.letter = l;
	return (array);
}

void	correct_cords(int *x, int *y)
{
	while (x[0] != 0 && x[1] != 0 && x[2] != 0 && x[3] != 0)
	{
		x[0] = x[0] - 1;
		x[1] = x[1] - 1;
		x[2] = x[2] - 1;
		x[3] = x[3] - 1;
	}
	while (y[0] != 0 && y[1] != 0 && y[2] != 0 && y[3] != 0)
	{
		y[0] = y[0] - 1;
		y[1] = y[1] - 1;
		y[2] = y[2] - 1;
		y[3] = y[3] - 1;
	}
	return ;
}

t_trm	read_cords(t_trm array, char *buf, char l, int z)
{
	int	x[4];
	int	y[4];
	int	xk;
	int	yk;

	xk = 0;
	yk = 0;
	while (*buf)
	{
		if (*buf == '#')
		{
			x[z] = xk;
			y[z++] = yk;
		}
		if (*buf++ == '\n')
		{
			xk = -1;
			yk++;
		}
		xk++;
	}
	correct_cords(x, y);
	return (ft_lstnew(array, x, y, l));
}

t_trm	*make_lists(char *buf)
{
	char	**sors;
	char	letter;
	int		z;
	t_trm	*array;

	if (!(array = (t_trm *)malloc(sizeof(t_trm) * (ft_strlen(buf) / 21 + 1))))
		return (0);
	sors = split_ttrmns(buf);
	z = 0;
	letter = 'A';
	while (sors[z] && z < 26)
	{
		array[z] = read_cords(array[z], sors[z], letter, 0);
		z++;
		letter++;
	}
	map_free(sors, 0);
	return (array);
}
