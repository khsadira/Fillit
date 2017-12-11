/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:18:08 by schakor           #+#    #+#             */
/*   Updated: 2017/12/11 12:34:26 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	t_uint16	*ret;

	if (ac != 2)
		ft_putendl_fd("usage : ", 2);
	ret = ft_read_file(av[1], 0);
	int i = 0;
	while (i < 4)
	{
		printf("ret[%d] = %u\n", i, ret[i]);
		i++;
	}
	return (0);
}
