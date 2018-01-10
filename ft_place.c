/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:16:24 by schakor           #+#    #+#             */
/*   Updated: 2018/01/10 16:44:34 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_is_placable(t_uint16 tetra, t_uint16 **cpy, int n)
{
	int     line;
	int     col;

	line = 0;
	while (line < n)
	{
		col = 0;
		while (col < n)
		{
			if (((((tetra & 0xF000) >> col) & (*cpy)[line]) == 0) &&
					(((((tetra << 4) & 0xF000) >> col) & (*cpy)[line + 1]) == 0) &&
					(((((tetra << 8) & 0xF000) >> col) & (*cpy)[line + 2]) == 0) &&
					(((((tetra << 12) & 0xF000) >> col) & (*cpy)[line + 3]) == 0))
				return (line * 16 + col);
			col++;
		}
		line++;
	}
	return (-1);
}

void	ft_create_border(t_uint16 **map, int n)
{
	int		i;

	i = 0;
	while (i < n)
		(*map)[i++] |= 1 << (15 - n);
	(*map)[i] = 0xFFFF;
}

void	ft_delete_border(t_uint16 **map, int n)
{
	int		i;

	i = 0;
	while (i < n)
		(*map)[i++] ^= 1 << (15 - n);
	(*map)[i] = 0x0000;
}

void	ft_place(t_uint16 tetra, t_uint16 **map, int row, int col)
{
	(*map)[row] ^= (tetra & 0xF000) >> col;
	(*map)[row + 1] ^= ((tetra << 4) & 0xF000) >> col;
	(*map)[row + 2] ^= ((tetra << 8) & 0xF000) >> col;
	(*map)[row + 3] ^= ((tetra << 12) & 0xF000) >> col;
}

void	ft_print_bits(t_uint16 nb)
{
	int			n;
	t_uint16	tmp;
	n = 15;
	while (n >= 0)
	{
		tmp = (nb >> n) & 1;
		if (tmp)
			printf("1");
		else
			printf("0");
		n--;
	}
}

void	ft_print_map(t_uint16 *map)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		ft_print_bits(map[i++]);
		printf("\n");
	}
}

int		main(void)
{
	t_uint16	*map;
	int			i;

	if (!(map = (t_uint16 *)malloc(sizeof(*map) * 16)))
		return (0);
	i = 0;
	while (i < 16)
		map[i++] = 0;
	ft_create_border(&map, 5);
	ft_place(0xF000, &map, 0, 0);
	ft_place(0xF000, &map, 1, 0);
	ft_place(0x8888, &map, 0, 4);
	ft_place(0x88c0, &map, 2, 0);
	ft_place(0x4E00, &map, 3, 2);
	ft_place(0x4000, &map, 2, 0);
	printf("i = %d\n",ft_is_placable((0x6C00), &map, 4));

	ft_place(0x6C00, &map, 33/16, 33%16);
	ft_print_map(map);
	printf("\n\n");
	ft_print_map(map);
	return (0);
}
