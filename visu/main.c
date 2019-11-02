/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:55:56 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/01 21:25:14 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

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

void	init_colors()
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, BRIGHT_BLUE, BRIGHT_BLUE);
	init_pair(4, BRIGHT_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, BRIGHT_WHITE, COLOR_BLACK);
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

int		print_map02(t_visu *v, char *c, int y, int x)
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
			{
				v->player1.score++;
				wattron(v->mwin, COLOR_PAIR(5));
				mvwprintw(v->mwin, 12, 20, "%d", v->player1.score);
				wattroff(v->mwin, COLOR_PAIR(5));
				wrefresh(v->mwin);
				v->player1.color = 5;
				
				wattron(v->bwin, COLOR_PAIR(2));
				mvwprintw(v->bwin, y, x, c);
				wattroff(v->bwin, COLOR_PAIR(2));
			}
			else
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
			x += 6;
		}
		y += 2;
	}
	return (1);
}

int		print_map01(t_visu *v, char *c, int y, int x)
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
			else
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
			x += 4;
		}
		y += 2;
	}
	return (1);
}

int		print_map00(t_visu *v, char *c, int y, int x)
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
			else
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
			x += 4;
		}
		y += 2;
	}
	return (1);
}

int		board_window(t_visu *v)
{
	initscr();
	init_colors();
	curs_set(FALSE);
	if (v->map_y == 15)
		v->bwin = subwin(stdscr, (v->map_y * 2) + 3, (v->map_x * 4) + 4, 0, 0);
	else
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
	return (1);
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

int main(int argc, char *argv[])
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

// int		navbar_window(t_visu *v)
// {
// 	initscr();
// 	start_color();
// 	init_pair(1, COLOR_WHITE, COLOR_WHITE);
// 	init_pair(2, COLOR_RED, COLOR_RED);
// 	curs_set(FALSE);

// 	v->nwin = subwin(stdscr, 8, (v->map_x * 2) + 4, 0, 0);

// 	wattron(v->nwin, COLOR_PAIR(1));
// 	box(v->nwin, ACS_S1, ACS_S3);
// 	wborder(v->nwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
// 	wattroff(v->nwin, COLOR_PAIR(1));


// 	// wattron(v->nwin, COLOR_PAIR(2));
// 	mvwprintw(v->nwin, 3, 20, "PLAYER 1: ");
// 	mvwprintw(v->nwin, 3, 30, v->player1);
// 	mvwprintw(v->nwin, 3, 50, "PLAYER 2: ");
// 	mvwprintw(v->nwin, 3, 60, v->player2);
// 	// wattroff(v->nwin, COLOR_PAIR(2));

// 	wrefresh(v->nwin);
// 	endwin();
// 	return (1);
// }