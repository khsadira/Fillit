/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:16:24 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 16:38:17 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_is_placable(t_uint16 tetra, t_uint16 *map,
								int n, int position)
{
	int	lin;
	int	col;

	lin = position / 16;
	col = position % 16;
	while (lin < n)
	{
		while (col < n)
		{
			if (((((tetra & 0xF000) >> col) & map[lin]) == 0) &&
					(((((tetra << 4) & 0xF000) >> col) & map[lin + 1]) == 0) &&
					(((((tetra << 8) & 0xF000) >> col) & map[lin + 2]) == 0) &&
					(((((tetra << 12) & 0xF000) >> col) & map[lin + 3]) == 0))
				return (lin * 16 + col);
			col++;
		}
		col = 0;
		lin++;
	}
	return (-1);
}

static void		ft_create_border(t_uint16 *map, int n)
{
	int		i;

	i = 0;
	while (i < n)
		(map)[i++] |= 1 << (15 - n);
	(map)[i] = 0xFFFF;
}

static void		ft_place(t_uint16 tetra, t_uint16 *map, int row, int col)
{
	(map)[row] ^= (tetra & 0xF000) >> col;
	(map)[row + 1] ^= ((tetra << 4) & 0xF000) >> col;
	(map)[row + 2] ^= ((tetra << 8) & 0xF000) >> col;
	(map)[row + 3] ^= ((tetra << 12) & 0xF000) >> col;
}

static void		ft_reduce(t_uint16 *map, int *pos, int square)
{
	ft_reset_int(pos);
	ft_reset_tuint16(map);
	ft_create_border(map, square);
}

void			ft_solve(t_uint16 *map, t_uint16 *tetra, int nb_tetra)
{
	int		i;
	int		square;
	int		position[26];

	square = ft_sqrt(nb_tetra * 4);
	ft_reduce(map, position, square);
	i = 0;
	while (i < nb_tetra)
	{
		position[i] = ft_is_placable(tetra[i], map, square, position[i]);
		if (position[i] == -1 && i == 0)
			ft_reduce(map, position, ++square);
		else if (position[i] == -1)
		{
			i--;
			ft_place(tetra[i], map, position[i] / 16, position[i]++ % 16);
		}
		else
		{
			ft_place(tetra[i], map, position[i] / 16, position[i] % 16);
			position[++i] = 0;
		}
	}
	ft_characterize_map(nb_tetra, position, tetra, square);
}
