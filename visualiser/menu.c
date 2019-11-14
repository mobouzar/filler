/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:05:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 22:48:25 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualiser.h"

void	ft_free_visu(t_visu *v)
{
	ft_free(v->map);
	ft_strdel(&v->player1.name);
	ft_strdel(&v->player2.name);
	free(v->bwin);
	free(v->mwin);
}

void	show_winner(t_visu v, int y, int x)
{
	if (v.player1.score > v.player2.score)
	{
		wattron(v.mwin, COLOR_PAIR(v.player1.color));
		mvwprintw(v.mwin, y, x, "%s", v.player1.name);
		wattroff(v.mwin, COLOR_PAIR(v.player1.color));
	}
	else
	{
		wattron(v.mwin, COLOR_PAIR(v.player2.color));
		mvwprintw(v.mwin, y, x, "%s", v.player2.name);
		wattroff(v.mwin, COLOR_PAIR(v.player2.color));
	}
}

void	get_winner(t_visu *v)
{
	if (v->map_y == 15)
		map00_winner(v);
	else if (v->map_y == 24)
		map01_winner(v);
	else
		map02_winner(v);
}

int		menu_window(t_visu *v)
{
	initscr();
	init_colors();
	curs_set(FALSE);
	if (v->map_y == 15)
		v->mwin = subwin(stdscr, v->ymarge, 30, 0, v->xmarge);
	else if (v->map_y == 24)
		v->mwin = subwin(stdscr, v->ymarge, 40, 0, v->xmarge + 1);
	else
		v->mwin = subwin(stdscr, v->ymarge, 80, 0, v->xmarge + 1);
	wattron(v->mwin, COLOR_PAIR(1));
	box(v->mwin, ACS_S1, ACS_S3);
	wborder(v->mwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(v->mwin, COLOR_PAIR(1));
	if (v->map_y == 15)
		menu00(*v);
	else if (v->map_y == 24)
		menu01(*v);
	else
		menu02(*v);
	get_winner(v);
	wrefresh(v->mwin);
	endwin();
	return (1);
}
