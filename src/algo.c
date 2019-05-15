/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:27:14 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/15 11:29:26 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		algo_distance(t_in *info, int pos_x, int pos_y)
{
	int x;
	int y;
	int min;
	int len;

	len = 0;
	min = info->map_x * info->map_y;
	x = -1;
	while (++x < info->map_x && (y = -1))
		while (++y < info->map_y)
			if (info->distance[y][x] == ENEMY ||
				info->map[y][x] == info->enemy ||
				info->map[y][x] == info->enemy + 32)
			{
				len = abs(x - pos_x) + abs(y - pos_y);
				if (len < min)
					min = len;
			}
	return (min);
}

void			algo(t_in *info)
{
	int x;
	int y;

	x= -1;
	while (++x < info->map_x && (y = -1))
	{
		while (++y < info->map_y)
		{
			if (info->map[y][x] == '.')
				info->distance[y][x] = algo_distance(info, x, y);
			else if (info->map[y][x] == info->me
				|| info->map[y][x] == info->me + 32)
				info->distance[y][x] = PLAYER;
			else if (info->map[y][x] == info->enemy
				|| info->map[y][x] == info->enemy + 32)
				info->distance[y][x] = ENEMY;
		}
	}
}


static int		count(t_in *info, int pos_x, int pos_y, int sum)
{
	int i;
	int j;
	int me;
	int enemy;

	me = 0;
	enemy = 0;
	i = -1;
	while (++i < info->piece_x && (j = -1))
		while (++j < info->piece_y)
			if (info->piece[j][i] == '*')
			{
				if ((i + pos_x) < 0 || (i + pos_x) >= info->map_x
					|| (j + pos_y) < 0 || (j + pos_y) >= info->map_y)
					return (0);
				if (info->distance[j + pos_y][i + pos_x] == PLAYER)
					me++;
				if (info->distance[j + pos_y][i + pos_x] == ENEMY)
					enemy++;
				sum += info->distance[j + pos_y][i + pos_x];
			}
	if (enemy || me != 1)
		return (0);
	return (sum);
}

void			place_player(t_in *info)
{
	int x;
	int y;
	int sum;
	int distance;

	distance = info->map_x * info->map_y;
	y = -info->piece_y;
	while (++y < info->map_y + info->piece_y && (x = -info->piece_x))
		while (++x < info->map_x + info->piece_x)
		{
			sum = 0;
			sum = count(info, x, y, sum);
			if (sum != 0 && sum < distance)
			{
				info->play_x = x;
				info->play_y = y;
				distance = sum;
			}
		}
	ft_printf("%d %d\n", info->play_y, info->play_x);
}
