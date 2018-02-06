/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:06:20 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 17:20:17 by schakor          ###   ########.fr       */
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

void		ft_characterize_map(int nb_tetra, int position[26],
			t_uint16 *tetra, int square)
{
	int		tab[5];
	char	*alphabet_map;

	ft_map_init(&alphabet_map, square);
	tab[0] = -1;
	while (tab[0]++ < nb_tetra)
	{
		tab[2] = 15;
		tab[4] = 0;
		while (tab[2] >= 0)
		{
			tab[1] = (position[tab[0]] / 16 * square) + (position[tab[0]] % 16)
				+ position[tab[0]] / 16 + ((tab[4] * square) + tab[4]);
			tab[3] = 0;
			while (tab[3]++ < 4)
			{
				if ((tetra[tab[0]] >> tab[2]-- & 1))
					alphabet_map[tab[1]] = 'A' + tab[0];
				tab[1]++;
			}
			tab[4]++;
		}
	}
	ft_putstr(alphabet_map);
}
