/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:03:45 by mmahias           #+#    #+#             */
/*   Updated: 2021/03/25 21:03:47 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width_per(t_flags *flags)
{
	int i;

	i = 0;
	if (flags->width == true)
	{
		while (i < flags->n_width - 1)
		{
			if (flags->zero == true && flags->left == false)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	return (i);
}

int	ft_conv_percent(t_flags *flags)
{
	int i;

	i = 0;
	if (flags->left == true)
		ft_putchar_fd('%', 1);
	if (flags->width == true)
		i += ft_width_per(flags);
	if (flags->left == false)
		ft_putchar_fd('%', 1);
	return (1 + i);
}
