/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:59:45 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 17:30:23 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_replace_tetra(t_uint16 **ret, int nb_tetra)
{
	int	a;

	a = 0;
	while (a < nb_tetra)
	{
		if ((*ret)[a] == 0)
		{
			ft_putendl_fd("error", 1);
			exit(1);
		}
		a++;
	}
	a = 0;
	while (a < nb_tetra)
	{
		while (((*ret)[a] & 0x8888) == 0)
			(*ret)[a] <<= 1;
		while (((*ret)[a] & 0xf000) == 0)
			(*ret)[a] <<= 4;
		a++;
	}
}

static void	ft_check_file(char *cont)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (cont[i])
	{
		if (cont[i] == '\n')
		{
			count++;
			if (count == 4 && (cont[i + 1] == '\n' || cont[i + 1] == '\0'))
			{
				i += 2;
				count = 0;
			}
			else if (count == 4)
				ft_print_err();
			else
				i++;
		}
		else if (cont[i] == '.' || cont[i] == '#')
			i++;
		else
			ft_print_err();
	}
}

void		ft_treat_file(char *content, t_uint16 **ret)
{
	int			n;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_check_file(content);
	*ret = (t_uint16 *)ft_memalloc(52);
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
	ft_replace_tetra(ret, (ft_strlen(content) + 1) / 21);
}
