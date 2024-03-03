/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtoolss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:25:25 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/03 18:14:20 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putexa_upper(unsigned long long n)
{
	int		count;
	char	*buff;

	count = 0;
	buff = "0123456789ABCDEF";
	if (n > 15)
	{
		count += ft_putexa_upper(n / 16);
		count += ft_putexa_upper(n % 16);
	}
	else
		count += ft_putchar(buff[n]);
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	unsigned long	nbr;
	int				count;

	nbr = n;
	count = 0;
	if (nbr < 10)
	{
		count += ft_putchar(nbr + 48);
	}
	else
	{
		count += ft_putunbr(nbr / 10);
		count += ft_putunbr(nbr % 10);
	}
	return (count);
}
