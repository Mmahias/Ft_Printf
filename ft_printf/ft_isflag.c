/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:06:21 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/10 17:23:06 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || c == ' ')
		return (1);
	return (0);
}

int		flag_width(t_flags *flags, va_list args, char *format)
{
	int	i;

	i = 0;
	flags->width = true;
	if (format[i] == '*')
	{
		flags->n_width = va_arg(args, int);
		if (flags->n_width < 0)
		{
			flags->n_width = (flags->n_width * (-1));
			flags->left = true;
		}
		i++;
	}
	else if (ft_isdigit(format[i]))
	{
		flags->n_width = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	else
		flags->width = false;
	return (i - 1);
}

void	prec_is_zero(t_flags *flags, char c)
{
	if (flags->n_prec < 0)
	{
		flags->prec = false;
		flags->n_prec = 0;
	}
	if (flags->prec == true && flags->n_prec == 0 &&
(c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'))
	{
		flags->prec_zero = true;
		flags->prec = false;
	}
}

int		flag_prec(t_flags *flags, va_list args, char *format)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	flags->prec = true;
	if ((format[i] == '*' || format[i] == 'd' ||
	format[i] == 'i' || format[i] == 'u' || format[i] == 'x'
	|| format[i] == 'X') && ft_is_conv(format[j]))
	{
		flags->n_prec = va_arg(args, int);
		i++;
	}
	else if ((format[i] == 'd' || format[i] == 'i') &&
ft_is_conv(format[j]) == 0)
		ft_empty(flags, format, i);
	if (ft_isdigit(format[i]))
	{
		flags->n_prec = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	prec_is_zero(flags, format[i]);
	return (i - 1);
}

int		check_flags(t_flags *flags, va_list args, char *format)
{
	int	i;

	i = 0;
	while (ft_isdigit(format[i]) || ft_isflag(format[i]))
	{
		if (format[i] == '-')
			flags->left = true;
		else if (format[i] == '0')
			flags->zero = true;
		else if (format[i] == '*' || ft_isdigit(format[i]))
			i += flag_width(flags, args, (format + i));
		else if (format[i] == '.')
			i += flag_prec(flags, args, (format + i));
		i++;
	}
	return (i);
}
