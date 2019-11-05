/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:27:33 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/05 18:35:35 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	print_obox1(t_visu *v, char *c, int y, int x)
{
	v->player1.score += 1;
	wattron(v->mwin, COLOR_PAIR(5));
	mvwprintw(v->mwin, 12, 20, "%d", v->player1.score);
	wattroff(v->mwin, COLOR_PAIR(5));
	wrefresh(v->mwin);
	v->player1.color = 5;
	wattron(v->bwin, COLOR_PAIR(2));
	mvwprintw(v->bwin, y, x, c);
	wattroff(v->bwin, COLOR_PAIR(2));
}

void	print_xbox1(t_visu *v, char *c, int y, int x)
{
	v->player2.score++;
	wattron(v->mwin, COLOR_PAIR(4));
	mvwprintw(v->mwin, 22, 20, "%d", v->player2.score);
	wattroff(v->mwin, COLOR_PAIR(4));
	wrefresh(v->mwin);
	v->player2.color = 4;
	wattron(v->bwin, COLOR_PAIR(3));
	mvwprintw(v->bwin, y, x, c);
	wattroff(v->bwin, COLOR_PAIR(3));
}

void	print_map01(t_visu *v, char *c, int y, int x)
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
				print_obox1(v, c, y, x);
			else
				print_xbox1(v, c, y, x);
			x += 4;
		}
		y += 2;
	}
}
