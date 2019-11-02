/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:14:42 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/18 20:47:24 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		create_heat_map(t_filler *filler)
{
	int	x;
	int	i;

	i = 0;
	x = filler->map_x;
	if (!(filler->h_map = (int **)malloc(sizeof(int *) * x)))
		return (0);
	while (x--)
		if (!(filler->h_map[i++] = (int *)malloc(sizeof(int) * filler->map_y)))
			return (0);
	return (1);
}

void	fill_heat_map(t_filler *filler)
{
	int	i;
	int	j;

	i = -1;
	if (!(create_heat_map(filler)))
		return ;
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
