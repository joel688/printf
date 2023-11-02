/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joakoeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:09:28 by joakoeni          #+#    #+#             */
/*   Updated: 2022/11/30 15:43:07 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_digitnb(unsigned int n)
{
	long	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	long	n_long;
	long	length;
	char	*res;

	n_long = n;
	length = ft_digitnb(n_long);
	res = (char *)malloc((length + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[length] = '\0';
	length--;
	if (n_long < 0)
		n_long = -n_long;
	while (length >= 0)
	{
		res[length] = (n_long % 10) + '0';
		length--;
		n_long /= 10;
	}
	return (res);
}
