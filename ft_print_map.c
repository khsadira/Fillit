/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:54:26 by khsadira          #+#    #+#             */
/*   Updated: 2018/01/11 10:58:29 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_print_bits(t_uint16 nb)
{
	int			n;
	t_uint16	tmp;

	n = 15;
	while (n >= 0)
	{
		tmp = (nb >> n) & 1;
		if (tmp)
			ft_putchar(49);
		else
			ft_putchar(48);
		n--;
	}
}

void	ft_print_map(t_uint16 *map)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		ft_print_bits(map[i++]);
		ft_putchar(10);
	}
}
