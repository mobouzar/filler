/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:05:39 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/01 20:09:10 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	menu02(t_visu v)
{
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 3, 1, "=======================================");
    mvwprintw(v.mwin, 3, 40, "=======================================");
	mvwprintw(v.mwin, 5, 2, "================================== VISUALISE");
    mvwprintw(v.mwin, 5, 46, "R ==============================");
	mvwprintw(v.mwin, 7, 1, "=============================================");
    mvwprintw(v.mwin, 7, 46, "=================================");
	wattroff(v.mwin, COLOR_PAIR(6));
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 10, 8, "PLAYER 1 : ");
	wattroff(v.mwin, COLOR_PAIR(6));
	wattron(v.mwin, COLOR_PAIR(5));
	mvwprintw(v.mwin, 10, 20, v.player1.name);
	wattroff(v.mwin, COLOR_PAIR(5));
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 12, 8, "SCORE 1  : ");
	wattroff(v.mwin, COLOR_PAIR(6));
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 16, 2, "================================= VS =");
    mvwprintw(v.mwin, 16, 40, "======================================");
	wattroff(v.mwin, COLOR_PAIR(6));
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 20, 8, "PLAYER 2 : ");
	wattroff(v.mwin, COLOR_PAIR(6));
	wattron(v.mwin, COLOR_PAIR(4));
	mvwprintw(v.mwin, 20, 20, v.player2.name);
	wattroff(v.mwin, COLOR_PAIR(4));
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 22, 8, "SCORE 2  : ");
	wattroff(v.mwin, COLOR_PAIR(6));
}

void	menu01(t_visu v)
{
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 1, 16, "FILLER");
	mvwprintw(v.mwin, 5, 2, "=========== VISUALISER =============");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(1));
	mvwprintw(v.mwin, 3, 1, "======================================");
	mvwprintw(v.mwin, 7, 1, "======================================");
	wattroff(v.mwin, COLOR_PAIR(1));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 10, 8, "PLAYER 1 : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(5));
	mvwprintw(v.mwin, 10, 20, v.player1.name);
	wattroff(v.mwin, COLOR_PAIR(5));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 12, 8, "SCORE 1  : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 16, 2, "=============== VS =================");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 20, 8, "PLAYER 2 : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(4));
	mvwprintw(v.mwin, 20, 20, v.player2.name);
	wattroff(v.mwin, COLOR_PAIR(4));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 22, 8, "SCORE 2  : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(1));
	mvwprintw(v.mwin, 25, 1, "======================================");
	wattroff(v.mwin, COLOR_PAIR(1));
}

void	menu00(t_visu v)
{
	wattron(v.mwin, COLOR_PAIR(1));
	mvwprintw(v.mwin, 3, 1, "============================");
	mvwprintw(v.mwin, 7, 1, "============================");
	wattroff(v.mwin, COLOR_PAIR(1));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 1, 12, "FILLER");
	mvwprintw(v.mwin, 5, 2, "======= VISUALISER =======");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 10, 3, "PLAYER 1 : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(5));
	mvwprintw(v.mwin, 10, 15, v.player1.name);
	wattroff(v.mwin, COLOR_PAIR(5));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 12, 3, "SCORE 1  : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 14, 2, "=========== VS ===========");
	wattroff(v.mwin, COLOR_PAIR(6));
	
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 16, 3, "PLAYER 2 : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(4));
	mvwprintw(v.mwin, 16, 15, v.player2.name);
	wattroff(v.mwin, COLOR_PAIR(4));
	

	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 18, 3, "SCORE 2  : ");
	wattroff(v.mwin, COLOR_PAIR(6));

	wattron(v.mwin, COLOR_PAIR(1));
	mvwprintw(v.mwin, 20, 1, "============================");
	wattroff(v.mwin, COLOR_PAIR(1));
}

int		menu_window(t_visu *v)
{
	int	x;
	int	y;

	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
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

	if (v->map_y == 15)
	{
		wattron(v->mwin, COLOR_PAIR(6));
		mvwprintw(v->mwin, 23, 2, "THE WINNER IS : ");
		wattroff(v->mwin, COLOR_PAIR(6));


		wattron(v->mwin, COLOR_PAIR(6));
		mvwprintw(v->mwin, 30, 6, "By : MOBOUZAR");
		wattroff(v->mwin, COLOR_PAIR(6));
		
		wattron(v->mwin, COLOR_PAIR(1));
		mvwprintw(v->mwin, 28, 1, "============================");
		wattroff(v->mwin, COLOR_PAIR(1));
	}
	else if (v->map_y == 24)
	{
		wattron(v->mwin, COLOR_PAIR(6));
		mvwprintw(v->mwin, 28, 5, "THE WINNER IS : ");
		wattroff(v->mwin, COLOR_PAIR(6));


		wattron(v->mwin, COLOR_PAIR(6));
		mvwprintw(v->mwin, 48, 10, "By : MOBOUZAR");
		wattroff(v->mwin, COLOR_PAIR(6));
		
		wattron(v->mwin, COLOR_PAIR(1));
		mvwprintw(v->mwin, 46, 1, "======================================");
		wattroff(v->mwin, COLOR_PAIR(1));
	}
	else
	{
		wattron(v->mwin, COLOR_PAIR(6));
		mvwprintw(v->mwin, 28, 5, "THE WINNER IS : ");
		wattroff(v->mwin, COLOR_PAIR(6));


		wattron(v->mwin, COLOR_PAIR(6));
		mvwprintw(v->mwin, 48, 10, "By : MOBOUZAR");
		wattroff(v->mwin, COLOR_PAIR(6));
		
		wattron(v->mwin, COLOR_PAIR(1));
		mvwprintw(v->mwin, 36, 1, "======================================");
		wattroff(v->mwin, COLOR_PAIR(1));
	}
	

	wrefresh(v->mwin);
	endwin();
	return (1);
}