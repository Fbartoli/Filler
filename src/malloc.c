/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:26:02 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/14 11:47:20 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	size_of_map(t_in *info, char *line)
{
	char **size;

	size = ft_strsplit(line, ' ');
	info->map_x = ft_atoi(size[1]);
	info->map_y = ft_atoi(size[2]);
}

void	size_of_token(t_in *info, char *line)
{
	char **size;

	size = ft_strsplit(line, ' ');
	info->piece_x = ft_atoi(size[1]);
	info->piece_y = ft_atoi(size[2]);
}

void	create_2d_array(t_in *info, int x, int y)
{
	int i;

	i = -1;
	info->map = (char **)malloc(sizeof(char *) * x);
	info->distance = (int **)malloc(sizeof(int *) * x);
	while (++i < x)
	{
		info->map[i] = (char *)malloc(sizeof(char) * (y + 1));
		info->distance[i] = (int *)malloc(sizeof(int) * y);
	}
}

void	create_2d_token_array(t_in *info, int x)
{
	int		i;
	char	*line;

	i = -1;
	info->piece = (char **)malloc(sizeof(char *) * x);
	while (++i < x)
	{
		get_next_line(0, &line);
		info->piece[i] = ft_strdup(line);
	}
}