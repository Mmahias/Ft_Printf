/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:34:25 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/06 19:34:27 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	i = 0;
	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	n = (n - 1);
	while (uc_s1[i] && uc_s2[i] && (uc_s1[i] == uc_s2[i]) && (i < n))
		i++;
	return (uc_s1[i] - uc_s2[i]);
}
