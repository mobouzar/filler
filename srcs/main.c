/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:51:44 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/29 00:28:55 by mobouzar         ###   ########.fr       */
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
	  	// system("clear");
		// usleep(100);
		fill_heat_map(&filler);
		trap_enemy(&filler);
		if ((filler.map_x < 25 && filler.me[0] == 'x' && exception_case(&filler)) || get_position(&filler))
		{
			// ft_putnbr(filler.map_x);
			ft_putchar('\n');
			ft_putnbr(filler.position.x);
			ft_putchar(' ');
			ft_putnbr(filler.position.y);
			ft_putchar('\n');
		}
	}
	// char	*line;
	// int 	fd;

	// fd = open("test3", O_WRONLY);
	// while (get_next_line(0, &line))
	// {
	// 	ft_putendl_fd(line, fd);
	// }
	return (0);
}
