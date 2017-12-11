/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:03:43 by schakor           #+#    #+#             */
/*   Updated: 2017/12/11 16:20:36 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_uint16	*ft_read_file(char *file, int rd)
{
	int			fd;
	char		c[546];
//	char		*content;
	t_uint16	ret[26];

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("wrong input", 2);
		exit(1);
	}
	rd = read(fd, c, 545);
	if (rd == -1)
	{
		ft_putendl_fd("wrong input", 2);
		exit(1);
	}
	if (rd > 545)
	{
		ft_putendl_fd("wrong input", 2);
		exit(1);
	}
	c[rd] = '\0';
//	content = ft_strdup(c);
	return (ft_treat_file(c, ret, 0, 0));
}
