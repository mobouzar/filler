/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:14:42 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 23:06:30 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	create_heatmap(t_filler *filler)
{
	int	i;
	int	j;

	i = -1;
	while (++i < filler->map_x)
	{
		j = -1;
		while (++j < filler->map_y)
		{
			if (filler->map[i][j] == '.')
				filler->h_map[i][j] = 0;
			if (ft_strchr(filler->enemy, filler->map[i][j]))
				filler->h_map[i][j] = 1;
		}
	}
}

void	fill_hmap(t_filler *filler, int x, int y, int i)
{
	if (x > 0 && filler->h_map[x - 1][y] == 0)
		filler->h_map[x - 1][y] = i + 1;
	if (y + 1 < filler->map_y && filler->h_map[x][y + 1] == 0)
		filler->h_map[x][y + 1] = i + 1;
	if (x + 1 < filler->map_x && filler->h_map[x + 1][y] == 0)
		filler->h_map[x + 1][y] = i + 1;
	if (y > 0 && filler->h_map[x][y - 1] == 0)
		filler->h_map[x][y - 1] = i + 1;
	if (x > 0 && y > 0 && filler->h_map[x - 1][y - 1] == 0)
		filler->h_map[x - 1][y - 1] = i + 1;
	if (x + 1 < filler->map_x && y + 1 < filler->map_y &&
	filler->h_map[x + 1][y + 1] == 0)
		filler->h_map[x + 1][y + 1] = i + 1;
	if (x + 1 < filler->map_x && y > 0 && filler->h_map[x + 1][y - 1] == 0)
		filler->h_map[x + 1][y - 1] = i + 1;
	if (x > 0 && y + 1 < filler->map_y && filler->h_map[x - 1][y + 1] == 0)
		filler->h_map[x - 1][y + 1] = i + 1;
}

int		check_end(t_filler *f)
{
	int i;
	int j;

	i = -1;
	while (++i < f->map_x)
	{
		j = -1;
		while (++j < f->map_y)
			if (f->h_map[i][j] == 0)
				return (1);
	}
	return (0);
}

void	trap_enemy(t_filler *filler)
{
	int x;
	int y;
	int i;

	x = -1;
	i = 1;
	while (check_end(filler))
	{
		while (++x < filler->map_x)
		{
			y = -1;
			while (++y < filler->map_y)
				if (filler->h_map[x][y] == i)
					fill_hmap(filler, x, y, i);
		}
		x = -1;
		i++;
	}
}
