/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:29:22 by schakor           #+#    #+#             */
/*   Updated: 2018/01/09 16:16:06 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_is_placable(t_uint16 tetra, t_uint16 *cpy, int n)
{
	int		line;
	int		col;

	line = 0;
	while (line < n)
	{
		col = 0;
		while (col < n)
		{
			if (((((tetra & 0xF000) >> col) & cpy[line]) == 0) &&
				(((((tetra << 4) & 0xF000) >> col) & cpy[line + 1]) == 0) &&
				(((((tetra << 8) & 0xF000) >> col) & cpy[line + 2]) == 0) &&
				(((((tetra << 12) & 0xF000) >> col) & cpy[line + 3]) == 0))
			{
				printf("\nline = %d, col = %d, i = %d\n",line,col, line*16+col);
				return (line * 16 + col);
			}
			col++;
		}
		line++;
	}
	return (0);
}

static int	ft_check_place_tetra(t_uint16 tetra, t_uint16 *map)
{
	t_uint16	*cpy;
	int			i;
	static int	n;
	int			ret;

	if (!(cpy = (t_uint16 *)malloc(sizeof(*cpy) * 16)))
		return (0);
	ft_memcpy(cpy, map, 16 * sizeof(t_uint16));
	n = 0;
	while (n < 16)
	{
		if ((ret = ft_is_placable(tetra, cpy, n)))
			return (ret);
		else
		{
			printf("n = %d\n", n);
			n++;
			i = 2;
			while (i < n - 1)
			{
				cpy[i] = 1 << (16 - i);
				printf("cpy[%d] = %#x\n", i, cpy[i]);
				i++;
			}
			cpy[i] = 0xFFFF;
			printf("cpy[%d] = %#x\n", i, cpy[i]);
		}
	}
	return (0);
}

static void	ft_place_tetra(t_uint16 tetra, t_uint16 *map)
{
	int		i;
	int		col;
	int		line;

	i = ft_check_place_tetra(tetra, map);
	printf("\ni = %d\n", i);
	col = i % 16;
	line = (i - col) / 16;
	map[line] |= (tetra & 0xF000) >> col;
	map[line + 1] |= ((tetra << 4) & 0xF000) >> col;
	map[line + 2] |= ((tetra << 8) & 0xF000) >> col;
	map[line + 3] |= ((tetra << 12) & 0xF000) >> col;
}

void	ft_solve(t_uint16 *tetra, int nb_tetra)
{
	t_uint16	*map;
	int			i;

	i = 0;
	if (!(map = (t_uint16 *)malloc(sizeof(*map) * 16)))
		return ;
	while (i < 16)
		map[i++] = 0;
	map[0] = 0xF000;
	map[1] = 0xe000;
	map[2] = 0xe000;
	map[3] = 0xc000;
	i = 0;
	//while (i < nb_tetra)
	//	ft_place_tetra(tetra[i++], map);
	ft_place_tetra(tetra[3], map);
	printf("\n\nret[0] = %#x\nret[1] = %#x\nret[2] = %#x\nret[3] = %#x\nret[4] = %#x\n", map[0], map[1], map[2], map[3], map[4]);
}
