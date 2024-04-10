/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulore <aboulore@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:21 by aboulore          #+#    #+#             */
/*   Updated: 2023/11/30 10:01:10 by aboulore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char a);
int		ft_putstr(char *str);
int		ft_format_hub(va_list arg, char c);
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_xup(unsigned int n);
int		ft_putnbr_x(unsigned int n);
int		ft_putptr(unsigned long int p);
char	*ft_strchr(const char *s, int c);

#endif
