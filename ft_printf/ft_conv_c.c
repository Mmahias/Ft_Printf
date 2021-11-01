/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:01:36 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/08 21:05:59 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_c(t_flags *flags)
{
	int	i;

	i = 1;
	while (i < flags->n_width)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

int	ft_conv_char(t_flags *flags, va_list args)
{
	int		i;
	char	c;

	i = 0;
	c = va_arg(args, int);
	if (flags->left == true)
		ft_putchar_fd(c, 1);
	if (flags->width == true)
		i += ft_width_c(flags);
	if (flags->left == false)
		ft_putchar_fd(c, 1);
	if (flags->width == true)
		return (i);
	return (i + 1);
}
