/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:10:59 by dverbyts          #+#    #+#             */
/*   Updated: 2016/12/23 16:11:02 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*buf;

	if (argc != 2)
	{
		write(1, "usage: ./fillit	some_map_file\n", 30);
		return (0);
	}
	buf = file_open(argv[1]);
	if (buf == NULL)
		return (-1);
	ft_make(buf);
	return (0);
}

void	ft_make(char *buf)
{
	char	**map;
	t_trm	*ttrm;
	int		inf[3];
	int		q;

	q = 0;
	ttrm = make_lists(buf);
	inf[0] = min_square(buf, ttrm);
	inf[2] = ft_strlen(buf) / 21 + 1;
	while (q != 1)
	{
		inf[1] = 0;
		map = new_square(inf[0]);
		q = fillit(map, ttrm, inf);
		if (q == 0)
			inf[0] = mapx_free(map, inf[0]);
	}
	ft_print(map, inf[0]);
	all_free(map, buf, ttrm);
	return ;
}
