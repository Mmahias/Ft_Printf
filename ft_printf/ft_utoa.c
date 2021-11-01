/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:15:49 by mmahias           #+#    #+#             */
/*   Updated: 2021/03/25 21:15:50 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_convert_utoa(long unsigned int nb, int size, char *str)
{
	if (nb >= 10)
	{
		ft_convert_utoa((nb / 10), (size - 1), str);
		str[size] = (nb % 10) + '0';
	}
	if (nb <= 9)
		str[size--] = (nb + 48);
	return (str);
}

char		*ft_utoa(int n)
{
	char			*str;
	int				size;
	unsigned int	cp_n;

	cp_n = (unsigned int)n;
	size = 1;
	while ((cp_n / 10) != 0)
	{
		size++;
		cp_n = (cp_n / 10);
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_convert_utoa((unsigned int)n, (size - 1), str);
	str[size++] = '\0';
	return (str);
}
