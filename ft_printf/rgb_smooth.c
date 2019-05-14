/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_smooth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:09:47 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/14 11:47:20 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_rgb_smooth(double t, int k)
{
	return (rgb_to_int((int)(9 * k * (1 - t) * t * t * t * 255),
		(int)(15 * k * (1 - t) * (1 - t) * t * t * 255),
		(int)(8.5 * k * (1 - t) * (1 - t) * (1 - t) * t * 255)));
}
