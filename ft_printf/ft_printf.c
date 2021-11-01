/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:10:38 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/10 16:26:16 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->zero = false;
	flags->left = false;
	flags->width = false;
	flags->n_width = 0;
	flags->prec = false;
	flags->empty = false;
	flags->prec_zero = false;
	flags->n_prec = 0;
}

int		ft_printf_format(va_list args, char *format, int res, int len)
{
	t_flags	flags;
	int		i;

	i = 0;
	while (format[i] && i < (len))
	{
		init_flags(&flags);
		if (format[i] == '%')
		{
			i++;
			i += check_flags(&flags, args, format + i);
			if (ft_is_conv(format[i]))
				res += ft_check_conv(&flags, args, format + i);
			else if (format[i] == '%')
				res += ft_conv_percent(&flags);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
		}
		i++;
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;
	int		len;

	res = 0;
	va_start(args, format);
	len = ft_strlen(format);
	res = ft_printf_format(args, (char *)format, res, len);
	va_end(args);
	return (res);
}
