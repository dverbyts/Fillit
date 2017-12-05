/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:09:09 by dverbyts          #+#    #+#             */
/*   Updated: 2017/01/12 22:22:05 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_trm
{
	int			y[4];
	int			x[4];
	char		letter;
}				t_trm;

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *string);
int				valid_map(char *map, int i, int str, int ttrm);
char			**split_ttrmns(char *map);
char			**split(char *map, int x, int y, int n);
void			correct_cords(int *x, int *y);
char			*file_open(char *argv);
int				inter(char **map, int r, int c);
int				valid_figure(char **map, int r, int c, int i);
int				map_free(char **f, int r);
int				mapx_free(char **f, int x);
t_trm			*make_lists(char *buf);
t_trm			read_cords(t_trm array, char *buf, char l, int z);
t_trm			ft_lstnew(t_trm re, int const bx[4], int const by[4], char l);
char			**new_square(int x);
int				min_square(char *map, t_trm	*array);
int				chek_first_ttr(t_trm fig, int s);
int				chek_ttr_cords(int x, int y, t_trm fig, int s);
int				ttr_del(char **map, t_trm fig, int s, int *c);
int				ttr_set(char **map, t_trm fig, int s, int *c);
int				fillit(char **map, t_trm *fig, int *inf);
int				ttr_inmap(char **map, t_trm fig, int s);
int				ttr_allin(char **map, t_trm *fig, int s, int ttrm_n);
void			ft_make(char *buf);
void			ft_print(char **map, int size);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			all_free(char **map, char *buf, t_trm *f);

#endif
