/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:16:24 by schakor           #+#    #+#             */
/*   Updated: 2018/01/24 15:31:57 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_is_placable(t_uint16 tetra, t_uint16 *map, int n, int position)
{
	int     line;
	int     col;

	line = position / 16;
	col = position % 16;
	while (line < n)
	{
		while (col < n)
		{
			if (((((tetra & 0xF000) >> col) & (map)[line]) == 0) &&
					(((((tetra << 4) & 0xF000) >> col) & (map)[line + 1]) == 0) &&
					(((((tetra << 8) & 0xF000) >> col) & (map)[line + 2]) == 0) &&
					(((((tetra << 12) & 0xF000) >> col) & (map)[line + 3]) == 0))
				return (line * 16 + col);
			col++;
		}
		col = 0;
		line++;
	}
	return (-1);
}

static void	ft_create_border(t_uint16 *map, int n)
{
	int		i;

	i = 0;
	while (i < n)
		(map)[i++] |= 1 << (15 - n);
	(map)[i] = 0xFFFF;
}

static void	ft_place(t_uint16 tetra, t_uint16 *map, int row, int col)
{
	(map)[row] ^= (tetra & 0xF000) >> col;
	(map)[row + 1] ^= ((tetra << 4) & 0xF000) >> col;
	(map)[row + 2] ^= ((tetra << 8) & 0xF000) >> col;
	(map)[row + 3] ^= ((tetra << 12) & 0xF000) >> col;
}

void	ft_solve(t_uint16 *map, t_uint16 *tetra, int nb_tetra)
{
	int		i;
	int		square;
	int		position[26];

	printf("nombre de tetra = %d\n", nb_tetra);
	square = ft_sqrt(nb_tetra*2*3);
	i = 0;
	while (i < 26)
		position[i++] = 0;
	i = 0;
	while (i < 16)
		map[i++] = 0;
	i = 0;
	ft_create_border(map, square);
	while (i < nb_tetra)
	{
		position[i] = ft_is_placable(tetra[i], map, square, position[i]);
		if (position[i] == -1)
		{
			if (i == 0)
			{
				while (i < 16)
					map[i++] = 0;
				i = 0;
				square++;
				printf("square = %d\n", square);
				ft_create_border(map, square);
				while (i < 26)
					position[i++] = 0;
				i = 0;
			}
			else
			{
				i--;
				ft_place(tetra[i], map, position[i] / 16, position[i] % 16);
				position[i]++;
			}
		}
		else
		{
			ft_place(tetra[i], map, position[i] / 16, position[i] % 16);
			if (i == 4)
			{
				ft_print_map(map);
				ft_putchar(10);
			}
			i++;
			position[i] = 0;
		}
	}
}
