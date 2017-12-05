/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:28:22 by dverbyts          #+#    #+#             */
/*   Updated: 2017/01/23 17:28:23 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(char **map, t_trm *fig, int *inf)
{
	int cord[2];

	if (ttr_allin(map, fig, inf[0], inf[2]) == 1)
		return (1);
	cord[1] = -1;
	while (++cord[1] < inf[0])
	{
		cord[0] = -1;
		while (++cord[0] < inf[0])
		{
			if (ttr_set(map, fig[inf[1]], inf[0], cord))
			{
				inf[1] += 1;
				if (fillit(map, fig, inf))
					return (1);
				inf[1] -= 1;
				ttr_del(map, fig[inf[1]], inf[0], cord);
			}
		}
	}
	return (0);
}

int		ttr_set(char **map, t_trm fig, int s, int *c)
{
	if (chek_ttr_cords(c[0], c[1], fig, s) == 1 && ttr_inmap(map, fig, s) == 1)
	{
		if ((map[c[1] + fig.y[0]][c[0] + fig.x[0]] == '.') &&
			(map[c[1] + fig.y[1]][c[0] + fig.x[1]] == '.') &&
			(map[c[1] + fig.y[2]][c[0] + fig.x[2]] == '.') &&
			(map[c[1] + fig.y[3]][c[0] + fig.x[3]] == '.'))
		{
			map[c[1] + fig.y[0]][c[0] + fig.x[0]] = fig.letter;
			map[c[1] + fig.y[1]][c[0] + fig.x[1]] = fig.letter;
			map[c[1] + fig.y[2]][c[0] + fig.x[2]] = fig.letter;
			map[c[1] + fig.y[3]][c[0] + fig.x[3]] = fig.letter;
			return (1);
		}
	}
	return (0);
}

int		ttr_del(char **map, t_trm fig, int s, int *c)
{
	c[1] = 0;
	while (c[1] < s)
	{
		c[0] = 0;
		while (c[0] < s)
		{
			if (chek_ttr_cords(c[0], c[1], fig, s) == 1)
			{
				if ((map[c[1] + fig.y[0]][c[0] + fig.x[0]] == fig.letter) &&
					(map[c[1] + fig.y[1]][c[0] + fig.x[1]] == fig.letter) &&
					(map[c[1] + fig.y[2]][c[0] + fig.x[2]] == fig.letter) &&
					(map[c[1] + fig.y[3]][c[0] + fig.x[3]] == fig.letter))
				{
					map[c[1] + fig.y[0]][c[0] + fig.x[0]] = '.';
					map[c[1] + fig.y[1]][c[0] + fig.x[1]] = '.';
					map[c[1] + fig.y[2]][c[0] + fig.x[2]] = '.';
					map[c[1] + fig.y[3]][c[0] + fig.x[3]] = '.';
					return (1);
				}
			}
			c[0]++;
		}
		c[1]++;
	}
	return (-1);
}
