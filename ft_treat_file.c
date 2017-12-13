/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:59:45 by schakor           #+#    #+#             */
/*   Updated: 2017/12/13 13:42:04 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_replace_tetra(t_uint16 **ret, int nb_tetra)
{
	int	a;

	a = 0;
	while (a <= nb_tetra)
	{
		while (((*ret)[a] & 0x8888) == 0)
			(*ret)[a] <<= 1;
		while (((*ret)[a] & 0xf000) == 0)
			(*ret)[a] <<= 4;
		a++;
	}
}

void		ft_treat_file(char *content, t_uint16 **ret, int i, int j)
{
	int			n;
	int			nb_tetra;

	nb_tetra = ft_strlen(content) / 21;
	*ret = (t_uint16*)malloc(sizeof(**ret) * nb_tetra);
	ft_bzero(*ret, 52);
	n = 15;
	while (content[i])
	{
		if (content[i] == '#')
			(*ret)[j] |= 1 << n;
		else if (content[i] == '\n')
			n++;
		if (n == 0)
		{
			j++;
			n = 16;
		}
		n--;
		i++;
	}
	ft_replace_tetra(ret, nb_tetra);
}
