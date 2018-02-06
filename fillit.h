/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:18:38 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 14:18:21 by schakor          ###   ########.fr       */
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

char		*ft_read_file(char *file);
void		ft_treat_file(char *content, t_uint16 **ret);
int			ft_check_tetra(t_uint16 *tetra, int nb_tetra);
void		ft_solve(t_uint16 *map, t_uint16 *tetra, int nb_tetra);
void		ft_characterize_map(int nb_tetra, int position[26],
								t_uint16 *tetra, int square);
void		ft_reset_tuint16(t_uint16 *map);
void		ft_reset_int(int *pos);

#endif
