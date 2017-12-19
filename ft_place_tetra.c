/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:29:22 by schakor           #+#    #+#             */
/*   Updated: 2017/12/19 13:00:02 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_place_tetra(t_uint16 tetra, t_uint tab[16])
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if ()
			break;
		++i;
	}
	return (i);
}

static void	ft_place_tetra(t_uint16 tetra, t_uint16 tab[16])
{
	t_uint16	mask;
	int			count;
	
	i = ft_check_place_tetra(tetra, tab);
	mask = 0xf000;
	while (count < 4)
	{
		tab[i++] = tetra & mask;
		mask >>= 4;
		count++;
	}
}

void	ft_solve(t_uint16 *tetra, int nb_tetra)
{
	t_uint16	tab[16];
	int			i;

	i = 0;
	while (i < 16)
		tab[i++] = 0x0000;
	i = 0;
	while (i < nb_tetra)
		ft_place_tetra(tetra[i++], tab);

}
