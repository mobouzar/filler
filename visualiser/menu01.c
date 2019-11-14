/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:40:57 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 22:00:59 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualiser.h"

void	menu01_helper(t_visu v)
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
}

void	menu01(t_visu v)
{
	menu01_helper(v);
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

void	map01_winner(t_visu *v)
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
