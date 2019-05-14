/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:51:13 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/14 11:47:20 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static void	print(t_info *info, t_num *n)
{
	if (info->plus)
		info->width--;
	if (info->width > 0)
	{
		info->width -= 1;
		info->res += info->width;
	}
	n->wid = info->width;
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (info->plus)
	{
		write(1, "+", 1);
		info->res++;
	}
}

int					print_percent(t_info *info, t_num n, int i)
{
	print(info, &n);
	if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	write(1, "%", 1);
	info->res += 1;
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	return (i);
}
