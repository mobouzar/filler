/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:04:30 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/06 00:19:46 by mobouzar         ###   ########.fr       */
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
	if (x + filler->p_x > filler->map_x || y + filler->p_y > filler->map_y)
		return (0);
	while (++i < filler->p_x)
	{
		j = -1;
		while (++j < filler->p_y)
		{
			if ((ft_tolower(filler->map[x + i][y + j]) == filler->me[0]) && filler->piece[i][j] == '*')
				count++;
			else if (ft_tolower(filler->map[x + i][y + j]) == filler->enemy[0] && filler->piece[i][j] == '*')
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

	j = filler->map_y - 1;
	filler->position.x = -1;
	filler->position.y = -1;
	while (j >= (filler->map_y / 4) * 3)
	{
		i = -1;
		while (++i < filler->map_x)
		{
			// ft_putendl_fd("lool", 2);
			if (is_placeable(filler, i, j) == 1)
			{
				filler->position.x = i;
				filler->position.y = j;
				return (1);
			}
		}
		j--;
	}
	if (filler->position.x > -1)
		return (1);
	return (0);
}
