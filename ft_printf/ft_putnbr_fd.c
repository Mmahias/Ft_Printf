/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:14:33 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/08 18:44:02 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (nb * -1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(((nb % 10) + 48), fd);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd((nb + 48), fd);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + 48), fd);
	}
	if (n <= 9)
		ft_putchar_fd((n + 48), fd);
}
