/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:59:45 by schakor           #+#    #+#             */
/*   Updated: 2017/12/13 12:26:36 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_treat_file(char *content, t_uint16 **ret, int i, int j)
{
	int			n;
	int			nb_return;
	int			nb_tetra;


	nb_tetra = ft_strlen(content) / 21;
	*ret = (t_uint16*)malloc(sizeof(**ret) * nb_tetra);
	ft_bzero(*ret, 52);
	n = 15;
	nb_return = 5;
	while (content[i])
	{
		if (content[i] == '#')
			(*ret)[j] |= 1 << n;
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
	int	 a = 0;
	while (a <= nb_tetra)
	{
		printf("ret[%d] = %u\n", a, (*ret)[a]);
		a++;
	}
	a = 0;
	while (a <= nb_tetra)
	{
		printf("1 a = %d ret[%d] = %u\n", a, a, (*ret)[a]);
		while (((*ret)[a] & 0x8888) == 0)
			(*ret)[a] <<= 1;
		printf("2 a = %d\n", a);
		while (((*ret)[a] & 0xf000) == 0)
			(*ret)[a] <<= 4;
		printf("ret[%d] = %u et a = %d\n", a, (*ret)[a], a);
		a++;
	}
	printf("%d\n", ft_check_tetra(*ret, nb_tetra));
}
