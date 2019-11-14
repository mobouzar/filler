/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:38:55 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 22:00:58 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualiser.h"

void	menu00_helper(t_visu v)
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
}

void	menu00(t_visu v)
{
	menu00_helper(v);
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

void	map00_winner(t_visu *v)
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
