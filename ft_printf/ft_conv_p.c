/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:02:20 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/06 18:53:49 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_left_ptr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], 1);
	return (i);
}

int	ft_width_ptr(t_flags *flags, int len, char *s)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (flags->left == true)
		i += ft_left_ptr(s);
	while (++j < (flags->n_width - len))
		ft_putchar_fd(' ', 1);
	while (s[i])
		ft_putchar_fd(s[i++], 1);
	return (i += j);
}

int	ft_conv_pointer(t_flags *flags, va_list args)
{
	int			i;
	intptr_t	p;
	int			len;
	char		*s;

	i = 0;
	p = va_arg(args, intptr_t);
	if (!p || p == 0)
		s = "0x0";
	else
		s = ft_conv_uintptr(p);
	len = ft_strlen(s);
	if (flags->width == true)
		i += ft_width_ptr(flags, len, s);
	else
	{
		while (s[i])
			ft_putchar_fd(s[i++], 1);
	}
	if ((!(!p || p == 0) && (s != NULL)))
		free(s);
	return (i);
}
