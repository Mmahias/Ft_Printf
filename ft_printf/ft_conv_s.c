/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:04:06 by mmahias           #+#    #+#             */
/*   Updated: 2021/03/25 21:04:08 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prec_str(t_flags *flags, char *s, int boolean)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (flags->prec == true)
	{
		if (flags->n_prec < len)
		{
			while (i < flags->n_prec)
			{
				if (boolean == 1)
					ft_putchar_fd(s[i], 1);
				i++;
			}
			return (i);
		}
	}
	if (boolean == 1)
	{
		while (s[i])
			ft_putchar_fd(s[i++], 1);
	}
	return (len);
}

int	ft_width_str(t_flags *flags, int size)
{
	int i;

	i = 0;
	if (flags->n_width > size)
	{
		while (i < (flags->n_width - size))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	return (i);
}

int	ft_conv_str(t_flags *flags, va_list args)
{
	char	*s;
	int		i;
	int		size;

	i = 0;
	s = va_arg(args, char *);
	if (s == NULL && flags->prec == true && (flags->n_prec < 1))
		s = "";
	else if (s == NULL)
		s = "(null)";
	if (flags->prec == false && flags->n_prec == -1)
		s = "";
	if (flags->left == true)
		ft_prec_str(flags, s, 1);
	size = ft_prec_str(flags, s, 0);
	if (flags->width == true)
		i += ft_width_str(flags, size);
	if (flags->left == false)
		ft_prec_str(flags, s, 1);
	return (size + i);
}
