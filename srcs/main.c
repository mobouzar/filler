/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:51:44 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/06 00:25:23 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <stdio.h>

void init_filler(t_filler *filler)
{
	filler->enemy = NULL;
	filler->me = NULL;
	filler->map = NULL;
	filler->piece = NULL;
	filler->map_x = -1;
	filler->map_y = -1;
	filler->p_x = -1;
	filler->p_y = -1;
	filler->position.x = -1;
	filler->position.y = -1;
}

int main()
{
	t_filler filler;
	init_filler(&filler);
	who_is_me(&filler);
	while (fill_filler(&filler))
	{
		fill_heat_map(&filler);
		trap_enemy(&filler);
		if ((filler.map_x < 25 && filler.me[0] == 'x' && (!ft_strchr(filler.map[0], 'x') || !ft_strchr(filler.map[0], 'X')) && exception_case(&filler)) || get_position(&filler))
		{
			ft_putnbr(filler.position.x);
			ft_putchar(' ');
			ft_putnbr(filler.position.y);
			ft_putchar('\n');

			// ft_putchar_fd('\n', 2);
			// ft_putnbr_fd(filler.position.x, 2);
			// ft_putchar_fd(' ', 2);
			// ft_putnbr_fd(filler.position.y, 2);
			// ft_putchar_fd('\n', 2);
		}
	}
	return (0);
}
