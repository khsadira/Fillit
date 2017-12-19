/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:03:43 by schakor           #+#    #+#             */
/*   Updated: 2017/12/19 10:22:16 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_file(char *file)
{
	int			rd;
	int			fd;
	char		buf[545];
	char		*content;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("wrong input", 2);
		exit(1);
	}
	rd = read(fd, buf, 545);
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
	buf[rd] = '\0';
	content = ft_strdup(buf);
	return (content);
}
