/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:11:10 by mmahias           #+#    #+#             */
/*   Updated: 2021/04/10 17:20:24 by mj               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

typedef	struct	s_flags
{
	bool	zero;
	bool	left;
	bool	width;
	int		n_width;
	bool	prec;
	bool	empty;
	bool	prec_zero;
	int		n_prec;
}				t_flags;

int				ft_atoi(char *nptr);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_itoa(long int n);
char			*ft_utoa(int n);
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(long int nb, int fd);
void			ft_putunbr_fd(unsigned int n, int fd);
char			*ft_putnbr_base(unsigned int nbr, int size,
char *str, char *base);
char			*ft_conv_hexa_min(unsigned int nbr);
char			*ft_conv_hexa_max(unsigned int nbr);
char			*ft_putnbr_ptr(intptr_t nbr, int size, char *str, char *base);
char			*ft_conv_uintptr(intptr_t nbr);
int				ft_width_c(t_flags *flags);
int				ft_conv_char(t_flags *flags, va_list args);
int				ft_prec_true(t_flags *flags, int len, int boolean);
int				ft_prec_id(t_flags *flags, int n, int len, int boolean);
int				ft_width_id(t_flags *flags, int size, int j, int n);
int				ft_conv_ints_bis(t_flags *flags, int n, char *s, int size);
int				ft_conv_ints(t_flags *flags, va_list args);
int				ft_left_ptr(char *s);
int				ft_width_ptr(t_flags *flags, int len, char *s);
int				ft_conv_pointer(t_flags *flags, va_list args);
int				ft_prec_str(t_flags *flags, char *s, int boolean);
int				ft_width_str(t_flags *flags, int size);
int				ft_conv_str(t_flags *flags, va_list args);
int				ft_prec_uint(t_flags *flags,
unsigned int u, int len, int boolean);
int				ft_conv_uint(t_flags *flags, va_list args);
int				ft_prec_x(t_flags *flags, char *s, int len, int boolean);
int				ft_width_x(t_flags *flags, int len, int j);
int				ft_conv_hexa_bis(t_flags *flags, char *s, int len);
int				ft_free_s(char *s, int len);
int				ft_conv_hexa_xx(t_flags *flags, va_list args, char *format);
int				ft_width_per(t_flags *flags);
int				ft_conv_percent(t_flags *flags);
int				ft_is_conv(int c);
int				ft_check_conv(t_flags *flags, va_list args, char *format);
int				ft_isflag(int c);
void			ft_empty(t_flags *flags, char *format, int i);
int				flag_width(t_flags *flags, va_list args, char *format);
void			prec_is_zero(t_flags *flags, char c);
int				flag_prec(t_flags *flags, va_list args, char *format);
int				check_flags(t_flags *flags, va_list args, char *format);
void			init_flags(t_flags *flags);
int				ft_printf_format(va_list args, char *format, int res, int len);
int				ft_printf(const char *format, ...);

#endif
