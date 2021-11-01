/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:04:45 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/08 17:24:51 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prec_uint(t_flags *flags, unsigned int u, int len, int boolean)
{
	int	i;

	i = 0;
	if (flags->prec == true)
	{
		if (flags->n_prec > len)
		{
			while (i < flags->n_prec - len)
			{
				if (boolean == 1)
					ft_putchar_fd('0', 1);
				i++;
			}
		}
		if (flags->n_prec > 0 && boolean == 1)
			ft_putunbr_fd(u, 1);
	}
	else if (boolean == 1)
	{
		if (flags->prec_zero == true && u == 0)
			return (i);
		ft_putunbr_fd(u, 1);
	}
	return (i);
}

int	ft_conv_uint(t_flags *flags, va_list args)
{
	int				i;
	int				j;
	unsigned int	u;
	int				size;
	char			*s;

	i = 0;
	j = 0;
	u = va_arg(args, int);
	s = ft_utoa(u);
	size = ft_strlen(s);
	if (flags->prec == true && flags->n_prec == 0)
		size = 0;
	if (flags->left == true)
		ft_prec_uint(flags, u, size, 1);
	if (flags->prec == true)
		j = ft_prec_uint(flags, u, size, 0);
	if (flags->width == true)
		i += ft_width_id(flags, size, j, u);
	if (flags->left == false)
		ft_prec_uint(flags, u, size, 1);
	if (flags->prec_zero == true && ft_strncmp(s, "2147483648", size) == 0)
		size--;
	free(s);
	return ((size + j) + i);
}
