/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:01:52 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/10 16:49:49 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prec_true(t_flags *flags, int len, int boolean)
{
	int i;

	i = 0;
	if (flags->n_prec > len)
	{
		while (i < flags->n_prec - len)
		{
			if (boolean == 1)
				ft_putchar_fd('0', 1);
			i++;
		}
	}
	return (i);
}

int	ft_prec_id(t_flags *flags, int n, int len, int boolean)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n < 0 && flags->prec == true)
	{
		if (boolean == 1 && n != -2147483648)
			ft_putchar_fd('-', 1);
		n = n * -1;
		len--;
	}
	if (flags->prec == true)
		j = ft_prec_true(flags, len, boolean);
	if (boolean == 1)
	{
		if (flags->prec_zero == true && n == 0)
			return (i);
		ft_putnbr_fd(n, 1);
	}
	return (i + j);
}

int	ft_width_id(t_flags *flags, int size, int j, int n)
{
	int i;

	if (flags->prec_zero == true && n == 0)
		size--;
	i = 0;
	if (flags->n_width > (size + j))
	{
		while (i < flags->n_width - (size + j))
		{
			if (flags->zero == true &&
	flags->left == false && flags->prec == false && flags->prec_zero == false)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	return (i);
}

int	ft_conv_ints_bis(t_flags *flags, int n, char *s, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	size += ft_strlen(s);
	if (flags->prec == true && flags->n_prec == 0)
		size = 0;
	if (flags->left == true)
		ft_prec_id(flags, n, size, 1);
	if (flags->prec == true)
		j = ft_prec_id(flags, n, size, 0);
	if (flags->width == true)
		i += ft_width_id(flags, size, j, n);
	if (flags->left == false)
		ft_prec_id(flags, n, size, 1);
	if (n == 0 && flags->empty == true && flags->n_prec == 0 &&
flags->prec == false && flags->prec_zero == true &&
flags->left == true && flags->width == true && flags->n_width == 1)
		return ((size + j) + (i - 1));
	return ((size + j) + i);
}

int	ft_conv_ints(t_flags *flags, va_list args)
{
	long int	n;
	int			i;
	char		*s;
	int			size;

	i = 0;
	n = va_arg(args, int);
	size = 0;
	if (n == -2147483648)
		size = 0;
	else if (n < 0 && flags->zero == true &&
flags->left == false && flags->prec == false && flags->prec_zero == false)
	{
		ft_putchar_fd('-', 1);
		n = n * -1;
		size++;
	}
	s = ft_itoa(n);
	i = ft_conv_ints_bis(flags, n, s, size);
	free(s);
	if (n == -2147483648 && (flags->prec_zero == true ||
(flags->prec == true && flags->n_prec == 0)))
		return (i - 1);
	return (i);
}
