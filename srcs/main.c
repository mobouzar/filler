/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:51:44 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 20:25:17 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	free_heatmap(t_filler *filler)
{
	int	i;

	i = -1;
	if (filler->map_y)
	{
		while (++i < filler->map_x)
			free(filler->h_map[i]);
		free(filler->h_map);
	}
}

void	free_map(char **tab, int x, int y)
{
	int	i;

	i = -1;
	if (y > 0)
	{
		while (++i < x)
			ft_strdel(&tab[i]);
		free(tab);
	}
}

void	ft_free(t_filler filler)
{
	ft_strdel(&filler.me);
	free_map(filler.map, filler.map_x, filler.map_y);
	free_heatmap(&filler);
	ft_strdel(&filler.enemy);
}

void	init_filler(t_filler *filler)
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

int		main(void)
{
	t_filler filler;

	init_filler(&filler);
	if (!who_is_me(&filler))
		return (0);
	while (fill_filler(&filler))
	{
		create_heatmap(&filler);
		trap_enemy(&filler);
		if ((filler.map_x < 20 && filler.me[0] == 'x' &&
		exception_case(&filler)) || get_position(&filler))
		{
			ft_putnbr(filler.position.x);
			ft_putchar(' ');
			ft_putnbr(filler.position.y);
			ft_putchar('\n');
			free_map(filler.piece, filler.p_x, filler.p_y);
		}
		else
			free_map(filler.piece, filler.p_x, filler.p_y);
	}
	ft_free(filler);
	return (0);
}
