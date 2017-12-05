/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:10:26 by dverbyts          #+#    #+#             */
/*   Updated: 2017/01/13 21:10:27 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid(char *buf)
{
	if (valid_map(buf, 0, 0, 0) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (valid_figure(split(buf, 0, 0, 6), 0, 0, 0) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}

char	*file_open(char *argv)
{
	int		fd;
	int		l;
	char	*buf;

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	if (!(buf = (char *)malloc(sizeof(char) * 600)))
		return (NULL);
	ft_bzero(buf, 600);
	l = 0;
	while (read(fd, &buf[l], 1) && l < 600)
		l++;
	if (buf[0] == '\0')
		buf[0] = -1;
	if (close(fd) != 0)
		write(1, "error\n", 6);
	if (valid(buf) == 1)
		return (buf);
	if (buf)
		free(buf);
	return (0);
}
