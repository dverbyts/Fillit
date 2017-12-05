/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 23:11:34 by dverbyts          #+#    #+#             */
/*   Updated: 2017/01/13 23:11:36 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_map(char *map, int i, int str, int ttrm)
{
	size_t l;

	l = 0;
	while (map[l])
	{
		str = -1;
		while (++str < 5)
		{
			if ((str == 4 && map[l] != '\n') || ((str >= 0 && str <= 3) &&
				(map[l] != '#' && map[l] != '.')))
				return (0);
			l++;
		}
		i++;
		if (i == 4)
		{
			if (((ft_strlen(map) - l) < 21 && map[l] != '\0') ||
				((map[l] != '\n' && map[l] != '\0') || ttrm > 25))
				return (0);
			i = 0;
			ttrm++;
			l++;
		}
	}
	return (1);
}

int		map_free(char **f, int r)
{
	int x;

	x = 0;
	while (f[x])
	{
		if (f[x])
			free(f[x]);
		f[x] = NULL;
		x++;
	}
	if (f)
		free(f);
	return (r);
}

char	**split(char *map, int x, int y, int n)
{
	char	**ttrm;

	if (!(ttrm = (char **)malloc(sizeof(char*) * 135)))
		return (NULL);
	ft_bzero(ttrm, 135);
	while (*map)
	{
		if (!(ttrm[x] = (char *)malloc(sizeof(char) * 6)))
			return (NULL);
		ft_bzero(ttrm[x], 6);
		while (--n > 0)
			ttrm[x][y++] = *map++;
		x++;
		y = 0;
		n = 6;
		if (*map == '\n')
			n = 2;
	}
	if (!(ttrm[x] = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	ft_bzero(ttrm[x], 2);
	return (ttrm);
}

int		inter(char **map, int r, int c)
{
	int		con;

	con = 0;
	if (map[r][c] == map[r + 1][c])
		con++;
	if (map[r][c] == map[r][c + 1])
		con++;
	if (r != 0)
	{
		if (map[r][c] == map[r - 1][c])
			con++;
	}
	if (c != 0)
	{
		if (map[r][c] == map[r][c - 1])
			con++;
	}
	return (con);
}

int		valid_figure(char **map, int r, int c, int i)
{
	int con;

	while (map[r][c] != '\0')
	{
		i = -1;
		con = 0;
		while (++i < 21)
		{
			if (map[r][c] == '#')
			{
				con++;
				con = (con + inter(map, r, c++));
			}
			else if (map[r][c] == '\n')
			{
				r++;
				c = 0;
			}
			else
				c++;
		}
		if ((con != 10 && con != 12))
			return (map_free(map, 0));
	}
	return (map_free(map, 1));
}
