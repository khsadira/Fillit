/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:16:24 by schakor           #+#    #+#             */
/*   Updated: 2018/01/24 15:38:44 by khsadira         ###   ########.fr       */
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

static void	ft_characterize_map(int nb_tetra, int position[26], t_uint16 *tetra, int square)
{
	int	i;
	int	a;
	char	*alphabet_map;
	int	suite;
	int	count;
	int	j;

	alphabet_map = (char*)malloc(sizeof(*alphabet_map) * (square * square + square) * square * square);
	i = 0;
	while (i < square * square + square)
		alphabet_map[i++] = '.';
	i = square;
	while (i < square * square + square)
	{
		alphabet_map[i] = '\n';
		i += square + 1;
	}
	ft_putchar(10);
	ft_putstr(alphabet_map);
	ft_putchar(10);
	i = 0;
	while (i < nb_tetra)
	{
		suite = 15;
		j = 0;
		while (suite >= 0)
		{
			a = (position[i] / 16 * square) + (position[i] % 16) + position[i] / 16 + ((j * square) + j);
			count = 0;
			while (count < 4)
			{
				if ((tetra[i] >> suite & 1))
					alphabet_map[a] = 'A' + i;
				count++;
				a++;
				suite--;
			}
			j++;
		}
		i++;
	}
/*	while (i < 2)
	{
		suite = 15;
		a = (position[i] / 16 * square) + (position[i] % 16) + position[i] / 16;
		while (suite >= 0)
		{
			if (alphabet_map[a] == '\n' || (suite != 15 && suite % 4 == 3))
			{
				a = (position[i] / 16 * square) + (position[i] % 16) + position[i] / 16 + square + 1;
				suite -= suite % 4 + 1; 
			}
		//	if (suite != 15 && suite % 4 == 3)
		//		a += 1;
			if ((tetra[i] >> suite & 1))
				alphabet_map[a] = 'A' + i;
			printf("suite = %d ||| a = %d\n",suite,a);
			a++;
			suite--;
		}
		i++;
	}*/
	ft_putchar(10);
	ft_putstr(alphabet_map);
	ft_putchar(10);
}

static int	ft_minimal_map(int nb_tetra, t_uint16 *tetra)
{
	int	i;
	int	square;
	int	taille_tetra[3];
	
	square = 0;
	i = 0;
	while (i < nb_tetra)
	{
		if (tetra[i] == 0xcc00)
			square += 4;
		else
			square += 5;
		i++;
	}
	return (square);
}

static void	ft_reset_map(t_uint16 *map)
{
	int	i;

	i = 0;
	while (i < 16)
		map[i++] = 0;
}

void	ft_solve(t_uint16 *map, t_uint16 *tetra, int nb_tetra)
{
	int		i;
	int		square;
	int		position[26];

	printf("nombre de tetra = %d\n", nb_tetra);
	square = ft_sqrt(nb_tetra*5);
	ft_putchar(10);
	ft_putstr("On commence avec un square de : ");
	ft_putnbr(square);
	ft_putchar(10);
	i = 0;
	while (i < 26)
		position[i++] = 0;
	ft_reset_map(map);
	i = 0;
	ft_create_border(map, square);
	while (i < nb_tetra)
	{
		position[i] = ft_is_placable(tetra[i], map, square, position[i]);
		if (position[i] == -1)
		{
			if (i == 0)
			{
				ft_reset_map(map);
				printf("square = %d\n", square);
				ft_create_border(map, ++square);
				while (i < 26)
					position[i++] = 0;
				i = 0;
			}
			else
			{
				i--;
				ft_place(tetra[i], map, position[i] / 16, position[i]++ % 16);
			}
		}
		else
		{
			ft_place(tetra[i], map, position[i] / 16, position[i] % 16);
			if (i == 1)
			{
				ft_print_map(map);
				ft_putchar(10);
			}
			position[++i] = 0;
		}
	}
	ft_putchar(10);
	ft_putstr("Nous avons : ");
	ft_putnbr(square);
	ft_putchar(10);
	ft_print_map(map);
	ft_characterize_map(nb_tetra, position, tetra, square);
}
