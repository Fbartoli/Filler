/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:55:52 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/14 16:19:26 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define PLAYER -1
# define ENEMY -2

typedef struct	s_in
{
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;
	int		play_x;
	int		play_y;
	char	me;
	char	enemy;
	char	**map;
	char	**piece;
	int		**distance;
}				t_in;

void			size_of_map(t_in *info, char *line);
void			size_of_token(t_in *info, char *line);
void			create_2d_array(t_in *info, int x, int y);
void			create_2d_token_array(t_in *info, int x);
void			algo(t_in *info);
void			place_player(t_in *info);

#endif