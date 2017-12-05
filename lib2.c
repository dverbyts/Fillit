/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:24:53 by dverbyts          #+#    #+#             */
/*   Updated: 2017/02/11 13:24:55 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_putstr(map[i++]);
}

void	ft_putstr(char const *s)
{
	if (s != NULL)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	all_free(char **map, char *buf, t_trm *f)
{
	mapx_free(map, 0);
	free(f);
	free(buf);
	return ;
}
