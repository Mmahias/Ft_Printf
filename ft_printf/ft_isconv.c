/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:05:34 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/09 21:10:47 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_conv(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_check_conv(t_flags *flags, va_list args, char *format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_is_conv(format[i]))
	{
		if (format[i] == 'c')
			j += ft_conv_char(flags, args);
		else if (format[i] == 's')
			j += ft_conv_str(flags, args);
		else if (format[i] == 'd' || format[i] == 'i')
			j += ft_conv_ints(flags, args);
		else if (format[i] == 'u')
			j += ft_conv_uint(flags, args);
		else if (format[i] == 'x' || format[i] == 'X')
			j += ft_conv_hexa_xx(flags, args, (format + i));
		else if (format[i] == 'p')
			j += ft_conv_pointer(flags, args);
		else
			return (j);
		i++;
	}
	return (j);
}
