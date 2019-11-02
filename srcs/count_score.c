/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 01:03:33 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/20 00:13:48 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		count_score(t_filler *filler, int i, int j)
{
	int count;
	int oldj;
	int x;
	int y;

	count = 0;
	oldj = j;
	x = 0;
	y = 0;
	while (x < filler->p_x)
	{
		y = 0;
		while (y < filler->p_y)
		{
			if (filler->piece[x][y] == '*')
				count += filler->h_map[x + i][y + j];
			y++;
		}
		x++;
	}
	return (count);
}
