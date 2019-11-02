/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:21:09 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/31 13:38:06 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISER_H
# define VISUALISER_H

# include "../inc/filler.h"
# include <ncurses.h>
# include <unistd.h>

#define BRIGHT_BLUE 28
#define BRIGHT_WHITE 15

typedef struct	s_player1
{
	char		*name;
	int			score;
	int			color;
}				t_player1;

typedef struct	s_player2
{
	char		*name;
	int			score;
	int			color;
}				t_player2;

typedef struct	s_visu
{
	WINDOW		*bwin;
	WINDOW		*mwin;
	t_player1	player1;
	t_player2	player2;
	char		**map;
	int			map_x;
	int			map_y;
	int			xmarge;
	int			ymarge;
	// int			xscore;
	// int			oscore;
	
}				t_visu;

void	get_player_name(t_visu *v);
int		get_plateau(t_visu *v);
void	get_board(t_visu *v);
int		menu_window(t_visu *v);
int		print_map00(t_visu *v, char *c, int y, int x);
int		print_map01(t_visu *v, char *c, int y, int x);
int		print_map02(t_visu *v, char *c, int y, int x);


#endif