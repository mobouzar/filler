/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:06:24 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/05 19:13:30 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	menu02_helper(t_visu v)
{
	wattron(v.mwin, COLOR_PAIR(1));
	mvwprintw(v.mwin, 3, 1, "=======================================");
	mvwprintw(v.mwin, 3, 40, "=======================================");
	wattroff(v.mwin, COLOR_PAIR(1));
	wattron(v.mwin, COLOR_PAIR(6));
	mvwprintw(v.mwin, 5, 2, "================================== VISUALISE");
	mvwprintw(v.mwin, 5, 46, "R ==============================");
	wattroff(v.mwin, COLOR_PAIR(6));
	wattron(v.mwin, COLOR_PAIR(1));
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
}

void	menu02(t_visu v)
{
	menu02_helper(v);
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
	wattron(v.mwin, COLOR_PAIR(1));
	mvwprintw(v.mwin, 26, 1, "=========================================");
	mvwprintw(v.mwin, 26, 42, "======================================");
	wattroff(v.mwin, COLOR_PAIR(1));
}

void	map02_winner(t_visu *v)
{
	wattron(v->mwin, COLOR_PAIR(6));
	mvwprintw(v->mwin, 36, 5, "THE WINNER IS : ");
	wattroff(v->mwin, COLOR_PAIR(6));
	wattron(v->mwin, COLOR_PAIR(6));
	mvwprintw(v->mwin, 195, 30, "By : MOBOUZAR");
	wattroff(v->mwin, COLOR_PAIR(6));
	wattron(v->mwin, COLOR_PAIR(1));
	mvwprintw(v->mwin, 190, 1, "=========================================");
	mvwprintw(v->mwin, 190, 42, "======================================");
	wattroff(v->mwin, COLOR_PAIR(1));
}
