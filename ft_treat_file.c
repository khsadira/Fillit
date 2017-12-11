/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:59:45 by schakor           #+#    #+#             */
/*   Updated: 2017/12/11 16:20:45 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_uint16	*ft_treat_file(char *content, t_uint16 ret[26], int i, int j)
{
	int			n;
	int			nb_return;

	ft_bzero(ret, 26);
	n = 15;
	nb_return = 5;
	while (content[i])
	{
		if (content[i] == '#')
			ret[j] |= 1 << n;
		else if (content[i] == '\n')
		{
			n++;
			nb_return--;
		}
		if (nb_return == 0)
		{
			j++;
			nb_return = 5;
			n = 16;
		}
		n--;
		i++;
	}
	i = 0;
/*	while (i < 4)
	{
		printf("ret[%d] = %u\n", i, ret[i]);
		i++;
	}*/
	return (ret);
}
