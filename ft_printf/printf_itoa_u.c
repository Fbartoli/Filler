/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:25:39 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/14 11:47:20 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(uintmax_t n)
{
	char		*str;
	uintmax_t	temp;
	uintmax_t	len;

	len = ((n <= 0) ? 1 : 0);
	temp = n;
	while (++len && temp)
		temp /= 10;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	temp = n;
	while (temp)
	{
		str[--len] = '0' + 1 * (temp % 10);
		temp /= 10;
	}
	return (str);
}
