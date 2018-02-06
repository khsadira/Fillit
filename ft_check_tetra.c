/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:17:34 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 14:56:28 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_check_tetra(t_uint16 *tetra, int nb_tetra)
{
	int	i;

	i = 0;
	while (i < nb_tetra)
	{
		if (tetra[i] != 0xf000 && tetra[i] != 0x8888 && tetra[i] != 0xcc00 &&
			tetra[i] != 0x4c40 && tetra[i] != 0x8c80 && tetra[i] != 0xe400 &&
			tetra[i] != 0x4e00 && tetra[i] != 0x44c0 && tetra[i] != 0x8e00 &&
			tetra[i] != 0xe200 && tetra[i] != 0xc880 && tetra[i] != 0x88c0 &&
			tetra[i] != 0xe800 && tetra[i] != 0xc440 && tetra[i] != 0x2e00 &&
			tetra[i] != 0x6c00 && tetra[i] != 0x8c40 && tetra[i] != 0xc600 &&
			tetra[i] != 0x4c80)
			return (0);
		i++;
	}
	return (1);
}
