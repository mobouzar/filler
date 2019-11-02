/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:04:30 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/20 00:59:21 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		is_placeable(t_filler *filler, int x, int y)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	if (x + filler->p_x >= filler->map_x || y + filler->p_y >= filler->map_y)
		return (0);
	while (++i < filler->p_x)
	{
		j = -1;
		while (++j < filler->p_y)
		{
			if ((filler->map[x + i][y + j] == filler->me[0] || filler->map[x + i][y + j] == filler->me[1])
			&& filler->piece[i][j] == '*')
				count++;
			else if (filler->map[x + i][y + j] != '.' && filler->piece[i][j] == '*')
				return (0);
		}
	}
	return (count);
}

int		get_position(t_filler *filler)
{
	int i;
	int j;
	int score;
	int tmp_score;

	i = 0;
	tmp_score = INT_MAX;
	while (i < filler->map_x)
	{
		j = -1;
		while (++j < filler->map_y)
		{
			if (is_placeable(filler, i, j) == 1)
			{
				score = count_score(filler, i, j);
				if (score <= tmp_score)
				{
					tmp_score = score;
					filler->position.x = i;
					filler->position.y = j;
				}
			}
		}
		i++;
	}
	return (1);
}

int		exception_case(t_filler *filler)
{
	int i;
	int	j;

	filler->position.x = -1;
	filler->position.y = -1;
	i = -1;
	while (++i < filler->map_x)
	{
		j = filler->map_y;
		while (--j >= (filler->map_y / 2))
		{
			if (is_placeable(filler, i, j) == 1)
			{
				filler->position.x = i;
				filler->position.y = j;
				break ;
			}
		}
	}
	if (filler->position.x > -1)
		return (1);
	return (0);
}
