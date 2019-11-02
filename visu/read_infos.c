/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:01:10 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/30 22:58:27 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	ft_free(char **splite)
{
	int	i;

	i = -1;
	while (splite[++i] != NULL)
		ft_strdel(&splite[i]);
	free(splite);
}

void	*ft_name(char *line)
{
	char	**split;
	char	*name;
	int		i;

	i = 0;
	name = NULL;
	split = ft_strsplit(line, '/');
	while (split[i] != NULL)
		i++;
	name = ft_strdup(split[i - 1]);
	// ft_free(split);
	split = ft_strsplit(name, '.');
	// ft_strdel(&name);
	name = ft_strdup(split[0]);
	return (name);
}

void	get_player_name(t_visu *v)
{
	char	*line;
	int		check;
	int		i;

	i = -1;
	check = 0;
	while (get_next_line(0, &line) == 1 && ++i < 8)
	{
		if (ft_strstr(line, "launched"))
		{
			if (check == 0 && (check = 1))
				v->player1.name = ft_name(line);
			else if (check == 1)
				v->player2.name = ft_name(line);
		}
		// ft_strdel(&line);
	}
	// ft_strdel(&line);
	// ft_putendl(v->player1);
	// ft_putendl(v->player2);
}

int		get_plateau(t_visu *v)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (1);
	v->map_y = ft_atoi(&line[8]);
	v->map_x = ft_atoi(&line[11]);
	// ft_strdel(&line);
	if (!(v->map = (char **)malloc(sizeof(char *) * v->map_y)))
		return (0);
	// ft_putnbr(v->map_y);
	// ft_putendl("");
	// ft_putnbr(v->map_x);
	// ft_putendl("");
	return (1);
}

void	get_board(t_visu *v)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if ((line[4] == '.' || ft_toupper(line[4]) == 'X' ||
		ft_toupper(line[4]) == 'O') && ft_isdigit(line[0]))
		{
			v->map[i] = ft_strdup(line + 4);
			i++;
		}
		else if (ft_strstr(line, "Piece"))
		{
			i = 0;
			v->player1.score = 0;
			v->player2.score = 0;
			if (v->map_y == 15)
			{
				print_map00(v, "   ", 2, 3);
			}
			else if (v->map_y == 24)
			{
				print_map01(v, "   ", 2, 3);
			}
			else if (v->map_y == 100)
			{
				print_map02(v, "   ", 2, 3);
			}
			usleep(10000);
			wrefresh(v->bwin);
			// ft_putnbr(v->map_y);
			// ft_putchar('\n');
			// ft_putnbr(v->map_x);
			// ft_putchar('\n');
			// break;
		}
		// ft_strdel(&line);
	}
	// ft_strdel(&line);
}