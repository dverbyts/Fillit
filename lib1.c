/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:57:55 by dverbyts          #+#    #+#             */
/*   Updated: 2017/01/15 16:57:57 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bzero(void *s, size_t n)
{
	int x;

	x = 0;
	if (!n)
		return ;
	while (n)
	{
		((char *)s)[x] = '\0';
		n--;
		x++;
	}
}

size_t	ft_strlen(const char *string)
{
	size_t rez;

	rez = 0;
	while (string[rez])
		rez++;
	return (rez);
}

char	**split_ttrmns(char *map)
{
	char	**ttrm;
	int		n;
	int		x;
	int		y;

	if (!(ttrm = (char **)malloc(sizeof(char*) * ft_strlen(map) / 21 + 2)))
		return (NULL);
	ft_bzero(ttrm, (ft_strlen(map) / 21 + 2));
	x = 0;
	while (*map)
	{
		if (!(ttrm[x] = (char *)malloc(sizeof(char) * 22)))
			return (NULL);
		ft_bzero(ttrm[x], 22);
		n = 21;
		y = 0;
		while (n--)
			ttrm[x][y++] = *map++;
		x++;
	}
	ttrm[x] = 0;
	return (ttrm);
}

int		min_square(char *map, t_trm *array)
{
	float	t_s;
	int		x;

	x = 2;
	t_s = ft_strlen(map);
	while (((t_s / 21) * 4) / (x * x) > 1)
		x++;
	x = chek_first_ttr(array[0], x);
	return (x);
}

int		chek_first_ttr(t_trm fig, int s)
{
	int z;

	z = 0;
	while (z < 4)
	{
		if ((fig.y[z] >= s) || (fig.x[z] >= s))
			s++;
		else
			z++;
	}
	return (s);
}
