/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:18:08 by schakor           #+#    #+#             */
/*   Updated: 2018/02/06 17:22:03 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_err(void)
{
	ft_putendl_fd("error", 1);
	exit(1);
}

int		main(int ac, char **av)
{
	t_uint16	*map;
	t_uint16	*ret;
	char		*content;

	if (!(map = (t_uint16 *)malloc(sizeof(*map) * 16)))
		return (0);
	if (ac != 2)
	{
		ft_putendl_fd("./fillit test.fillit", 1);
		return (0);
	}
	content = ft_read_file(av[1]);
	ft_treat_file(content, &ret);
	if (ft_check_tetra(ret, (ft_strlen(content) + 1) / 21) == 0)
	{
		ft_putendl_fd("error", 1);
		return (0);
	}
	ft_solve(map, ret, (ft_strlen(content) + 1) / 21);
	free (ret);
	free (content);	
	free (map);
	return (0);
}
