/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:03:43 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 17:30:11 by schakor          ###   ########.fr       */
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
		ft_putendl_fd("error", 1);
		exit(1);
	}
	rd = read(fd, buf, 545);
	if (rd == -1 || rd > 545)
	{
		ft_putendl_fd("error", 1);
		exit(1);
	}
	buf[rd] = '\0';
	content = ft_strdup(buf);
	if ((rd + 1) % 21 != 0)
		ft_print_err();
	return (content);
}
