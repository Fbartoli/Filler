/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:47:04 by flbartol          #+#    #+#             */
/*   Updated: 2019/05/14 11:47:20 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t n)
{
	char		*str;
	intmax_t	temp;
	intmax_t	len;
	intmax_t	minus;

	len = ((n <= 0) ? 1 : 0);
	minus = ((n < 0) ? -1 : 1);
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
		str[--len] = '0' + (minus) * (temp % 10);
		temp /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}
