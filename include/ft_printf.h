/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:27:09 by kael-ala          #+#    #+#             */
/*   Updated: 2024/02/27 00:40:06 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putaddress(void *n);
int	ft_putstr(const char *str);
int	ft_putexa(unsigned long long n);
int	ft_putexa_upper(unsigned long long n);
int	ft_putunbr(unsigned int n);
int	ft_atoi(const char *str);

#endif