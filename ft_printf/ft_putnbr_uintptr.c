/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uintptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:14:56 by mmahias           #+#    #+#             */
/*   Updated: 2021/03/25 21:14:57 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_ptr(intptr_t nbr, int size, char *str, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_ptr((nbr / 16), (size - 1), str, base);
		str[size] = base[nbr % 16];
	}
	if (nbr < 16)
		str[size--] = base[nbr];
	return (str);
}

char	*ft_conv_uintptr(intptr_t nbr)
{
	char		*str;
	int			size;
	intptr_t	cp_nbr;
	char		*base;

	base = "0123456789abcdef";
	cp_nbr = nbr;
	size = 1;
	while ((cp_nbr / 16) != 0)
	{
		size++;
		cp_nbr = (cp_nbr / 16);
	}
	size += 2;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str = ft_putnbr_ptr(nbr, (size - 1), str, base);
	str[0] = '0';
	str[1] = 'x';
	str[size++] = '\0';
	return (str);
}
