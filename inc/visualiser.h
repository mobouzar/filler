/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:21:09 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 22:01:09 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISER_H
# define VISUALISER_H

# include "filler.h"
# include <ncurses.h>
# include <unistd.h>

# define BRIGHT_BLUE 28
# define BRIGHT_WHITE 15

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
}				t_visu;

void			init_colors();
void			ft_free(char **splite);
void			ft_free_visu(t_visu *v);
void			get_board(t_visu *v);
int				menu_window(t_visu *v);
int				get_plateau(t_visu *v);
void			get_player_name(t_visu *v);
void			show_winner(t_visu v, int y, int x);
void			print_map00(t_visu *v, char *c, int y, int x);
void			map00_winner(t_visu *v);
void			menu00(t_visu v);
void			print_map01(t_visu *v, char *c, int y, int x);
void			map01_winner(t_visu *v);
void			menu01(t_visu v);
void			print_map02(t_visu *v, char *c, int y, int x);
void			map02_winner(t_visu *v);
void			menu02(t_visu v);

#endif
