/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:55:56 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 22:49:39 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualiser.h"

void	init_visu(t_visu *v)
{
	v->player1.name = NULL;
	v->player2.name = NULL;
	v->player1.score = 0;
	v->player2.score = 0;
	v->player1.color = 5;
	v->player2.color = 4;
	v->map = NULL;
	v->map_x = -1;
	v->map_y = -1;
	v->ymarge = -1;
	v->xmarge = -1;
}

void	init_colors(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, BRIGHT_BLUE, BRIGHT_BLUE);
	init_pair(4, BRIGHT_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, BRIGHT_WHITE, COLOR_BLACK);
}

void	init_marge(t_visu *v)
{
	if (v->map_y == 100)
	{
		v->ymarge = 203;
		v->xmarge = 598;
	}
	else
	{
		v->ymarge = (v->map_y * 2) + 3;
		v->xmarge = (v->map_x * 4) + 5;
	}
}

void	board_window(t_visu *v)
{
	initscr();
	init_colors();
	curs_set(FALSE);
	v->bwin = subwin(stdscr, v->ymarge, v->xmarge, 0, 0);
	wattron(v->bwin, COLOR_PAIR(1));
	box(v->bwin, ACS_S1, ACS_S3);
	wborder(v->bwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(v->bwin, COLOR_PAIR(1));
	get_board(v);
	if (v->map_y == 15)
		show_winner(*v, 23, 18);
	else
		show_winner(*v, 28, 21);
	wrefresh(v->bwin);
	endwin();
	ft_free_visu(v);
}

int		main(void)
{
	t_visu	v;

	init_visu(&v);
	get_player_name(&v);
	get_plateau(&v);
	init_marge(&v);
	menu_window(&v);
	board_window(&v);
	while (1)
		refresh();
	return (0);
}
