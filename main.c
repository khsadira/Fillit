/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:18:08 by schakor           #+#    #+#             */
/*   Updated: 2017/12/13 12:24:20 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_uint16	*ret;
	char		*content;

	if (ac != 2)
		ft_putendl_fd("usage : ", 2);
	content = ft_read_file(av[1]);
	ft_treat_file(content, &ret, 0 ,0);
	size_t i = 0;
	while (i <= ft_strlen(content) / 21)
	{
		printf("ret[%zu] = %u\n", i, ret[i]);
		i++;
	}
	return (0);
}
