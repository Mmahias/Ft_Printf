/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:14:09 by mmahias           #+#    #+#             */
/*   Updated: 2021/03/25 21:14:12 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_base(unsigned int nbr, int size, char *str, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base((nbr / 16), (size - 1), str, base);
		str[size] = base[nbr % 16];
	}
	if (nbr < 16)
		str[size--] = base[nbr];
	return (str);
}

char	*ft_conv_hexa_min(unsigned int nbr)
{
	char			*str;
	int				size;
	unsigned int	cp_nbr;
	char			*base_min;

	base_min = "0123456789abcdef";
	cp_nbr = nbr;
	size = 1;
	while ((cp_nbr / 16) != 0)
	{
		size++;
		cp_nbr = (cp_nbr / 16);
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_putnbr_base(nbr, (size - 1), str, base_min);
	str[size++] = '\0';
	return (str);
}

char	*ft_conv_hexa_max(unsigned int nbr)
{
	char			*str;
	int				size;
	unsigned int	cp_nbr;
	char			*base_max;

	base_max = "0123456789ABCDEF";
	cp_nbr = nbr;
	size = 1;
	while ((cp_nbr / 16) != 0)
	{
		size++;
		cp_nbr = (cp_nbr / 16);
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str = ft_putnbr_base(nbr, (size - 1), str, base_max);
	str[size++] = '\0';
	return (str);
}
