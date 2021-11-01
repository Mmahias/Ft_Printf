/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:19:39 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/10 17:19:50 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_empty(t_flags *flags, char *format, int i)
{
	flags->n_prec = ft_atoi(format + i);
	if (flags->n_prec == 0)
		flags->empty = true;
}
