/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:10:20 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/07 17:44:41 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_convert_itoa(long int nb, int size, char *str)
{
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_convert_itoa((nb / 10), (size - 1), str);
		str[size] = (nb % 10) + '0';
	}
	if (nb >= 0 && nb <= 9)
		str[size--] = (nb + 48);
	return (str);
}

char		*ft_itoa(long int n)
{
	char		*str;
	int			size;
	long int	cp_n;

	cp_n = (long int)n;
	size = 1;
	if (cp_n < 0)
	{
		size++;
		cp_n = cp_n * (-1);
	}
	while ((cp_n / 10) != 0)
	{
		size++;
		cp_n = (cp_n / 10);
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_convert_itoa((long int)n, (size - 1), str);
	str[size++] = '\0';
	return (str);
}
