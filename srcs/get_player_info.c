/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:00:50 by mobouzar          #+#    #+#             */
/*   Updated: 2019/10/19 22:39:39 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		who_is_me(t_filler *filler)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strlen(line) >= 10 && line[10] == '1')
	{
		filler->me = ft_strdup("oO");
		filler->enemy = ft_strdup("xX");
		ft_strdel(&line);
		return (1);
	}
	else
	{
		filler->me = ft_strdup("xX");
		filler->enemy = ft_strdup("oO");
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (0);
}

int		map_maker(t_filler *filler, char *line)
{
	int x;
	int i;

	i = 0;
	filler->map_x = ft_atoi(&line[8]);
	filler->map_y = ft_atoi(&line[11]);
	x = filler->map_x;
	if (!(filler->map = (char **)malloc(sizeof(char *) * x)))
		return (0);
	return (1);
}

int		piece_maker(t_filler *filler, char *line)
{
	int x;
	int i;

	i = 0;
	filler->p_x = ft_atoi(&line[5]);
	line = line + 6;
	while (ft_isdigit(*line))
		line++;
	filler->p_y = ft_atoi(line);
	x = filler->p_x;
	if (!(filler->piece = (char **)malloc(sizeof(char *) * x)))
		return (0);
	return (1);
}

int	fill_filler(t_filler *filler)
{
	char	*line;
	int		i;

	i = -1;
	if (get_next_line(0, &line) == 1)
	{
		if (!(map_maker(filler, line)))
			return 0;
		free(line);
		while (i <= filler->map_x && get_next_line(0, &line) && ft_strlen(line) > 4)
		{
			if (ft_strchr(".oOxX", line[4]))
				filler->map[i] = ft_strdup(line + 4);
			i++;
			if (i < filler->map_x)
				free(line);
		}
		if (!(piece_maker(filler, line)))
			return 0;
		free(line);
		i = 0;
		while (i < filler->p_x && get_next_line(0, &line))
		{
			filler->piece[i] = ft_strdup(line);
			i++;
			free(line);
		}
		return 1;
	}
	return  0; 
}
