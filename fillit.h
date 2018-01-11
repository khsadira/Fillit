/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:18:38 by schakor           #+#    #+#             */
/*   Updated: 2018/01/11 11:29:23 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;

char		*ft_read_file(char *file);
void		ft_treat_file(char *content, t_uint16 **ret);
int			ft_check_tetra(t_uint16 *tetra, int nb_tetra);
void		ft_solve(t_uint16 *map, t_uint16 *tetra, int nb_tetra);
void		ft_print_map(t_uint16 *map);

#endif
