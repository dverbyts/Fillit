/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:36:09 by dverbyts          #+#    #+#             */
/*   Updated: 2017/02/11 14:36:10 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ttr_inmap(char **map, t_trm fig, int s)
{
	int	x;
	int	y;

	y = 0;
	while (y < s)
	{
		x = 0;
		while (x < s)
		{
			if (map[y][x] == fig.letter)
				return (-1);
			x++;
		}
		y++;
	}
	return (1);
}

int		ttr_allin(char **map, t_trm *fig, int s, int ttrm_n)
{
	int l;

	l = 0;
	while (l < ttrm_n)
	{
		if (ttr_inmap(map, fig[l], s) != -1)
			return (-1);
		l++;
	}
	return (1);
}

int		chek_ttr_cords(int x, int y, t_trm fig, int s)
{
	if ((y + fig.y[0] < s) && (x + fig.x[0] < s) && (y + fig.y[1] < s) &&
		(x + fig.x[1] < s) && (y + fig.y[2] < s) && (x + fig.x[2] < s) &&
		(y + fig.y[3] < s) && (x + fig.x[3] < s))
		return (1);
	return (-1);
}

int		mapx_free(char **f, int s)
{
	int x;

	x = 0;
	while (x < s)
	{
		if (f[x])
			free(f[x]);
		f[x++] = NULL;
	}
	if (f)
		free(f);
	s++;
	return (s);
}

char	**new_square(int x)
{
	char	**square;
	int		l;
	int		len;

	if (!(square = (char**)malloc(sizeof(char*) * (x + 1))))
		return (0);
	l = 0;
	while (l < x)
	{
		if (!(square[l] = (char*)malloc(sizeof(char) * (x + 2))))
			return (0);
		len = 0;
		while (len < x)
			square[l][len++] = '.';
		square[l][len++] = '\n';
		square[l][len] = '\0';
		l++;
	}
	square[l] = NULL;
	return (square);
}
