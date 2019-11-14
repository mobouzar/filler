/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:00:50 by mobouzar          #+#    #+#             */
/*   Updated: 2019/11/07 23:03:17 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		who_is_me(t_filler *filler)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "$$$"))
	{
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
	}
	ft_strdel(&line);
	return (0);
}

int		map_maker(t_filler *filler, char *line)
{
	int i;

	i = -1;
	if (filler->map_x == -1 && ft_strstr(line, "Plateau"))
	{
		filler->map_x = ft_atoi(&line[8]);
		filler->map_y = ft_atoi(&line[11]);
		if (filler->map_x <= 0 && filler->map_y <= 0)
			return (0);
		if (!(filler->map = (char **)malloc(sizeof(char *) *
		filler->map_x)))
			return (0);
		while (++i < filler->map_x)
			if (!(filler->map[i] = ft_strnew(filler->map_y)))
				return (0);
		i = -1;
		if (!(filler->h_map = (int **)malloc(sizeof(int *) *
		filler->map_x)))
			return (0);
		while (++i < filler->map_x)
			if (!(filler->h_map[i] = (int *)malloc(sizeof(int)
			* filler->map_y)))
				return (0);
	}
	return (1);
}

int		piece_maker(t_filler *filler, char *line)
{
	int i;

	i = -1;
	if (ft_strstr(line, "Piece"))
	{
		filler->p_x = ft_atoi(&line[5]);
		line = line + 6;
		while (ft_isdigit(*line))
			line++;
		filler->p_y = ft_atoi(line);
		if (filler->p_x <= 0 && filler->p_y <= 0)
			return (0);
		if (!(filler->piece = (char **)malloc(sizeof(char *) * filler->p_x)))
			return (0);
		while (++i < filler->p_x)
			if (!(filler->piece[i] = ft_strnew(filler->p_y)))
				return (0);
	}
	return (1);
}

int		fill_maps(t_filler *filler, char *line)
{
	int i;

	i = 0;
	while (i < filler->map_x && get_next_line(0, &line) && ft_strlen(line) > 4)
	{
		if (ft_strchr(".oOxX", line[4]))
			ft_strcpy(filler->map[i], line + 4);
		else
			break ;
		i++;
		if (i <= filler->map_x)
			ft_strdel(&line);
	}
	get_next_line(0, &line);
	if (!(piece_maker(filler, line)))
		return (0);
	ft_strdel(&line);
	i = 0;
	while (i < filler->p_x && get_next_line(0, &line))
	{
		ft_strcpy(filler->piece[i], line);
		ft_strdel(&line);
		i++;
	}
	return (1);
}

int		fill_filler(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) == 1)
	{
		if (!(map_maker(filler, line)))
			return (0);
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_strdel(&line);
		if (filler->map_x > 0)
		{
			if (fill_maps(filler, line))
				return (1);
			else
				return (0);
		}
	}
	ft_strdel(&line);
	return (0);
}
