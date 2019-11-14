/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:29:37 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 23:06:15 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <limits.h>
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_filler
{
	char		**map;
	char		**piece;
	char		*enemy;
	char		*me;
	int			**h_map;
	int			map_x;
	int			map_y;
	int			p_x;
	int			p_y;
	t_point		position;
}				t_filler;

int				fill_filler(t_filler *filler);
int				is_placeable(t_filler *filler, int x, int y);
int				get_position(t_filler *filler);
int				who_is_me(t_filler *filler);
void			create_heatmap(t_filler *filler);
void			trap_enemy(t_filler *filler);
int				exception_case(t_filler *filler);
int				count_score(t_filler *filler, int i, int j);

#endif
