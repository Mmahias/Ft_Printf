/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:01:10 by mmahias           #+#    #+#             */
/*   Updated: 2021/03/25 21:01:16 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char *nptr)
{
	int i;
	int neg;
	int res;

	i = 0;
	neg = 0;
	res = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r' ||
		nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	while ((nptr[i] == '-' || nptr[i] == '+') &&
		(!((nptr[i + 1] == '-') || (nptr[i + 1] == '+'))))
	{
		if (nptr[i] == '-')
			neg++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = ((res * 10) + (nptr[i] - 48));
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
