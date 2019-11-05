/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:22:02 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/05 18:33:57 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	print_obox0(t_visu *v, char *c, int y, int x)
{
	v->player1.score++;
	wattron(v->mwin, COLOR_PAIR(5));
	mvwprintw(v->mwin, 12, 15, "%d", v->player1.score);
	wattroff(v->mwin, COLOR_PAIR(5));
	wrefresh(v->mwin);
	v->player1.color = 5;
	wattron(v->bwin, COLOR_PAIR(2));
	mvwprintw(v->bwin, y, x, c);
	wattroff(v->bwin, COLOR_PAIR(2));
}

void	print_xbox0(t_visu *v, char *c, int y, int x)
{
	v->player2.score++;
	wattron(v->mwin, COLOR_PAIR(4));
	mvwprintw(v->mwin, 18, 15, "%d", v->player2.score);
	wattroff(v->mwin, COLOR_PAIR(4));
	wrefresh(v->mwin);
	v->player2.color = 4;
	wattron(v->bwin, COLOR_PAIR(3));
	mvwprintw(v->bwin, y, x, c);
	wattroff(v->bwin, COLOR_PAIR(3));
}

void	print_map00(t_visu *v, char *c, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	init_colors();
	while (++i < v->map_y)
	{
		j = -1;
		x = 3;
		while (++j < v->map_x)
		{
			if (v->map[i][j] == '.')
			{
				wattron(v->bwin, COLOR_PAIR(1));
				mvwprintw(v->bwin, y, x, c);
				wattroff(v->bwin, COLOR_PAIR(1));
			}
			else if (ft_toupper(v->map[i][j]) == 'O')
				print_obox0(v, c, y, x);
			else
				print_xbox0(v, c, y, x);
			x += 4;
		}
		y += 2;
	}
}
