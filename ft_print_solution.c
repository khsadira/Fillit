/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:06:20 by schakor           #+#    #+#             */
/*   Updated: 2018/04/08 17:50:22 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_map_init(char **alphabet_map, int square)
{
	int	i;

	if (!(*alphabet_map = (char*)malloc(sizeof(**alphabet_map) * (square *
						square + square))))
	{
		ft_putendl_fd("error", 1);
		exit(1);
	}
	i = 0;
	while (i < square * square + square)
		(*alphabet_map)[i++] = '.';
	i = square;
	while (i < square * square + square)
	{
		(*alphabet_map)[i] = '\n';
		i += square + 1;
	}
}

static void	ft_putfmap(char **map)
{
	ft_putstr(*map);
	free(*map);
}

static int	ft_calc_pos(int ind, int pos[26], int sqr, int i)
{
	return (pos[ind] / 16 + (pos[ind] % 16)
			+ (pos[ind] / 16 * sqr) + ((i * sqr) + i));
}

/*
** Tab[0] = index tetra
** Tab[1] = position tetra;
** Tab[2] = decalage binaire
** Tab[3] = variable a realiser 4 fois
** Tab[4] =
*/

void		ft_characterize_map(int nb_tetra, int pos[26],
			t_uint16 *tetra, int sqr)
{
	int		place;
	int		ind[4];
	char	*alphabet_map;

	ft_map_init(&alphabet_map, sqr);
	ind[0] = -1;
	while (ind[0]++ < nb_tetra)
	{
		ind[1] = 15;
		ind[3] = 0;
		while (ind[1] >= 0)
		{
			place = ft_calc_pos(ind[0], pos, sqr, ind[3]);
			ind[2] = 0;
			while (ind[2]++ < 4)
			{
				if ((tetra[ind[0]] >> ind[1]-- & 1))
					alphabet_map[place] = 'A' + ind[0];
				place++;
			}
			ind[3]++;
		}
	}
	ft_putfmap(&alphabet_map);
}
