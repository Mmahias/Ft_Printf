/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:05:09 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/08 17:27:25 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prec_x(t_flags *flags, char *s, int len, int boolean)
{
	int i;

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
			ft_putstr_fd(s, 1);
	}
	else if (boolean == 1)
		ft_putstr_fd(s, 1);
	return (i);
}

int	ft_width_x(t_flags *flags, int len, int j)
{
	int i;

	i = 0;
	if (flags->n_width > len + j)
	{
		while (i < flags->n_width - (len + j))
		{
			if (flags->zero == true && flags->left == false
		&& flags->prec == false && flags->prec_zero == false)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	return (i);
}

int	ft_conv_hexa_bis(t_flags *flags, char *s, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (flags->left == true)
		ft_prec_x(flags, s, len, 1);
	if (flags->prec == true)
		j = ft_prec_x(flags, s, len, 0);
	if (flags->width == true)
		i += ft_width_x(flags, len, j);
	if (flags->left == false)
		ft_prec_x(flags, s, len, 1);
	return (i + j);
}

int	ft_free_s(char *s, int len)
{
	if (!(s == NULL || (ft_strncmp(s, "0", len) == 0) ||
(ft_strncmp(s, "", len) == 0)))
		return (1);
	return (0);
}

int	ft_conv_hexa_xx(t_flags *flags, va_list args, char *format)
{
	char			*s;
	int				len;
	long long int	x;

	x = va_arg(args, unsigned int);
	if (x == 0 && (flags->prec_zero != true))
		s = "0";
	else if ((flags->prec == true && flags->n_prec == 0)
	|| (flags->prec_zero == true && x == 0))
		s = "";
	else
	{
		if (format[0] == 'x')
			s = ft_conv_hexa_min(x);
		else
			s = ft_conv_hexa_max(x);
	}
	if (flags->prec == true && flags->n_prec == 0)
		len = 0;
	else
		len = ft_strlen(s);
	len += ft_conv_hexa_bis(flags, s, len);
	if (ft_free_s(s, len) == 1)
		free(s);
	return (len);
}
